#include <stdlib.h>

#include "time.h"

#include "rcore.h"

static bool InitGraphicsDevice(int width, int height);  // Initialize graphics device
static void InitKeyboard(void);                         // Initialize raw keyboard system
static void RestoreKeyboard(void);                      // Restore keyboard system
#if defined(SUPPORT_SSH_KEYBOARD_RPI)
static void ProcessKeyboard(void);                      // Process keyboard events
#endif

static void InitEvdevInput(void);                       // Initialize evdev inputs
static void ConfigureEvdevDevice(char *device);         // Identifies a input device and configures it for use if appropriate
static void PollKeyboardEvents(void);                   // Process evdev keyboard events.
static void *EventThread(void *arg);                    // Input device events reading thread

static void InitGamepad(void);                          // Initialize raw gamepad input
static void *GamepadThread(void *arg);                  // Mouse reading thread

static int FindMatchingConnectorMode(const drmModeConnector *connector, const drmModeModeInfo *mode);                               // Search matching DRM mode in connector's mode list
static int FindExactConnectorMode(const drmModeConnector *connector, uint width, uint height, uint fps, bool allowInterlaced);      // Search exactly matching DRM connector mode in connector's list
static int FindNearestConnectorMode(const drmModeConnector *connector, uint width, uint height, uint fps, bool allowInterlaced);    // Search the nearest matching DRM connector mode in connector's list

// Initialize window and OpenGL context
// NOTE: data parameter could be used to pass any kind of required data to the initialization
void InitWindow(int width, int height, const char *title)
{
    TRACELOG(LOG_INFO, "Initializing raylib %s", RAYLIB_VERSION);

    TRACELOG(LOG_INFO, "Supported raylib modules:");
    TRACELOG(LOG_INFO, "    > rcore:..... loaded (mandatory)");
    TRACELOG(LOG_INFO, "    > rlgl:...... loaded (mandatory)");
#if defined(SUPPORT_MODULE_RSHAPES)
    TRACELOG(LOG_INFO, "    > rshapes:... loaded (optional)");
#else
    TRACELOG(LOG_INFO, "    > rshapes:... not loaded (optional)");
#endif
#if defined(SUPPORT_MODULE_RTEXTURES)
    TRACELOG(LOG_INFO, "    > rtextures:. loaded (optional)");
#else
    TRACELOG(LOG_INFO, "    > rtextures:. not loaded (optional)");
#endif
#if defined(SUPPORT_MODULE_RTEXT)
    TRACELOG(LOG_INFO, "    > rtext:..... loaded (optional)");
#else
    TRACELOG(LOG_INFO, "    > rtext:..... not loaded (optional)");
#endif
#if defined(SUPPORT_MODULE_RMODELS)
    TRACELOG(LOG_INFO, "    > rmodels:... loaded (optional)");
#else
    TRACELOG(LOG_INFO, "    > rmodels:... not loaded (optional)");
#endif
#if defined(SUPPORT_MODULE_RAUDIO)
    TRACELOG(LOG_INFO, "    > raudio:.... loaded (optional)");
#else
    TRACELOG(LOG_INFO, "    > raudio:.... not loaded (optional)");
#endif

    if ((title != NULL) && (title[0] != 0))
        CORE.Window.title = title;

    // Initialize global input state
    memset(&CORE.Input, 0, sizeof(CORE.Input));
    CORE.Input.Keyboard.exitKey = KEY_ESCAPE;
    CORE.Input.Mouse.scale = (Vector2){1.0f, 1.0f};
    CORE.Input.Mouse.cursor = MOUSE_CURSOR_ARROW;
    CORE.Input.Gamepad.lastButtonPressed = 0; // GAMEPAD_BUTTON_UNKNOWN
#if defined(SUPPORT_EVENTS_WAITING)
    CORE.Window.eventWaiting = true;
#endif

    // Initialize graphics device (display device and OpenGL context)
    // NOTE: returns true if window and graphic device has been initialized successfully
    CORE.Window.ready = InitGraphicsDevice(width, height);

    // If graphic device is no properly initialized, we end program
    if (!CORE.Window.ready)
    {
        TRACELOG(LOG_FATAL, "Failed to initialize Graphic Device");
        return;
    }
    else
        SetWindowPosition(GetMonitorWidth(GetCurrentMonitor()) / 2 - CORE.Window.screen.width / 2, GetMonitorHeight(GetCurrentMonitor()) / 2 - CORE.Window.screen.height / 2);

    // Initialize hi-res timer
    InitTimer();

    // Initialize random seed
    srand((unsigned int)time(NULL));

    // Initialize base path for storage
    CORE.Storage.basePath = GetWorkingDirectory();

#if defined(SUPPORT_MODULE_RTEXT) && defined(SUPPORT_DEFAULT_FONT)
    // Load default font
    // WARNING: External function: Module required: rtext
    LoadFontDefault();
#if defined(SUPPORT_MODULE_RSHAPES)
    // Set font white rectangle for shapes drawing, so shapes and text can be batched together
    // WARNING: rshapes module is required, if not available, default internal white rectangle is used
    Rectangle rec = GetFontDefault().recs[95];
    if (CORE.Window.flags & FLAG_MSAA_4X_HINT)
    {
        // NOTE: We try to maxime rec padding to avoid pixel bleeding on MSAA filtering
        SetShapesTexture(GetFontDefault().texture, (Rectangle){rec.x + 2, rec.y + 2, 1, 1});
    }
    else
    {
        // NOTE: We set up a 1px padding on char rectangle to avoid pixel bleeding
        SetShapesTexture(GetFontDefault().texture, (Rectangle){rec.x + 1, rec.y + 1, rec.width - 2, rec.height - 2});
    }
#endif
#else
#if defined(SUPPORT_MODULE_RSHAPES)
    // Set default texture and rectangle to be used for shapes drawing
    // NOTE: rlgl default texture is a 1x1 pixel UNCOMPRESSED_R8G8B8A8
    Texture2D texture = {rlGetTextureIdDefault(), 1, 1, 1, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};
    SetShapesTexture(texture, (Rectangle){0.0f, 0.0f, 1.0f, 1.0f}); // WARNING: Module required: rshapes
#endif
#endif
#if defined(SUPPORT_MODULE_RTEXT) && defined(SUPPORT_DEFAULT_FONT)
    if ((CORE.Window.flags & FLAG_WINDOW_HIGHDPI) > 0)
    {
        // Set default font texture filter for HighDPI (blurry)
        // RL_TEXTURE_FILTER_LINEAR - tex filter: BILINEAR, no mipmaps
        rlTextureParameters(GetFontDefault().texture.id, RL_TEXTURE_MIN_FILTER, RL_TEXTURE_FILTER_LINEAR);
        rlTextureParameters(GetFontDefault().texture.id, RL_TEXTURE_MAG_FILTER, RL_TEXTURE_FILTER_LINEAR);
    }
#endif

    // Initialize raw input system
    InitEvdevInput(); // Evdev inputs initialization
    InitGamepad();    // Gamepad init
    InitKeyboard();   // Keyboard init (stdin)

#if defined(SUPPORT_EVENTS_AUTOMATION)
    events = (AutomationEvent *)RL_CALLOC(MAX_CODE_AUTOMATION_EVENTS, sizeof(AutomationEvent));
    CORE.Time.frameCounter = 0;
#endif
}


