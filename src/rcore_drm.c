#include <stdlib.h>

#include "raylib.h"
#include "rcore.h"

#include <fcntl.h>   // POSIX file control definitions - open(), creat(), fcntl()
#include <unistd.h>  // POSIX standard function definitions - read(), close(), STDIN_FILENO
#include <termios.h> // POSIX terminal control definitions - tcgetattr(), tcsetattr()
#include <pthread.h> // POSIX threads management (inputs reading)
#include <dirent.h>  // POSIX directory browsing

#include <sys/ioctl.h>      // Required for: ioctl() - UNIX System call for device-specific input/output operations
#include <linux/kd.h>       // Linux: KDSKBMODE, K_MEDIUMRAM constants definition
#include <linux/input.h>    // Linux: Keycodes constants definition (KEY_A, ...)
#include <linux/joystick.h> // Linux: Joystick support library

#include <gbm.h>         // Generic Buffer Management (native platform for EGL on DRM)
#include <xf86drm.h>     // Direct Rendering Manager user-level library interface
#include <xf86drmMode.h> // Direct Rendering Manager mode setting (KMS) interface

#include "EGL/egl.h"    // Native platform windowing system interface
#include "EGL/eglext.h" // EGL extensions

typedef struct
{
    pthread_t threadId; // Event reading thread id
    int fd;             // File descriptor to the device it is assigned to
    int eventNum;       // Number of 'event<N>' device
    Rectangle absRange; // Range of values for absolute pointing devices (touchscreens)
    int touchSlot;      // Hold the touch slot number of the currently being sent multitouch block
    bool isMouse;       // True if device supports relative X Y movements
    bool isTouch;       // True if device supports absolute X Y movements and has BTN_TOUCH
    bool isMultitouch;  // True if device supports multiple absolute movevents and has BTN_TOUCH
    bool isKeyboard;    // True if device has letter keycodes
    bool isGamepad;     // True if device has gamepad buttons
} InputEventWorker;

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