// Initialize display device and framebuffer
// NOTE: width and height represent the screen (framebuffer) desired size, not actual display size
// If width or height are 0, default display size will be used for framebuffer size
// NOTE: returns false in case graphic device could not be created
static bool InitGraphicsDevice(int width, int height)
{
    CORE.Window.screen.width = width;            // User desired width
    CORE.Window.screen.height = height;          // User desired height
    CORE.Window.screenScale = MatrixIdentity();  // No draw scaling required by default

    // Set the window minimum and maximum default values to 0
    CORE.Window.windowMin.width  = 0;
    CORE.Window.windowMin.height = 0;
    CORE.Window.windowMax.width  = 0;
    CORE.Window.windowMax.height = 0;

    // NOTE: Framebuffer (render area - CORE.Window.render.width, CORE.Window.render.height) could include black bars...
    // ...in top-down or left-right to match display aspect ratio (no weird scaling)

    CORE.Window.fullscreen = true;
    CORE.Window.flags |= FLAG_FULLSCREEN_MODE;


    CORE.Window.fd = -1;
    CORE.Window.connector = NULL;
    CORE.Window.modeIndex = -1;
    CORE.Window.crtc = NULL;
    CORE.Window.gbmDevice = NULL;
    CORE.Window.gbmSurface = NULL;
    CORE.Window.prevBO = NULL;
    CORE.Window.prevFB = 0;

#if defined(DEFAULT_GRAPHIC_DEVICE_DRM)
    CORE.Window.fd = open(DEFAULT_GRAPHIC_DEVICE_DRM, O_RDWR);
#else
    TRACELOG(LOG_INFO, "DISPLAY: No graphic card set, trying platform-gpu-card");
    CORE.Window.fd = open("/dev/dri/by-path/platform-gpu-card",  O_RDWR); // VideoCore VI (Raspberry Pi 4)

    if ((-1 == CORE.Window.fd) || (drmModeGetResources(CORE.Window.fd) == NULL))
    {
        TRACELOG(LOG_INFO, "DISPLAY: Failed to open platform-gpu-card, trying card1");
        CORE.Window.fd = open("/dev/dri/card1", O_RDWR); // Other Embedded
    }

    if ((-1 == CORE.Window.fd) || (drmModeGetResources(CORE.Window.fd) == NULL))
    {
        TRACELOG(LOG_INFO, "DISPLAY: Failed to open graphic card1, trying card0");
        CORE.Window.fd = open("/dev/dri/card0", O_RDWR); // VideoCore IV (Raspberry Pi 1-3)
    }
#endif
    if (-1 == CORE.Window.fd)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to open graphic card");
        return false;
    }

    drmModeRes *res = drmModeGetResources(CORE.Window.fd);
    if (!res)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed get DRM resources");
        return false;
    }

    TRACELOG(LOG_TRACE, "DISPLAY: Connectors found: %i", res->count_connectors);
    for (size_t i = 0; i < res->count_connectors; i++)
    {
        TRACELOG(LOG_TRACE, "DISPLAY: Connector index %i", i);
        drmModeConnector *con = drmModeGetConnector(CORE.Window.fd, res->connectors[i]);
        TRACELOG(LOG_TRACE, "DISPLAY: Connector modes detected: %i", con->count_modes);
        if ((con->connection == DRM_MODE_CONNECTED) && (con->encoder_id))
        {
            TRACELOG(LOG_TRACE, "DISPLAY: DRM mode connected");
            CORE.Window.connector = con;
            break;
        }
        else
        {
            TRACELOG(LOG_TRACE, "DISPLAY: DRM mode NOT connected (deleting)");
            drmModeFreeConnector(con);
        }
    }

    if (!CORE.Window.connector)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: No suitable DRM connector found");
        drmModeFreeResources(res);
        return false;
    }

    drmModeEncoder *enc = drmModeGetEncoder(CORE.Window.fd, CORE.Window.connector->encoder_id);
    if (!enc)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to get DRM mode encoder");
        drmModeFreeResources(res);
        return false;
    }

    CORE.Window.crtc = drmModeGetCrtc(CORE.Window.fd, enc->crtc_id);
    if (!CORE.Window.crtc)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to get DRM mode crtc");
        drmModeFreeEncoder(enc);
        drmModeFreeResources(res);
        return false;
    }

    // If InitWindow should use the current mode find it in the connector's mode list
    if ((CORE.Window.screen.width <= 0) || (CORE.Window.screen.height <= 0))
    {
        TRACELOG(LOG_TRACE, "DISPLAY: Selecting DRM connector mode for current used mode...");

        CORE.Window.modeIndex = FindMatchingConnectorMode(CORE.Window.connector, &CORE.Window.crtc->mode);

        if (CORE.Window.modeIndex < 0)
        {
            TRACELOG(LOG_WARNING, "DISPLAY: No matching DRM connector mode found");
            drmModeFreeEncoder(enc);
            drmModeFreeResources(res);
            return false;
        }

        CORE.Window.screen.width = CORE.Window.display.width;
        CORE.Window.screen.height = CORE.Window.display.height;
    }

    const bool allowInterlaced = CORE.Window.flags & FLAG_INTERLACED_HINT;
    const int fps = (CORE.Time.target > 0) ? (1.0/CORE.Time.target) : 60;

    // Try to find an exact matching mode
    CORE.Window.modeIndex = FindExactConnectorMode(CORE.Window.connector, CORE.Window.screen.width, CORE.Window.screen.height, fps, allowInterlaced);

    // If nothing found, try to find a nearly matching mode
    if (CORE.Window.modeIndex < 0) CORE.Window.modeIndex = FindNearestConnectorMode(CORE.Window.connector, CORE.Window.screen.width, CORE.Window.screen.height, fps, allowInterlaced);

    // If nothing found, try to find an exactly matching mode including interlaced
    if (CORE.Window.modeIndex < 0) CORE.Window.modeIndex = FindExactConnectorMode(CORE.Window.connector, CORE.Window.screen.width, CORE.Window.screen.height, fps, true);

    // If nothing found, try to find a nearly matching mode including interlaced
    if (CORE.Window.modeIndex < 0) CORE.Window.modeIndex = FindNearestConnectorMode(CORE.Window.connector, CORE.Window.screen.width, CORE.Window.screen.height, fps, true);

    // If nothing found, there is no suitable mode
    if (CORE.Window.modeIndex < 0)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to find a suitable DRM connector mode");
        drmModeFreeEncoder(enc);
        drmModeFreeResources(res);
        return false;
    }

    CORE.Window.display.width = CORE.Window.connector->modes[CORE.Window.modeIndex].hdisplay;
    CORE.Window.display.height = CORE.Window.connector->modes[CORE.Window.modeIndex].vdisplay;

    TRACELOG(LOG_INFO, "DISPLAY: Selected DRM connector mode %s (%ux%u%c@%u)", CORE.Window.connector->modes[CORE.Window.modeIndex].name,
        CORE.Window.connector->modes[CORE.Window.modeIndex].hdisplay, CORE.Window.connector->modes[CORE.Window.modeIndex].vdisplay,
        (CORE.Window.connector->modes[CORE.Window.modeIndex].flags & DRM_MODE_FLAG_INTERLACE) ? 'i' : 'p',
        CORE.Window.connector->modes[CORE.Window.modeIndex].vrefresh);

    // Use the width and height of the surface for render
    CORE.Window.render.width = CORE.Window.screen.width;
    CORE.Window.render.height = CORE.Window.screen.height;

    drmModeFreeEncoder(enc);
    enc = NULL;

    drmModeFreeResources(res);
    res = NULL;

    CORE.Window.gbmDevice = gbm_create_device(CORE.Window.fd);
    if (!CORE.Window.gbmDevice)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to create GBM device");
        return false;
    }

    CORE.Window.gbmSurface = gbm_surface_create(CORE.Window.gbmDevice, CORE.Window.connector->modes[CORE.Window.modeIndex].hdisplay,
        CORE.Window.connector->modes[CORE.Window.modeIndex].vdisplay, GBM_FORMAT_ARGB8888, GBM_BO_USE_SCANOUT | GBM_BO_USE_RENDERING);
    if (!CORE.Window.gbmSurface)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to create GBM surface");
        return false;
    }

    EGLint samples = 0;
    EGLint sampleBuffer = 0;
    if (CORE.Window.flags & FLAG_MSAA_4X_HINT)
    {
        samples = 4;
        sampleBuffer = 1;
        TRACELOG(LOG_INFO, "DISPLAY: Trying to enable MSAA x4");
    }

    const EGLint framebufferAttribs[] =
    {
        EGL_RENDERABLE_TYPE, (rlGetVersion() == RL_OPENGL_ES_30)? EGL_OPENGL_ES3_BIT : EGL_OPENGL_ES2_BIT,      // Type of context support
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,          // Don't use it on Android!
        EGL_RED_SIZE, 8,            // RED color bit depth (alternative: 5)
        EGL_GREEN_SIZE, 8,          // GREEN color bit depth (alternative: 6)
        EGL_BLUE_SIZE, 8,           // BLUE color bit depth (alternative: 5)
        EGL_ALPHA_SIZE, 8,        // ALPHA bit depth (required for transparent framebuffer)
        //EGL_TRANSPARENT_TYPE, EGL_NONE, // Request transparent framebuffer (EGL_TRANSPARENT_RGB does not work on RPI)
        EGL_DEPTH_SIZE, 16,         // Depth buffer size (Required to use Depth testing!)
        //EGL_STENCIL_SIZE, 8,      // Stencil buffer size
        EGL_SAMPLE_BUFFERS, sampleBuffer,    // Activate MSAA
        EGL_SAMPLES, samples,       // 4x Antialiasing if activated (Free on MALI GPUs)
        EGL_NONE
    };

    const EGLint contextAttribs[] =
    {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };

    EGLint numConfigs = 0;

    // Get an EGL device connection
    CORE.Window.device = eglGetDisplay((EGLNativeDisplayType)CORE.Window.gbmDevice);
    if (CORE.Window.device == EGL_NO_DISPLAY)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to initialize EGL device");
        return false;
    }

    // Initialize the EGL device connection
    if (eglInitialize(CORE.Window.device, NULL, NULL) == EGL_FALSE)
    {
        // If all of the calls to eglInitialize returned EGL_FALSE then an error has occurred.
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to initialize EGL device");
        return false;
    }

    if (!eglChooseConfig(CORE.Window.device, NULL, NULL, 0, &numConfigs))
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to get EGL config count: 0x%x", eglGetError());
        return false;
    }

    TRACELOG(LOG_TRACE, "DISPLAY: EGL configs available: %d", numConfigs);

    EGLConfig *configs = RL_CALLOC(numConfigs, sizeof(*configs));
    if (!configs)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to get memory for EGL configs");
        return false;
    }

    EGLint matchingNumConfigs = 0;
    if (!eglChooseConfig(CORE.Window.device, framebufferAttribs, configs, numConfigs, &matchingNumConfigs))
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to choose EGL config: 0x%x", eglGetError());
        free(configs);
        return false;
    }

    TRACELOG(LOG_TRACE, "DISPLAY: EGL matching configs available: %d", matchingNumConfigs);

    // find the EGL config that matches the previously setup GBM format
    int found = 0;
    for (EGLint i = 0; i < matchingNumConfigs; ++i)
    {
        EGLint id = 0;
        if (!eglGetConfigAttrib(CORE.Window.device, configs[i], EGL_NATIVE_VISUAL_ID, &id))
        {
            TRACELOG(LOG_WARNING, "DISPLAY: Failed to get EGL config attribute: 0x%x", eglGetError());
            continue;
        }

        if (GBM_FORMAT_ARGB8888 == id)
        {
            TRACELOG(LOG_TRACE, "DISPLAY: Using EGL config: %d", i);
            CORE.Window.config = configs[i];
            found = 1;
            break;
        }
    }

    RL_FREE(configs);

    if (!found)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to find a suitable EGL config");
        return false;
    }

    // Set rendering API
    eglBindAPI(EGL_OPENGL_ES_API);

    // Create an EGL rendering context
    CORE.Window.context = eglCreateContext(CORE.Window.device, CORE.Window.config, EGL_NO_CONTEXT, contextAttribs);
    if (CORE.Window.context == EGL_NO_CONTEXT)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to create EGL context");
        return false;
    }


    // Create an EGL window surface
    //---------------------------------------------------------------------------------
    CORE.Window.surface = eglCreateWindowSurface(CORE.Window.device, CORE.Window.config, (EGLNativeWindowType)CORE.Window.gbmSurface, NULL);
    if (EGL_NO_SURFACE == CORE.Window.surface)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to create EGL window surface: 0x%04x", eglGetError());
        return false;
    }

    // At this point we need to manage render size vs screen size
    // NOTE: This function use and modify global module variables:
    //  -> CORE.Window.screen.width/CORE.Window.screen.height
    //  -> CORE.Window.render.width/CORE.Window.render.height
    //  -> CORE.Window.screenScale
    SetupFramebuffer(CORE.Window.display.width, CORE.Window.display.height);

    // There must be at least one frame displayed before the buffers are swapped
    //eglSwapInterval(CORE.Window.device, 1);

    if (eglMakeCurrent(CORE.Window.device, CORE.Window.surface, CORE.Window.surface, CORE.Window.context) == EGL_FALSE)
    {
        TRACELOG(LOG_WARNING, "DISPLAY: Failed to attach EGL rendering context to EGL surface");
        return false;
    }
    else
    {
        CORE.Window.render.width = CORE.Window.screen.width;
        CORE.Window.render.height = CORE.Window.screen.height;
        CORE.Window.currentFbo.width = CORE.Window.render.width;
        CORE.Window.currentFbo.height = CORE.Window.render.height;

        TRACELOG(LOG_INFO, "DISPLAY: Device initialized successfully");
        TRACELOG(LOG_INFO, "    > Display size: %i x %i", CORE.Window.display.width, CORE.Window.display.height);
        TRACELOG(LOG_INFO, "    > Screen size:  %i x %i", CORE.Window.screen.width, CORE.Window.screen.height);
        TRACELOG(LOG_INFO, "    > Render size:  %i x %i", CORE.Window.render.width, CORE.Window.render.height);
        TRACELOG(LOG_INFO, "    > Viewport offsets: %i, %i", CORE.Window.renderOffset.x, CORE.Window.renderOffset.y);
    }

    // Load OpenGL extensions
    // NOTE: GL procedures address loader is required to load extensions
    rlLoadExtensions(eglGetProcAddress);

    // Initialize OpenGL context (states and resources)
    // NOTE: CORE.Window.currentFbo.width and CORE.Window.currentFbo.height not used, just stored as globals in rlgl
    rlglInit(CORE.Window.currentFbo.width, CORE.Window.currentFbo.height);

    // Setup default viewport
    // NOTE: It updated CORE.Window.render.width and CORE.Window.render.height
    SetupViewport(CORE.Window.currentFbo.width, CORE.Window.currentFbo.height);

    if ((CORE.Window.flags & FLAG_WINDOW_MINIMIZED) > 0) MinimizeWindow();

    return true;
}


// Close window and unload OpenGL context
void CloseWindow(void)
{
#if defined(SUPPORT_GIF_RECORDING)
    if (gifRecording)
    {
        MsfGifResult result = msf_gif_end(&gifState);
        msf_gif_free(result);
        gifRecording = false;
    }
#endif

#if defined(SUPPORT_MODULE_RTEXT) && defined(SUPPORT_DEFAULT_FONT)
    UnloadFontDefault();        // WARNING: Module required: rtext
#endif

    rlglClose();                // De-init rlgl

#if defined(_WIN32) && defined(SUPPORT_WINMM_HIGHRES_TIMER) && !defined(SUPPORT_BUSY_WAIT_LOOP)
    timeEndPeriod(1);           // Restore time period
#endif


    if (CORE.Window.prevFB)
    {
        drmModeRmFB(CORE.Window.fd, CORE.Window.prevFB);
        CORE.Window.prevFB = 0;
    }

    if (CORE.Window.prevBO)
    {
        gbm_surface_release_buffer(CORE.Window.gbmSurface, CORE.Window.prevBO);
        CORE.Window.prevBO = NULL;
    }

    if (CORE.Window.gbmSurface)
    {
        gbm_surface_destroy(CORE.Window.gbmSurface);
        CORE.Window.gbmSurface = NULL;
    }

    if (CORE.Window.gbmDevice)
    {
        gbm_device_destroy(CORE.Window.gbmDevice);
        CORE.Window.gbmDevice = NULL;
    }

    if (CORE.Window.crtc)
    {
        if (CORE.Window.connector)
        {
            drmModeSetCrtc(CORE.Window.fd, CORE.Window.crtc->crtc_id, CORE.Window.crtc->buffer_id,
                CORE.Window.crtc->x, CORE.Window.crtc->y, &CORE.Window.connector->connector_id, 1, &CORE.Window.crtc->mode);
            drmModeFreeConnector(CORE.Window.connector);
            CORE.Window.connector = NULL;
        }

        drmModeFreeCrtc(CORE.Window.crtc);
        CORE.Window.crtc = NULL;
    }

    if (CORE.Window.fd != -1)
    {
        close(CORE.Window.fd);
        CORE.Window.fd = -1;
    }

    // Close surface, context and display
    if (CORE.Window.device != EGL_NO_DISPLAY)
    {
        if (CORE.Window.surface != EGL_NO_SURFACE)
        {
            eglDestroySurface(CORE.Window.device, CORE.Window.surface);
            CORE.Window.surface = EGL_NO_SURFACE;
        }

        if (CORE.Window.context != EGL_NO_CONTEXT)
        {
            eglDestroyContext(CORE.Window.device, CORE.Window.context);
            CORE.Window.context = EGL_NO_CONTEXT;
        }

        eglTerminate(CORE.Window.device);
        CORE.Window.device = EGL_NO_DISPLAY;
    }

    // Wait for mouse and gamepad threads to finish before closing
    // NOTE: Those threads should already have finished at this point
    // because they are controlled by CORE.Window.shouldClose variable

    CORE.Window.shouldClose = true;   // Added to force threads to exit when the close window is called

    // Close the evdev keyboard
    if (CORE.Input.Keyboard.fd != -1)
    {
        close(CORE.Input.Keyboard.fd);
        CORE.Input.Keyboard.fd = -1;
    }

    for (int i = 0; i < sizeof(CORE.Input.eventWorker)/sizeof(InputEventWorker); ++i)
    {
        if (CORE.Input.eventWorker[i].threadId)
        {
            pthread_join(CORE.Input.eventWorker[i].threadId, NULL);
        }
    }

    if (CORE.Input.Gamepad.threadId) pthread_join(CORE.Input.Gamepad.threadId, NULL);

#if defined(SUPPORT_EVENTS_AUTOMATION)
    RL_FREE(events);
#endif

    CORE.Window.ready = false;
    TRACELOG(LOG_INFO, "Window closed successfully");
}



// Check if KEY_ESCAPE pressed or Close icon pressed
bool WindowShouldClose(void)
{
    if (CORE.Window.ready) return CORE.Window.shouldClose;
    else return true;
}

// Check if window is currently hidden
bool IsWindowHidden(void)
{
    return false;
}

// Check if window has been minimized
bool IsWindowMinimized(void)
{
    return false;
}


// Check if window has been maximized (only PLATFORM_DESKTOP)
bool IsWindowMaximized(void)
{
    return false;
}

// Check if window has the focus
bool IsWindowFocused(void)
{
    return true;
}

// Check if window has been resizedLastFrame
bool IsWindowResized(void)
{
    return false;
}


// Toggle fullscreen mode (only PLATFORM_DESKTOP)
void ToggleFullscreen(void)
{
    TRACELOG(LOG_WARNING, "SYSTEM: Failed to toggle to windowed mode");
}


// Set window state: maximized, if resizable (only PLATFORM_DESKTOP)
void MaximizeWindow(void)
{
    TRACELOG(LOG_INFO, "MaximizeWindow not implemented in rcore_drm.c");
}

// Set window state: minimized (only PLATFORM_DESKTOP)
void MinimizeWindow(void)
{
    TRACELOG(LOG_INFO, "MinimizeWindow not implemented in rcore_drm.c");
}

// Set window state: not minimized/maximized (only PLATFORM_DESKTOP)
void RestoreWindow(void)
{
    TRACELOG(LOG_INFO, "RestoreWindow not implemented in rcore_drm.c");
}


// Toggle borderless windowed mode (only PLATFORM_DESKTOP)
void ToggleBorderlessWindowed(void)
{
    TRACELOG(LOG_INFO, "ToggleBorderlessWindowed not implemented in rcore_drm.c");
}

// Set window configuration state using flags
void SetWindowState(unsigned int flags)
{
    TRACELOG(LOG_INFO, "SetWindowState not implemented in rcore_drm.c");
}

// Clear window configuration state flags
void ClearWindowState(unsigned int flags)
{
    TRACELOG(LOG_INFO, "ClearWindowState not implemented in rcore_drm.c");
}

// Set icon for window (only PLATFORM_DESKTOP)
// NOTE 1: Image must be in RGBA format, 8bit per channel
// NOTE 2: Image is scaled by the OS for all required sizes
void SetWindowIcon(Image image)
{
    TRACELOG(LOG_INFO, "SetWindowIcon not implemented in rcore_drm.c");
}

// Set icon for window (multiple images, only PLATFORM_DESKTOP)
// NOTE 1: Images must be in RGBA format, 8bit per channel
// NOTE 2: The multiple images are used depending on provided sizes
// Standard Windows icon sizes: 256, 128, 96, 64, 48, 32, 24, 16
void SetWindowIcons(Image *images, int count)
{
    TRACELOG(LOG_INFO, "SetWindowIcons not implemented in rcore_drm.c");
}

// Set title for window (only PLATFORM_DESKTOP and PLATFORM_WEB)
void SetWindowTitle(const char *title)
{
    CORE.Window.title = title;
}

// Set window position on screen (windowed mode)
void SetWindowPosition(int x, int y)
{
    TRACELOG(LOG_INFO, "SetWindowPosition not implemented in rcore_drm.c");
}

// Set monitor for the current window
void SetWindowMonitor(int monitor)
{
    TRACELOG(LOG_INFO, "SetWindowMonitor not implemented in rcore_drm.c");
}

// Set window minimum dimensions (FLAG_WINDOW_RESIZABLE)
void SetWindowMinSize(int width, int height)
{
    CORE.Window.windowMin.width = width;
    CORE.Window.windowMin.height = height;
}

// Set window maximum dimensions (FLAG_WINDOW_RESIZABLE)
void SetWindowMaxSize(int width, int height)
{
    CORE.Window.windowMax.width = width;
    CORE.Window.windowMax.height = height;
}

// Set window dimensions
void SetWindowSize(int width, int height)
{
    TRACELOG(LOG_INFO, "SetWindowSize not implemented in rcore_drm.c");
}

// Set window opacity, value opacity is between 0.0 and 1.0
void SetWindowOpacity(float opacity)
{
    TRACELOG(LOG_INFO, "SetWindowOpacity not implemented in rcore_drm.c");
}

// Set window focused
void SetWindowFocused(void)
{
    TRACELOG(LOG_INFO, "SetWindowFocused not implemented in rcore_drm.c");
}

// Get native window handle
void *GetWindowHandle(void)
{
    return NULL;
}

// Get number of monitors
int GetMonitorCount(void)
{
    return 1;
}

// Get number of monitors
int GetCurrentMonitor(void)
{
    return 0;
}

// Get selected monitor position
Vector2 GetMonitorPosition(int monitor)
{
    return (Vector2){ 0, 0 };
}

// Get selected monitor width (currently used by monitor)
int GetMonitorWidth(int monitor)
{
    return 0;
}

// Get selected monitor height (currently used by monitor)
int GetMonitorHeight(int monitor)
{
    return 0;
}

// Get selected monitor physical height in millimetres
int GetMonitorPhysicalHeight(int monitor)
{
    return 0;
}

// Get selected monitor refresh rate
int GetMonitorRefreshRate(int monitor)
{
    if ((CORE.Window.connector) && (CORE.Window.modeIndex >= 0))
    {
        return CORE.Window.connector->modes[CORE.Window.modeIndex].vrefresh;
    }
    return 0;
}

// Get window position XY on monitor
Vector2 GetWindowPosition(void)
{
    return (Vector2){ 0, 0 };
}

// Get window scale DPI factor for current monitor
Vector2 GetWindowScaleDPI(void)
{
    return (Vector2){ 1.0f, 1.0f };
}

// Get the human-readable, UTF-8 encoded name of the selected monitor
const char *GetMonitorName(int monitor)
{
    return "";
}


// Set clipboard text content
void SetClipboardText(const char *text)
{
}


// Get clipboard text content
// NOTE: returned string is allocated and freed by GLFW
const char *GetClipboardText(void)
{
    return NULL;
}

// Show mouse cursor
void ShowCursor(void)
{
    CORE.Input.Mouse.cursorHidden = false;
}

// Hides mouse cursor
void HideCursor(void)
{
    CORE.Input.Mouse.cursorHidden = true;
}


// Enables cursor (unlock cursor)
void EnableCursor(void)
{
    // Set cursor position in the middle
    SetMousePosition(CORE.Window.screen.width/2, CORE.Window.screen.height/2);

    CORE.Input.Mouse.cursorHidden = false;
}

// Disables cursor (lock cursor)
void DisableCursor(void)
{
    // Set cursor position in the middle
    SetMousePosition(CORE.Window.screen.width/2, CORE.Window.screen.height/2);

    CORE.Input.Mouse.cursorHidden = true;
}

// Get elapsed time measure in seconds since InitTimer()
// NOTE: On PLATFORM_DESKTOP InitTimer() is called on InitWindow()
// NOTE: On PLATFORM_DESKTOP, timer is initialized on glfwInit()
double GetTime(void)
{
    double time = 0.0;
    struct timespec ts = { 0 };
    clock_gettime(CLOCK_MONOTONIC, &ts);
    unsigned long long int nanoSeconds = (unsigned long long int)ts.tv_sec*1000000000LLU + (unsigned long long int)ts.tv_nsec;

    time = (double)(nanoSeconds - CORE.Time.base)*1e-9;  // Elapsed time since InitTimer()
    return time;
}

// NOTE TRACELOG() function is located in [utils.h]

// Takes a screenshot of current screen (saved a .png)
void TakeScreenshot(const char *fileName)
{
#if defined(SUPPORT_MODULE_RTEXTURES)
    // Security check to (partially) avoid malicious code on PLATFORM_WEB
    if (strchr(fileName, '\'') != NULL) { TRACELOG(LOG_WARNING, "SYSTEM: Provided fileName could be potentially malicious, avoid [\'] character");  return; }

    Vector2 scale = GetWindowScaleDPI();
    unsigned char *imgData = rlReadScreenPixels((int)((float)CORE.Window.render.width*scale.x), (int)((float)CORE.Window.render.height*scale.y));
    Image image = { imgData, (int)((float)CORE.Window.render.width*scale.x), (int)((float)CORE.Window.render.height*scale.y), 1, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 };

    char path[2048] = { 0 };
    strcpy(path, TextFormat("%s/%s", CORE.Storage.basePath, fileName));

    ExportImage(image, path);           // WARNING: Module required: rtextures
    RL_FREE(imgData);

    TRACELOG(LOG_INFO, "SYSTEM: [%s] Screenshot taken successfully", path);
#else
    TRACELOG(LOG_WARNING,"IMAGE: ExportImage() requires module: rtextures");
#endif
}

// Open URL with default system browser (if available)
// NOTE: This function is only safe to use if you control the URL given.
// A user could craft a malicious string performing another action.
// Only call this function yourself not with user input or make sure to check the string yourself.
// Ref: https://github.com/raysan5/raylib/issues/686
void OpenURL(const char *url)
{
    // Security check to (partially) avoid malicious code on PLATFORM_WEB
    if (strchr(url, '\'') != NULL) TRACELOG(LOG_WARNING, "SYSTEM: Provided URL could be potentially malicious, avoid [\'] character");
    TRACELOG(LOG_INFO, "OpenURL not implemented in rcore_drm.c");
}

// Get gamepad internal name id
const char *GetGamepadName(int gamepad)
{
    const char *name = NULL;

    if (CORE.Input.Gamepad.ready[gamepad])
    {
        ioctl(CORE.Input.Gamepad.streamId[gamepad], JSIOCGNAME(64), &CORE.Input.Gamepad.name[gamepad]);
        name = CORE.Input.Gamepad.name[gamepad];
    }

    return name;
}

// Get selected monitor physical width in millimetres
int GetMonitorPhysicalWidth(int monitor)
{
    return 0;
}

// Get gamepad axis count
int GetGamepadAxisCount(int gamepad)
{
    int axisCount = 0;
    if (CORE.Input.Gamepad.ready[gamepad]) ioctl(CORE.Input.Gamepad.streamId[gamepad], JSIOCGAXES, &axisCount);
    CORE.Input.Gamepad.axisCount = axisCount;
    return CORE.Input.Gamepad.axisCount;
}

// Set internal gamepad mappings
int SetGamepadMappings(const char *mappings)
{
    return 0;
}

// Get mouse position X
int GetMouseX(void)
{
    return (int)((CORE.Input.Mouse.currentPosition.x + CORE.Input.Mouse.offset.x)*CORE.Input.Mouse.scale.x);
}

// Get mouse position Y
int GetMouseY(void)
{
    return (int)((CORE.Input.Mouse.currentPosition.y + CORE.Input.Mouse.offset.y)*CORE.Input.Mouse.scale.y);
}

// Get mouse position XY
Vector2 GetMousePosition(void)
{
    Vector2 position = { 0 };

    position.x = (CORE.Input.Mouse.currentPosition.x + CORE.Input.Mouse.offset.x)*CORE.Input.Mouse.scale.x;
    position.y = (CORE.Input.Mouse.currentPosition.y + CORE.Input.Mouse.offset.y)*CORE.Input.Mouse.scale.y;

    return position;
}

// Set mouse position XY
void SetMousePosition(int x, int y)
{
    CORE.Input.Mouse.currentPosition = (Vector2){ (float)x, (float)y };
    CORE.Input.Mouse.previousPosition = CORE.Input.Mouse.currentPosition;

}


// Get mouse wheel movement Y
float GetMouseWheelMove(void)
{
    float result = 0.0f;

    if (fabsf(CORE.Input.Mouse.currentWheelMove.x) > fabsf(CORE.Input.Mouse.currentWheelMove.y)) result = (float)CORE.Input.Mouse.currentWheelMove.x;
    else result = (float)CORE.Input.Mouse.currentWheelMove.y;

    return result;
}


// Swap back buffer with front buffer (screen drawing)
void SwapScreenBuffer(void)
{
    eglSwapBuffers(CORE.Window.device, CORE.Window.surface);

    if (!CORE.Window.gbmSurface || (-1 == CORE.Window.fd) || !CORE.Window.connector || !CORE.Window.crtc) TRACELOG(LOG_ERROR, "DISPLAY: DRM initialization failed to swap");

    struct gbm_bo *bo = gbm_surface_lock_front_buffer(CORE.Window.gbmSurface);
    if (!bo) TRACELOG(LOG_ERROR, "DISPLAY: Failed GBM to lock front buffer");

    uint32_t fb = 0;
    int result = drmModeAddFB(CORE.Window.fd, CORE.Window.connector->modes[CORE.Window.modeIndex].hdisplay, CORE.Window.connector->modes[CORE.Window.modeIndex].vdisplay, 24, 32, gbm_bo_get_stride(bo), gbm_bo_get_handle(bo).u32, &fb);
    if (result != 0) TRACELOG(LOG_ERROR, "DISPLAY: drmModeAddFB() failed with result: %d", result);

    result = drmModeSetCrtc(CORE.Window.fd, CORE.Window.crtc->crtc_id, fb, 0, 0, &CORE.Window.connector->connector_id, 1, &CORE.Window.connector->modes[CORE.Window.modeIndex]);
    if (result != 0) TRACELOG(LOG_ERROR, "DISPLAY: drmModeSetCrtc() failed with result: %d", result);

    if (CORE.Window.prevFB)
    {
        result = drmModeRmFB(CORE.Window.fd, CORE.Window.prevFB);
        if (result != 0) TRACELOG(LOG_ERROR, "DISPLAY: drmModeRmFB() failed with result: %d", result);
    }

    CORE.Window.prevFB = fb;

    if (CORE.Window.prevBO) gbm_surface_release_buffer(CORE.Window.gbmSurface, CORE.Window.prevBO);

    CORE.Window.prevBO = bo;
}


// Register all input events
void PollInputEvents(void)
{
#if defined(SUPPORT_GESTURES_SYSTEM)
    // NOTE: Gestures update must be called every frame to reset gestures correctly
    // because ProcessGestureEvent() is just called on an event, not every frame
    UpdateGestures();
#endif

    // Reset keys/chars pressed registered
    CORE.Input.Keyboard.keyPressedQueueCount = 0;
    CORE.Input.Keyboard.charPressedQueueCount = 0;
    // Reset key repeats
    for (int i = 0; i < MAX_KEYBOARD_KEYS; i++) CORE.Input.Keyboard.keyRepeatInFrame[i] = 0;

    // Reset last gamepad button/axis registered state
    CORE.Input.Gamepad.lastButtonPressed = 0;       // GAMEPAD_BUTTON_UNKNOWN
    CORE.Input.Gamepad.axisCount = 0;

    // Register previous keys states
    for (int i = 0; i < MAX_KEYBOARD_KEYS; i++)
    {
        CORE.Input.Keyboard.previousKeyState[i] = CORE.Input.Keyboard.currentKeyState[i];
        CORE.Input.Keyboard.keyRepeatInFrame[i] = 0;
    }

    PollKeyboardEvents();

    // Register previous mouse states
    CORE.Input.Mouse.previousWheelMove = CORE.Input.Mouse.currentWheelMove;
    CORE.Input.Mouse.currentWheelMove = CORE.Input.Mouse.eventWheelMove;
    CORE.Input.Mouse.eventWheelMove = (Vector2){ 0.0f, 0.0f };
    for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
    {
        CORE.Input.Mouse.previousButtonState[i] = CORE.Input.Mouse.currentButtonState[i];
        CORE.Input.Mouse.currentButtonState[i] = CORE.Input.Mouse.currentButtonStateEvdev[i];
    }

    // Register gamepads buttons events
    for (int i = 0; i < MAX_GAMEPADS; i++)
    {
        if (CORE.Input.Gamepad.ready[i])
        {
            // Register previous gamepad states
            for (int k = 0; k < MAX_GAMEPAD_BUTTONS; k++) CORE.Input.Gamepad.previousButtonState[i][k] = CORE.Input.Gamepad.currentButtonState[i][k];
        }
    }

    // Register previous touch states
    for (int i = 0; i < MAX_TOUCH_POINTS; i++) CORE.Input.Touch.previousTouchState[i] = CORE.Input.Touch.currentTouchState[i];

    // Reset touch positions
    // TODO: It resets on PLATFORM_WEB the mouse position and not filled again until a move-event,
    // so, if mouse is not moved it returns a (0, 0) position... this behaviour should be reviewed!
    //for (int i = 0; i < MAX_TOUCH_POINTS; i++) CORE.Input.Touch.position[i] = (Vector2){ 0, 0 };

#if defined(SUPPORT_SSH_KEYBOARD_RPI)
    // NOTE: Keyboard reading could be done using input_event(s) or just read from stdin, both methods are used here.
    // stdin reading is still used for legacy purposes, it allows keyboard input trough SSH console

    if (!CORE.Input.Keyboard.evtMode) ProcessKeyboard();

    // NOTE: Mouse input events polling is done asynchronously in another pthread - EventThread()
    // NOTE: Gamepad (Joystick) input events polling is done asynchonously in another pthread - GamepadThread()
#endif
}


// Initialize Keyboard system (using standard input)
static void InitKeyboard(void)
{
    // NOTE: We read directly from Standard Input (stdin) - STDIN_FILENO file descriptor,
    // Reading directly from stdin will give chars already key-mapped by kernel to ASCII or UNICODE

    // Save terminal keyboard settings
    tcgetattr(STDIN_FILENO, &CORE.Input.Keyboard.defaultSettings);

    // Reconfigure terminal with new settings
    struct termios keyboardNewSettings = { 0 };
    keyboardNewSettings = CORE.Input.Keyboard.defaultSettings;

    // New terminal settings for keyboard: turn off buffering (non-canonical mode), echo and key processing
    // NOTE: ISIG controls if ^C and ^Z generate break signals or not
    keyboardNewSettings.c_lflag &= ~(ICANON | ECHO | ISIG);
    //keyboardNewSettings.c_iflag &= ~(ISTRIP | INLCR | ICRNL | IGNCR | IXON | IXOFF);
    keyboardNewSettings.c_cc[VMIN] = 1;
    keyboardNewSettings.c_cc[VTIME] = 0;

    // Set new keyboard settings (change occurs immediately)
    tcsetattr(STDIN_FILENO, TCSANOW, &keyboardNewSettings);

    // Save old keyboard mode to restore it at the end
    CORE.Input.Keyboard.defaultFileFlags = fcntl(STDIN_FILENO, F_GETFL, 0);          // F_GETFL: Get the file access mode and the file status flags
    fcntl(STDIN_FILENO, F_SETFL, CORE.Input.Keyboard.defaultFileFlags | O_NONBLOCK); // F_SETFL: Set the file status flags to the value specified

    // NOTE: If ioctl() returns -1, it means the call failed for some reason (error code set in errno)
    int result = ioctl(STDIN_FILENO, KDGKBMODE, &CORE.Input.Keyboard.defaultMode);

    // In case of failure, it could mean a remote keyboard is used (SSH)
    if (result < 0) TRACELOG(LOG_WARNING, "RPI: Failed to change keyboard mode, an SSH keyboard is probably used");
    else
    {
        // Reconfigure keyboard mode to get:
        //    - scancodes (K_RAW)
        //    - keycodes (K_MEDIUMRAW)
        //    - ASCII chars (K_XLATE)
        //    - UNICODE chars (K_UNICODE)
        ioctl(STDIN_FILENO, KDSKBMODE, K_XLATE);  // ASCII chars
    }

    // Register keyboard restore when program finishes
    atexit(RestoreKeyboard);
}

// Restore default keyboard input
static void RestoreKeyboard(void)
{
    // Reset to default keyboard settings
    tcsetattr(STDIN_FILENO, TCSANOW, &CORE.Input.Keyboard.defaultSettings);

    // Reconfigure keyboard to default mode
    fcntl(STDIN_FILENO, F_SETFL, CORE.Input.Keyboard.defaultFileFlags);
    ioctl(STDIN_FILENO, KDSKBMODE, CORE.Input.Keyboard.defaultMode);
}

#if defined(SUPPORT_SSH_KEYBOARD_RPI)
// Process keyboard inputs
static void ProcessKeyboard(void)
{
    #define MAX_KEYBUFFER_SIZE      32      // Max size in bytes to read

    // Keyboard input polling (fill keys[256] array with status)
    int bufferByteCount = 0;                        // Bytes available on the buffer
    char keysBuffer[MAX_KEYBUFFER_SIZE] = { 0 };    // Max keys to be read at a time

    // Read availables keycodes from stdin
    bufferByteCount = read(STDIN_FILENO, keysBuffer, MAX_KEYBUFFER_SIZE);     // POSIX system call

    // Reset pressed keys array (it will be filled below)
    for (int i = 0; i < MAX_KEYBOARD_KEYS; i++)
    {
        CORE.Input.Keyboard.currentKeyState[i] = 0;
        CORE.Input.Keyboard.keyRepeatInFrame[i] = 0;
    }

    // Fill all read bytes (looking for keys)
    for (int i = 0; i < bufferByteCount; i++)
    {
        // NOTE: If (key == 0x1b), depending on next key, it could be a special keymap code!
        // Up -> 1b 5b 41 / Left -> 1b 5b 44 / Right -> 1b 5b 43 / Down -> 1b 5b 42
        if (keysBuffer[i] == 0x1b)
        {
            // Check if ESCAPE key has been pressed to stop program
            if (bufferByteCount == 1) CORE.Input.Keyboard.currentKeyState[CORE.Input.Keyboard.exitKey] = 1;
            else
            {
                if (keysBuffer[i + 1] == 0x5b)    // Special function key
                {
                    if ((keysBuffer[i + 2] == 0x5b) || (keysBuffer[i + 2] == 0x31) || (keysBuffer[i + 2] == 0x32))
                    {
                        // Process special function keys (F1 - F12)
                        switch (keysBuffer[i + 3])
                        {
                            case 0x41: CORE.Input.Keyboard.currentKeyState[290] = 1; break;    // raylib KEY_F1
                            case 0x42: CORE.Input.Keyboard.currentKeyState[291] = 1; break;    // raylib KEY_F2
                            case 0x43: CORE.Input.Keyboard.currentKeyState[292] = 1; break;    // raylib KEY_F3
                            case 0x44: CORE.Input.Keyboard.currentKeyState[293] = 1; break;    // raylib KEY_F4
                            case 0x45: CORE.Input.Keyboard.currentKeyState[294] = 1; break;    // raylib KEY_F5
                            case 0x37: CORE.Input.Keyboard.currentKeyState[295] = 1; break;    // raylib KEY_F6
                            case 0x38: CORE.Input.Keyboard.currentKeyState[296] = 1; break;    // raylib KEY_F7
                            case 0x39: CORE.Input.Keyboard.currentKeyState[297] = 1; break;    // raylib KEY_F8
                            case 0x30: CORE.Input.Keyboard.currentKeyState[298] = 1; break;    // raylib KEY_F9
                            case 0x31: CORE.Input.Keyboard.currentKeyState[299] = 1; break;    // raylib KEY_F10
                            case 0x33: CORE.Input.Keyboard.currentKeyState[300] = 1; break;    // raylib KEY_F11
                            case 0x34: CORE.Input.Keyboard.currentKeyState[301] = 1; break;    // raylib KEY_F12
                            default: break;
                        }

                        if (keysBuffer[i + 2] == 0x5b) i += 4;
                        else if ((keysBuffer[i + 2] == 0x31) || (keysBuffer[i + 2] == 0x32)) i += 5;
                    }
                    else
                    {
                        switch (keysBuffer[i + 2])
                        {
                            case 0x41: CORE.Input.Keyboard.currentKeyState[265] = 1; break;    // raylib KEY_UP
                            case 0x42: CORE.Input.Keyboard.currentKeyState[264] = 1; break;    // raylib KEY_DOWN
                            case 0x43: CORE.Input.Keyboard.currentKeyState[262] = 1; break;    // raylib KEY_RIGHT
                            case 0x44: CORE.Input.Keyboard.currentKeyState[263] = 1; break;    // raylib KEY_LEFT
                            default: break;
                        }

                        i += 3;  // Jump to next key
                    }

                    // NOTE: Some keys are not directly keymapped (CTRL, ALT, SHIFT)
                }
            }
        }
        else if (keysBuffer[i] == 0x0a)     // raylib KEY_ENTER (don't mix with <linux/input.h> KEY_*)
        {
            CORE.Input.Keyboard.currentKeyState[257] = 1;

            CORE.Input.Keyboard.keyPressedQueue[CORE.Input.Keyboard.keyPressedQueueCount] = 257;     // Add keys pressed into queue
            CORE.Input.Keyboard.keyPressedQueueCount++;
        }
        else if (keysBuffer[i] == 0x7f)     // raylib KEY_BACKSPACE
        {
            CORE.Input.Keyboard.currentKeyState[259] = 1;

            CORE.Input.Keyboard.keyPressedQueue[CORE.Input.Keyboard.keyPressedQueueCount] = 257;     // Add keys pressed into queue
            CORE.Input.Keyboard.keyPressedQueueCount++;
        }
        else
        {
            // Translate lowercase a-z letters to A-Z
            if ((keysBuffer[i] >= 97) && (keysBuffer[i] <= 122))
            {
                CORE.Input.Keyboard.currentKeyState[(int)keysBuffer[i] - 32] = 1;
            }
            else CORE.Input.Keyboard.currentKeyState[(int)keysBuffer[i]] = 1;

            CORE.Input.Keyboard.keyPressedQueue[CORE.Input.Keyboard.keyPressedQueueCount] = keysBuffer[i];     // Add keys pressed into queue
            CORE.Input.Keyboard.keyPressedQueueCount++;
        }
    }

    // Check exit key (same functionality as GLFW3 KeyCallback())
    if (CORE.Input.Keyboard.currentKeyState[CORE.Input.Keyboard.exitKey] == 1) CORE.Window.shouldClose = true;

#if defined(SUPPORT_SCREEN_CAPTURE)
    // Check screen capture key (raylib key: KEY_F12)
    if (CORE.Input.Keyboard.currentKeyState[301] == 1)
    {
        TakeScreenshot(TextFormat("screenshot%03i.png", screenshotCounter));
        screenshotCounter++;
    }
#endif
}
#endif  // SUPPORT_SSH_KEYBOARD_RPI

// Initialise user input from evdev(/dev/input/event<N>) this means mouse, keyboard or gamepad devices
static void InitEvdevInput(void)
{
    char path[MAX_FILEPATH_LENGTH] = { 0 };
    DIR *directory = NULL;
    struct dirent *entity = NULL;

    // Initialise keyboard file descriptor
    CORE.Input.Keyboard.fd = -1;

    // Reset variables
    for (int i = 0; i < MAX_TOUCH_POINTS; ++i)
    {
        CORE.Input.Touch.position[i].x = -1;
        CORE.Input.Touch.position[i].y = -1;
    }

    // Reset keyboard key state
    for (int i = 0; i < MAX_KEYBOARD_KEYS; i++)
    {
        CORE.Input.Keyboard.currentKeyState[i] = 0;
        CORE.Input.Keyboard.keyRepeatInFrame[i] = 0;
    }

    // Open the linux directory of "/dev/input"
    directory = opendir(DEFAULT_EVDEV_PATH);

    if (directory)
    {
        while ((entity = readdir(directory)) != NULL)
        {
            if ((strncmp("event", entity->d_name, strlen("event")) == 0) ||     // Search for devices named "event*"
                (strncmp("mouse", entity->d_name, strlen("mouse")) == 0))       // Search for devices named "mouse*"
            {
                sprintf(path, "%s%s", DEFAULT_EVDEV_PATH, entity->d_name);
                ConfigureEvdevDevice(path);                                     // Configure the device if appropriate
            }
        }

        closedir(directory);
    }
    else TRACELOG(LOG_WARNING, "RPI: Failed to open linux event directory: %s", DEFAULT_EVDEV_PATH);
}

// Identifies a input device and configures it for use if appropriate
static void ConfigureEvdevDevice(char *device)
{
    #define BITS_PER_LONG   (8*sizeof(long))
    #define NBITS(x)        ((((x) - 1)/BITS_PER_LONG) + 1)
    #define OFF(x)          ((x)%BITS_PER_LONG)
    #define BIT(x)          (1UL<<OFF(x))
    #define LONG(x)         ((x)/BITS_PER_LONG)
    #define TEST_BIT(array, bit) ((array[LONG(bit)] >> OFF(bit)) & 1)

    struct input_absinfo absinfo = { 0 };
    unsigned long evBits[NBITS(EV_MAX)] = { 0 };
    unsigned long absBits[NBITS(ABS_MAX)] = { 0 };
    unsigned long relBits[NBITS(REL_MAX)] = { 0 };
    unsigned long keyBits[NBITS(KEY_MAX)] = { 0 };
    bool hasAbs = false;
    bool hasRel = false;
    bool hasAbsMulti = false;
    int freeWorkerId = -1;
    int fd = -1;

    InputEventWorker *worker = NULL;

    // Open the device and allocate worker
    //-------------------------------------------------------------------------------------------------------
    // Find a free spot in the workers array
    for (int i = 0; i < sizeof(CORE.Input.eventWorker)/sizeof(InputEventWorker); ++i)
    {
        if (CORE.Input.eventWorker[i].threadId == 0)
        {
            freeWorkerId = i;
            break;
        }
    }

    // Select the free worker from array
    if (freeWorkerId >= 0)
    {
        worker = &(CORE.Input.eventWorker[freeWorkerId]);       // Grab a pointer to the worker
        memset(worker, 0, sizeof(InputEventWorker));  // Clear the worker
    }
    else
    {
        TRACELOG(LOG_WARNING, "RPI: Failed to create input device thread for %s, out of worker slots", device);
        return;
    }

    // Open the device
    fd = open(device, O_RDONLY | O_NONBLOCK);
    if (fd < 0)
    {
        TRACELOG(LOG_WARNING, "RPI: Failed to open input device: %s", device);
        return;
    }
    worker->fd = fd;

    // Grab number on the end of the devices name "event<N>"
    int devNum = 0;
    char *ptrDevName = strrchr(device, 't');
    worker->eventNum = -1;

    if (ptrDevName != NULL)
    {
        if (sscanf(ptrDevName, "t%d", &devNum) == 1) worker->eventNum = devNum;
    }
    else worker->eventNum = 0;      // TODO: HACK: Grab number for mouse0 device!

    // At this point we have a connection to the device, but we don't yet know what the device is.
    // It could be many things, even as simple as a power button...
    //-------------------------------------------------------------------------------------------------------

    // Identify the device
    //-------------------------------------------------------------------------------------------------------
    ioctl(fd, EVIOCGBIT(0, sizeof(evBits)), evBits);    // Read a bitfield of the available device properties

    // Check for absolute input devices
    if (TEST_BIT(evBits, EV_ABS))
    {
        ioctl(fd, EVIOCGBIT(EV_ABS, sizeof(absBits)), absBits);

        // Check for absolute movement support (usually touchscreens, but also joysticks)
        if (TEST_BIT(absBits, ABS_X) && TEST_BIT(absBits, ABS_Y))
        {
            hasAbs = true;

            // Get the scaling values
            ioctl(fd, EVIOCGABS(ABS_X), &absinfo);
            worker->absRange.x = absinfo.minimum;
            worker->absRange.width = absinfo.maximum - absinfo.minimum;
            ioctl(fd, EVIOCGABS(ABS_Y), &absinfo);
            worker->absRange.y = absinfo.minimum;
            worker->absRange.height = absinfo.maximum - absinfo.minimum;
        }

        // Check for multiple absolute movement support (usually multitouch touchscreens)
        if (TEST_BIT(absBits, ABS_MT_POSITION_X) && TEST_BIT(absBits, ABS_MT_POSITION_Y))
        {
            hasAbsMulti = true;

            // Get the scaling values
            ioctl(fd, EVIOCGABS(ABS_X), &absinfo);
            worker->absRange.x = absinfo.minimum;
            worker->absRange.width = absinfo.maximum - absinfo.minimum;
            ioctl(fd, EVIOCGABS(ABS_Y), &absinfo);
            worker->absRange.y = absinfo.minimum;
            worker->absRange.height = absinfo.maximum - absinfo.minimum;
        }
    }

    // Check for relative movement support (usually mouse)
    if (TEST_BIT(evBits, EV_REL))
    {
        ioctl(fd, EVIOCGBIT(EV_REL, sizeof(relBits)), relBits);

        if (TEST_BIT(relBits, REL_X) && TEST_BIT(relBits, REL_Y)) hasRel = true;
    }

    // Check for button support to determine the device type(usually on all input devices)
    if (TEST_BIT(evBits, EV_KEY))
    {
        ioctl(fd, EVIOCGBIT(EV_KEY, sizeof(keyBits)), keyBits);

        if (hasAbs || hasAbsMulti)
        {
            if (TEST_BIT(keyBits, BTN_TOUCH)) worker->isTouch = true;          // This is a touchscreen
            if (TEST_BIT(keyBits, BTN_TOOL_FINGER)) worker->isTouch = true;    // This is a drawing tablet
            if (TEST_BIT(keyBits, BTN_TOOL_PEN)) worker->isTouch = true;       // This is a drawing tablet
            if (TEST_BIT(keyBits, BTN_STYLUS)) worker->isTouch = true;         // This is a drawing tablet
            if (worker->isTouch || hasAbsMulti) worker->isMultitouch = true;   // This is a multitouch capable device
        }

        if (hasRel)
        {
            if (TEST_BIT(keyBits, BTN_LEFT)) worker->isMouse = true;           // This is a mouse
            if (TEST_BIT(keyBits, BTN_RIGHT)) worker->isMouse = true;          // This is a mouse
        }

        if (TEST_BIT(keyBits, BTN_A)) worker->isGamepad = true;                // This is a gamepad
        if (TEST_BIT(keyBits, BTN_TRIGGER)) worker->isGamepad = true;          // This is a gamepad
        if (TEST_BIT(keyBits, BTN_START)) worker->isGamepad = true;            // This is a gamepad
        if (TEST_BIT(keyBits, BTN_TL)) worker->isGamepad = true;               // This is a gamepad
        if (TEST_BIT(keyBits, BTN_TL)) worker->isGamepad = true;               // This is a gamepad

        if (TEST_BIT(keyBits, KEY_SPACE)) worker->isKeyboard = true;           // This is a keyboard
    }
    //-------------------------------------------------------------------------------------------------------

    // Decide what to do with the device
    //-------------------------------------------------------------------------------------------------------
    if (worker->isKeyboard && (CORE.Input.Keyboard.fd == -1))
    {
        // Use the first keyboard encountered. This assumes that a device that says it's a keyboard is just a
        // keyboard. The keyboard is polled synchronously, whereas other input devices are polled in separate
        // threads so that they don't drop events when the frame rate is slow.
        TRACELOG(LOG_INFO, "RPI: Opening keyboard device: %s", device);
        CORE.Input.Keyboard.fd = worker->fd;
    }
    else if (worker->isTouch || worker->isMouse)
    {
        // Looks like an interesting device
        TRACELOG(LOG_INFO, "RPI: Opening input device: %s (%s%s%s%s)", device,
            worker->isMouse? "mouse " : "",
            worker->isMultitouch? "multitouch " : "",
            worker->isTouch? "touchscreen " : "",
            worker->isGamepad? "gamepad " : "");

        // Create a thread for this device
        int error = pthread_create(&worker->threadId, NULL, &EventThread, (void *)worker);
        if (error != 0)
        {
            TRACELOG(LOG_WARNING, "RPI: Failed to create input device thread: %s (error: %d)", device, error);
            worker->threadId = 0;
            close(fd);
        }

#if defined(USE_LAST_TOUCH_DEVICE)
        // Find touchscreen with the highest index
        int maxTouchNumber = -1;

        for (int i = 0; i < sizeof(CORE.Input.eventWorker)/sizeof(InputEventWorker); ++i)
        {
            if (CORE.Input.eventWorker[i].isTouch && (CORE.Input.eventWorker[i].eventNum > maxTouchNumber)) maxTouchNumber = CORE.Input.eventWorker[i].eventNum;
        }

        // Find touchscreens with lower indexes
        for (int i = 0; i < sizeof(CORE.Input.eventWorker)/sizeof(InputEventWorker); ++i)
        {
            if (CORE.Input.eventWorker[i].isTouch && (CORE.Input.eventWorker[i].eventNum < maxTouchNumber))
            {
                if (CORE.Input.eventWorker[i].threadId != 0)
                {
                    TRACELOG(LOG_WARNING, "RPI: Found duplicate touchscreen, killing touchscreen on event: %d", i);
                    pthread_cancel(CORE.Input.eventWorker[i].threadId);
                    close(CORE.Input.eventWorker[i].fd);
                }
            }
        }
#endif
    }
    else close(fd);  // We are not interested in this device
    //-------------------------------------------------------------------------------------------------------
}

static void PollKeyboardEvents(void)
{
    // Scancode to keycode mapping for US keyboards
    // TODO: Replace this with a keymap from the X11 to get the correct regional map for the keyboard:
    // Currently non US keyboards will have the wrong mapping for some keys
    static const int keymapUS[] = {
        0, 256, 49, 50, 51, 52, 53, 54, 55, 56, 57, 48, 45, 61, 259, 258, 81, 87, 69, 82, 84,
        89, 85, 73, 79, 80, 91, 93, 257, 341, 65, 83, 68, 70, 71, 72, 74, 75, 76, 59, 39, 96,
        340, 92, 90, 88, 67, 86, 66, 78, 77, 44, 46, 47, 344, 332, 342, 32, 280, 290, 291,
        292, 293, 294, 295, 296, 297, 298, 299, 282, 281, 327, 328, 329, 333, 324, 325,
        326, 334, 321, 322, 323, 320, 330, 0, 85, 86, 300, 301, 89, 90, 91, 92, 93, 94, 95,
        335, 345, 331, 283, 346, 101, 268, 265, 266, 263, 262, 269, 264, 267, 260, 261,
        112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 347, 127,
        128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143,
        144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
        160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175,
        176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
        192, 193, 194, 0, 0, 0, 0, 0, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210,
        211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226,
        227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242,
        243, 244, 245, 246, 247, 248, 0, 0, 0, 0, 0, 0, 0
    };

    int fd = CORE.Input.Keyboard.fd;
    if (fd == -1) return;

    struct input_event event = { 0 };
    int keycode = -1;

    // Try to read data from the keyboard and only continue if successful
    while (read(fd, &event, sizeof(event)) == (int)sizeof(event))
    {
        // Button parsing
        if (event.type == EV_KEY)
        {
#if defined(SUPPORT_SSH_KEYBOARD_RPI)
            // Change keyboard mode to events
            CORE.Input.Keyboard.evtMode = true;
#endif
            // Keyboard button parsing
            if ((event.code >= 1) && (event.code <= 255))     //Keyboard keys appear for codes 1 to 255
            {
                keycode = keymapUS[event.code & 0xFF];     // The code we get is a scancode so we look up the appropriate keycode

                // Make sure we got a valid keycode
                if ((keycode > 0) && (keycode < sizeof(CORE.Input.Keyboard.currentKeyState)))
                {
                    // WARNING: https://www.kernel.org/doc/Documentation/input/input.txt
                    // Event interface: 'value' is the value the event carries. Either a relative change for EV_REL,
                    // absolute new value for EV_ABS (joysticks ...), or 0 for EV_KEY for release, 1 for keypress and 2 for autorepeat
                    CORE.Input.Keyboard.currentKeyState[keycode] = (event.value >= 1)? 1 : 0;
                    if (event.value >= 1)
                    {
                        CORE.Input.Keyboard.keyPressedQueue[CORE.Input.Keyboard.keyPressedQueueCount] = keycode;     // Register last key pressed
                        CORE.Input.Keyboard.keyPressedQueueCount++;
                    }

                #if defined(SUPPORT_SCREEN_CAPTURE)
                    // Check screen capture key (raylib key: KEY_F12)
                    if (CORE.Input.Keyboard.currentKeyState[301] == 1)
                    {
                        TakeScreenshot(TextFormat("screenshot%03i.png", screenshotCounter));
                        screenshotCounter++;
                    }
                #endif

                    if (CORE.Input.Keyboard.currentKeyState[CORE.Input.Keyboard.exitKey] == 1) CORE.Window.shouldClose = true;

                    TRACELOGD("RPI: KEY_%s ScanCode: %4i KeyCode: %4i", event.value == 0 ? "UP":"DOWN", event.code, keycode);
                }
            }
        }
    }
}

// Input device events reading thread
static void *EventThread(void *arg)
{
    struct input_event event = { 0 };
    InputEventWorker *worker = (InputEventWorker *)arg;

    int touchAction = -1;           // 0-TOUCH_ACTION_UP, 1-TOUCH_ACTION_DOWN, 2-TOUCH_ACTION_MOVE
    bool gestureUpdate = false;     // Flag to note gestures require to update

    while (!CORE.Window.shouldClose)
    {
        // Try to read data from the device and only continue if successful
        while (read(worker->fd, &event, sizeof(event)) == (int)sizeof(event))
        {
            // Relative movement parsing
            if (event.type == EV_REL)
            {
                if (event.code == REL_X)
                {
                    CORE.Input.Mouse.currentPosition.x += event.value;
                    CORE.Input.Touch.position[0].x = CORE.Input.Mouse.currentPosition.x;

                    touchAction = 2;    // TOUCH_ACTION_MOVE
                    gestureUpdate = true;
                }

                if (event.code == REL_Y)
                {
                    CORE.Input.Mouse.currentPosition.y += event.value;
                    CORE.Input.Touch.position[0].y = CORE.Input.Mouse.currentPosition.y;

                    touchAction = 2;    // TOUCH_ACTION_MOVE
                    gestureUpdate = true;
                }

                if (event.code == REL_WHEEL) CORE.Input.Mouse.eventWheelMove.y += event.value;
            }

            // Absolute movement parsing
            if (event.type == EV_ABS)
            {
                // Basic movement
                if (event.code == ABS_X)
                {
                    CORE.Input.Mouse.currentPosition.x = (event.value - worker->absRange.x)*CORE.Window.screen.width/worker->absRange.width;    // Scale according to absRange
                    CORE.Input.Touch.position[0].x = (event.value - worker->absRange.x)*CORE.Window.screen.width/worker->absRange.width;        // Scale according to absRange

                    touchAction = 2;    // TOUCH_ACTION_MOVE
                    gestureUpdate = true;
                }

                if (event.code == ABS_Y)
                {
                    CORE.Input.Mouse.currentPosition.y = (event.value - worker->absRange.y)*CORE.Window.screen.height/worker->absRange.height;  // Scale according to absRange
                    CORE.Input.Touch.position[0].y = (event.value - worker->absRange.y)*CORE.Window.screen.height/worker->absRange.height;      // Scale according to absRange

                    touchAction = 2;    // TOUCH_ACTION_MOVE
                    gestureUpdate = true;
                }

                // Multitouch movement
                if (event.code == ABS_MT_SLOT) worker->touchSlot = event.value;   // Remember the slot number for the folowing events

                if (event.code == ABS_MT_POSITION_X)
                {
                    if (worker->touchSlot < MAX_TOUCH_POINTS) CORE.Input.Touch.position[worker->touchSlot].x = (event.value - worker->absRange.x)*CORE.Window.screen.width/worker->absRange.width;    // Scale according to absRange
                }

                if (event.code == ABS_MT_POSITION_Y)
                {
                    if (worker->touchSlot < MAX_TOUCH_POINTS) CORE.Input.Touch.position[worker->touchSlot].y = (event.value - worker->absRange.y)*CORE.Window.screen.height/worker->absRange.height;  // Scale according to absRange
                }

                if (event.code == ABS_MT_TRACKING_ID)
                {
                    if ((event.value < 0) && (worker->touchSlot < MAX_TOUCH_POINTS))
                    {
                        // Touch has ended for this point
                        CORE.Input.Touch.position[worker->touchSlot].x = -1;
                        CORE.Input.Touch.position[worker->touchSlot].y = -1;
                    }
                }

                // Touchscreen tap
                if (event.code == ABS_PRESSURE)
                {
                    int previousMouseLeftButtonState = CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_LEFT];

                    if (!event.value && previousMouseLeftButtonState)
                    {
                        CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_LEFT] = 0;

                        touchAction = 0;    // TOUCH_ACTION_UP
                        gestureUpdate = true;
                    }

                    if (event.value && !previousMouseLeftButtonState)
                    {
                        CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_LEFT] = 1;

                        touchAction = 1;    // TOUCH_ACTION_DOWN
                        gestureUpdate = true;
                    }
                }

            }

            // Button parsing
            if (event.type == EV_KEY)
            {
                // Mouse button parsing
                if ((event.code == BTN_TOUCH) || (event.code == BTN_LEFT))
                {
                    CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_LEFT] = event.value;

                    if (event.value > 0) touchAction = 1;   // TOUCH_ACTION_DOWN
                    else touchAction = 0;       // TOUCH_ACTION_UP
                    gestureUpdate = true;
                }

                if (event.code == BTN_RIGHT) CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_RIGHT] = event.value;
                if (event.code == BTN_MIDDLE) CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_MIDDLE] = event.value;
                if (event.code == BTN_SIDE) CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_SIDE] = event.value;
                if (event.code == BTN_EXTRA) CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_EXTRA] = event.value;
                if (event.code == BTN_FORWARD) CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_FORWARD] = event.value;
                if (event.code == BTN_BACK) CORE.Input.Mouse.currentButtonStateEvdev[MOUSE_BUTTON_BACK] = event.value;
            }

            // Screen confinement
            if (!CORE.Input.Mouse.cursorHidden)
            {
                if (CORE.Input.Mouse.currentPosition.x < 0) CORE.Input.Mouse.currentPosition.x = 0;
                if (CORE.Input.Mouse.currentPosition.x > CORE.Window.screen.width/CORE.Input.Mouse.scale.x) CORE.Input.Mouse.currentPosition.x = CORE.Window.screen.width/CORE.Input.Mouse.scale.x;

                if (CORE.Input.Mouse.currentPosition.y < 0) CORE.Input.Mouse.currentPosition.y = 0;
                if (CORE.Input.Mouse.currentPosition.y > CORE.Window.screen.height/CORE.Input.Mouse.scale.y) CORE.Input.Mouse.currentPosition.y = CORE.Window.screen.height/CORE.Input.Mouse.scale.y;
            }

            // Update touch point count
            CORE.Input.Touch.pointCount = 0;
            for (int i = 0; i < MAX_TOUCH_POINTS; i++)
            {
                if (CORE.Input.Touch.position[i].x >= 0) CORE.Input.Touch.pointCount++;
            }

#if defined(SUPPORT_GESTURES_SYSTEM)        // PLATFORM_DRM
            if (gestureUpdate)
            {
                GestureEvent gestureEvent = { 0 };

                gestureEvent.touchAction = touchAction;
                gestureEvent.pointCount = CORE.Input.Touch.pointCount;

                for (int i = 0; i < MAX_TOUCH_POINTS; i++)
                {
                    gestureEvent.pointId[i] = i;
                    gestureEvent.position[i] = CORE.Input.Touch.position[i];
                }

                ProcessGestureEvent(gestureEvent);
            }
#endif
        }

        WaitTime(0.005);    // Sleep for 5ms to avoid hogging CPU time
    }

    close(worker->fd);

    return NULL;
}

// Initialize gamepad system
static void InitGamepad(void)
{
    char gamepadDev[128] = { 0 };

    for (int i = 0; i < MAX_GAMEPADS; i++)
    {
        sprintf(gamepadDev, "%s%i", DEFAULT_GAMEPAD_DEV, i);

        if ((CORE.Input.Gamepad.streamId[i] = open(gamepadDev, O_RDONLY | O_NONBLOCK)) < 0)
        {
            // NOTE: Only show message for first gamepad
            if (i == 0) TRACELOG(LOG_WARNING, "RPI: Failed to open Gamepad device, no gamepad available");
        }
        else
        {
            CORE.Input.Gamepad.ready[i] = true;

            // NOTE: Only create one thread
            if (i == 0)
            {
                int error = pthread_create(&CORE.Input.Gamepad.threadId, NULL, &GamepadThread, NULL);

                if (error != 0) TRACELOG(LOG_WARNING, "RPI: Failed to create gamepad input event thread");
                else  TRACELOG(LOG_INFO, "RPI: Gamepad device initialized successfully");
            }
        }
    }
}

// Process Gamepad (/dev/input/js0)
static void *GamepadThread(void *arg)
{
    #define JS_EVENT_BUTTON         0x01    // Button pressed/released
    #define JS_EVENT_AXIS           0x02    // Joystick axis moved
    #define JS_EVENT_INIT           0x80    // Initial state of device

    struct js_event {
        unsigned int time;      // event timestamp in milliseconds
        short value;            // event value
        unsigned char type;     // event type
        unsigned char number;   // event axis/button number
    };

    // Read gamepad event
    struct js_event gamepadEvent = { 0 };

    while (!CORE.Window.shouldClose)
    {
        for (int i = 0; i < MAX_GAMEPADS; i++)
        {
            if (read(CORE.Input.Gamepad.streamId[i], &gamepadEvent, sizeof(struct js_event)) == (int)sizeof(struct js_event))
            {
                gamepadEvent.type &= ~JS_EVENT_INIT;     // Ignore synthetic events

                // Process gamepad events by type
                if (gamepadEvent.type == JS_EVENT_BUTTON)
                {
                    //TRACELOG(LOG_WARNING, "RPI: Gamepad button: %i, value: %i", gamepadEvent.number, gamepadEvent.value);

                    if (gamepadEvent.number < MAX_GAMEPAD_BUTTONS)
                    {
                        // 1 - button pressed, 0 - button released
                        CORE.Input.Gamepad.currentButtonState[i][gamepadEvent.number] = (int)gamepadEvent.value;

                        if ((int)gamepadEvent.value == 1) CORE.Input.Gamepad.lastButtonPressed = gamepadEvent.number;
                        else CORE.Input.Gamepad.lastButtonPressed = 0;       // GAMEPAD_BUTTON_UNKNOWN
                    }
                }
                else if (gamepadEvent.type == JS_EVENT_AXIS)
                {
                    //TRACELOG(LOG_WARNING, "RPI: Gamepad axis: %i, value: %i", gamepadEvent.number, gamepadEvent.value);

                    if (gamepadEvent.number < MAX_GAMEPAD_AXIS)
                    {
                        // NOTE: Scaling of gamepadEvent.value to get values between -1..1
                        CORE.Input.Gamepad.axisState[i][gamepadEvent.number] = (float)gamepadEvent.value/32768;
                    }
                }
            }
            else WaitTime(0.001);    // Sleep for 1 ms to avoid hogging CPU time
        }
    }

    return NULL;
}

// Search matching DRM mode in connector's mode list
static int FindMatchingConnectorMode(const drmModeConnector *connector, const drmModeModeInfo *mode)
{
    if (NULL == connector) return -1;
    if (NULL == mode) return -1;

    // safe bitwise comparison of two modes
    #define BINCMP(a, b) memcmp((a), (b), (sizeof(a) < sizeof(b)) ? sizeof(a) : sizeof(b))

    for (size_t i = 0; i < connector->count_modes; i++)
    {
        TRACELOG(LOG_TRACE, "DISPLAY: DRM mode: %d %ux%u@%u %s", i, connector->modes[i].hdisplay, connector->modes[i].vdisplay,
            connector->modes[i].vrefresh, (connector->modes[i].flags & DRM_MODE_FLAG_INTERLACE) ? "interlaced" : "progressive");

        if (0 == BINCMP(&CORE.Window.crtc->mode, &CORE.Window.connector->modes[i])) return i;
    }

    return -1;

    #undef BINCMP
}

// Search exactly matching DRM connector mode in connector's list
static int FindExactConnectorMode(const drmModeConnector *connector, uint width, uint height, uint fps, bool allowInterlaced)
{
    TRACELOG(LOG_TRACE, "DISPLAY: Searching exact connector mode for %ux%u@%u, selecting an interlaced mode is allowed: %s", width, height, fps, allowInterlaced ? "yes" : "no");

    if (NULL == connector) return -1;

    for (int i = 0; i < CORE.Window.connector->count_modes; i++)
    {
        const drmModeModeInfo *const mode = &CORE.Window.connector->modes[i];

        TRACELOG(LOG_TRACE, "DISPLAY: DRM Mode %d %ux%u@%u %s", i, mode->hdisplay, mode->vdisplay, mode->vrefresh, (mode->flags & DRM_MODE_FLAG_INTERLACE) ? "interlaced" : "progressive");

        if ((mode->flags & DRM_MODE_FLAG_INTERLACE) && (!allowInterlaced)) continue;

        if ((mode->hdisplay == width) && (mode->vdisplay == height) && (mode->vrefresh == fps)) return i;
    }

    TRACELOG(LOG_TRACE, "DISPLAY: No DRM exact matching mode found");
    return -1;
}

// Search the nearest matching DRM connector mode in connector's list
static int FindNearestConnectorMode(const drmModeConnector *connector, uint width, uint height, uint fps, bool allowInterlaced)
{
    TRACELOG(LOG_TRACE, "DISPLAY: Searching nearest connector mode for %ux%u@%u, selecting an interlaced mode is allowed: %s", width, height, fps, allowInterlaced ? "yes" : "no");

    if (NULL == connector) return -1;

    int nearestIndex = -1;
    for (int i = 0; i < CORE.Window.connector->count_modes; i++)
    {
        const drmModeModeInfo *const mode = &CORE.Window.connector->modes[i];

        TRACELOG(LOG_TRACE, "DISPLAY: DRM mode: %d %ux%u@%u %s", i, mode->hdisplay, mode->vdisplay, mode->vrefresh,
            (mode->flags & DRM_MODE_FLAG_INTERLACE) ? "interlaced" : "progressive");

        if ((mode->hdisplay < width) || (mode->vdisplay < height))
        {
            TRACELOG(LOG_TRACE, "DISPLAY: DRM mode is too small");
            continue;
        }

        if ((mode->flags & DRM_MODE_FLAG_INTERLACE) && (!allowInterlaced))
        {
            TRACELOG(LOG_TRACE, "DISPLAY: DRM shouldn't choose an interlaced mode");
            continue;
        }

        if (nearestIndex < 0)
        {
            nearestIndex = i;
            continue;
        }

        const int widthDiff = abs(mode->hdisplay - width);
        const int heightDiff = abs(mode->vdisplay - height);
        const int fpsDiff = abs(mode->vrefresh - fps);

        const int nearestWidthDiff = abs(CORE.Window.connector->modes[nearestIndex].hdisplay - width);
        const int nearestHeightDiff = abs(CORE.Window.connector->modes[nearestIndex].vdisplay - height);
        const int nearestFpsDiff = abs(CORE.Window.connector->modes[nearestIndex].vrefresh - fps);

        if ((widthDiff < nearestWidthDiff) || (heightDiff < nearestHeightDiff) || (fpsDiff < nearestFpsDiff)) {
            nearestIndex = i;
        }
    }

    return nearestIndex;
}