return {
  defines = {
    {
      name = "RAYLIB_H",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "RAYLIB_VERSION_MAJOR",
      type = "INT",
      value = 5,
      description = ""
    },
    {
      name = "RAYLIB_VERSION_MINOR",
      type = "INT",
      value = 1,
      description = ""
    },
    {
      name = "RAYLIB_VERSION_PATCH",
      type = "INT",
      value = 0,
      description = ""
    },
    {
      name = "RAYLIB_VERSION",
      type = "STRING",
      value = "5.1-dev",
      description = ""
    },
    {
      name = "__declspec(x)",
      type = "MACRO",
      value = "__attribute__((x))",
      description = ""
    },
    {
      name = "RLAPI",
      type = "UNKNOWN",
      value = "__declspec(dllexport)",
      description = "We are building the library as a Win32 shared library (.dll)"
    },
    {
      name = "PI",
      type = "FLOAT",
      value = 3.14159265358979323846,
      description = ""
    },
    {
      name = "DEG2RAD",
      type = "FLOAT_MATH",
      value = "(PI / 180.0f)",
      description = ""
    },
    {
      name = "RAD2DEG",
      type = "FLOAT_MATH",
      value = "(180.0f / PI)",
      description = ""
    },
    {
      name = "RL_MALLOC(sz)",
      type = "MACRO",
      value = "malloc(sz)",
      description = ""
    },
    {
      name = "RL_CALLOC(n, sz)",
      type = "MACRO",
      value = "calloc(n, sz)",
      description = ""
    },
    {
      name = "RL_REALLOC(ptr, sz)",
      type = "MACRO",
      value = "realloc(ptr, sz)",
      description = ""
    },
    {
      name = "RL_FREE(ptr)",
      type = "MACRO",
      value = "free(ptr)",
      description = ""
    },
    {
      name = "CLITERAL(type)",
      type = "MACRO",
      value = "type",
      description = ""
    },
    {
      name = "RL_COLOR_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "RL_RECTANGLE_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "RL_VECTOR2_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "RL_VECTOR3_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "RL_VECTOR4_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "RL_QUATERNION_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "RL_MATRIX_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "LIGHTGRAY",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "GRAY",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "DARKGRAY",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "YELLOW",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "GOLD",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "ORANGE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "PINK",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "RED",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "MAROON",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "GREEN",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "LIME",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "DARKGREEN",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "SKYBLUE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "BLUE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "DARKBLUE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "PURPLE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "VIOLET",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "DARKPURPLE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "BEIGE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "BROWN",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "DARKBROWN",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "WHITE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "BLACK",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "BLANK",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "MAGENTA",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "RAYWHITE",
      type = "UNKNOWN",
      value = "",
      description = ""
    },
    {
      name = "RL_BOOL_TYPE",
      type = "GUARD",
      value = "",
      description = ""
    },
    {
      name = "MOUSE_LEFT_BUTTON",
      type = "UNKNOWN",
      value = "MOUSE_BUTTON_LEFT",
      description = ""
    },
    {
      name = "MOUSE_RIGHT_BUTTON",
      type = "UNKNOWN",
      value = "MOUSE_BUTTON_RIGHT",
      description = ""
    },
    {
      name = "MOUSE_MIDDLE_BUTTON",
      type = "UNKNOWN",
      value = "MOUSE_BUTTON_MIDDLE",
      description = ""
    },
    {
      name = "MATERIAL_MAP_DIFFUSE",
      type = "UNKNOWN",
      value = "MATERIAL_MAP_ALBEDO",
      description = ""
    },
    {
      name = "MATERIAL_MAP_SPECULAR",
      type = "UNKNOWN",
      value = "MATERIAL_MAP_METALNESS",
      description = ""
    },
    {
      name = "SHADER_LOC_MAP_DIFFUSE",
      type = "UNKNOWN",
      value = "SHADER_LOC_MAP_ALBEDO",
      description = ""
    },
    {
      name = "SHADER_LOC_MAP_SPECULAR",
      type = "UNKNOWN",
      value = "SHADER_LOC_MAP_METALNESS",
      description = ""
    },
    {
      name = "GetMouseRay",
      type = "UNKNOWN",
      value = "GetScreenToWorldRay",
      description = "Compatibility hack for previous raylib versions"
    }
  },
  structs = {
  },
  aliases = {
    {
      type = "Vector4",
      name = "Quaternion",
      description = "Quaternion, 4 components (Vector4 alias)"
    },
    {
      type = "Texture",
      name = "Texture2D",
      description = "Texture2D, same as Texture"
    },
    {
      type = "Texture",
      name = "TextureCubemap",
      description = "TextureCubemap, same as Texture"
    },
    {
      type = "RenderTexture",
      name = "RenderTexture2D",
      description = "RenderTexture2D, same as RenderTexture"
    },
    {
      type = "Camera3D",
      name = "Camera",
      description = "Camera type fallback, defaults to Camera3D"
    }
  },
  enums = {
  },
  callbacks = {
    {
      name = "TraceLogCallback",
      description = "Logging: Redirect trace log messages",
      returnType = "void",
      params = {
        {type = "int", name = "logLevel"},
        {type = "const char *", name = "text"},
        {type = "va_list", name = "args"}
      }
    },
    {
      name = "LoadFileDataCallback",
      description = "FileIO: Load binary data",
      returnType = "unsigned char *",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "int *", name = "dataSize"}
      }
    },
    {
      name = "SaveFileDataCallback",
      description = "FileIO: Save binary data",
      returnType = "bool",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "void *", name = "data"},
        {type = "int", name = "dataSize"}
      }
    },
    {
      name = "LoadFileTextCallback",
      description = "FileIO: Load text data",
      returnType = "char *",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "SaveFileTextCallback",
      description = "FileIO: Save text data",
      returnType = "bool",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "char *", name = "text"}
      }
    },
    {
      name = "AudioCallback",
      description = "",
      returnType = "void",
      params = {
        {type = "void *", name = "bufferData"},
        {type = "unsigned int", name = "frames"}
      }
    }
  },
  functions = {
    {
      name = "InitWindow",
      description = "Initialize window and OpenGL context",
      returnType = "void",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "const char *", name = "title"}
      }
    },
    {
      name = "CloseWindow",
      description = "Close window and unload OpenGL context",
      returnType = "void"
    },
    {
      name = "WindowShouldClose",
      description = "Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)",
      returnType = "bool"
    },
    {
      name = "IsWindowReady",
      description = "Check if window has been initialized successfully",
      returnType = "bool"
    },
    {
      name = "IsWindowFullscreen",
      description = "Check if window is currently fullscreen",
      returnType = "bool"
    },
    {
      name = "IsWindowHidden",
      description = "Check if window is currently hidden (only PLATFORM_DESKTOP)",
      returnType = "bool"
    },
    {
      name = "IsWindowMinimized",
      description = "Check if window is currently minimized (only PLATFORM_DESKTOP)",
      returnType = "bool"
    },
    {
      name = "IsWindowMaximized",
      description = "Check if window is currently maximized (only PLATFORM_DESKTOP)",
      returnType = "bool"
    },
    {
      name = "IsWindowFocused",
      description = "Check if window is currently focused (only PLATFORM_DESKTOP)",
      returnType = "bool"
    },
    {
      name = "IsWindowResized",
      description = "Check if window has been resized last frame",
      returnType = "bool"
    },
    {
      name = "IsWindowState",
      description = "Check if one specific window flag is enabled",
      returnType = "bool",
      params = {
        {type = "unsigned int", name = "flag"}
      }
    },
    {
      name = "SetWindowState",
      description = "Set window configuration state using flags (only PLATFORM_DESKTOP)",
      returnType = "void",
      params = {
        {type = "unsigned int", name = "flags"}
      }
    },
    {
      name = "ClearWindowState",
      description = "Clear window configuration state flags",
      returnType = "void",
      params = {
        {type = "unsigned int", name = "flags"}
      }
    },
    {
      name = "ToggleFullscreen",
      description = "Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)",
      returnType = "void"
    },
    {
      name = "ToggleBorderlessWindowed",
      description = "Toggle window state: borderless windowed (only PLATFORM_DESKTOP)",
      returnType = "void"
    },
    {
      name = "MaximizeWindow",
      description = "Set window state: maximized, if resizable (only PLATFORM_DESKTOP)",
      returnType = "void"
    },
    {
      name = "MinimizeWindow",
      description = "Set window state: minimized, if resizable (only PLATFORM_DESKTOP)",
      returnType = "void"
    },
    {
      name = "RestoreWindow",
      description = "Set window state: not minimized/maximized (only PLATFORM_DESKTOP)",
      returnType = "void"
    },
    {
      name = "SetWindowIcon",
      description = "Set icon for window (single image, RGBA 32bit, only PLATFORM_DESKTOP)",
      returnType = "void",
      params = {
        {type = "Image", name = "image"}
      }
    },
    {
      name = "SetWindowIcons",
      description = "Set icon for window (multiple images, RGBA 32bit, only PLATFORM_DESKTOP)",
      returnType = "void",
      params = {
        {type = "Image *", name = "images"},
        {type = "int", name = "count"}
      }
    },
    {
      name = "SetWindowTitle",
      description = "Set title for window (only PLATFORM_DESKTOP and PLATFORM_WEB)",
      returnType = "void",
      params = {
        {type = "const char *", name = "title"}
      }
    },
    {
      name = "SetWindowPosition",
      description = "Set window position on screen (only PLATFORM_DESKTOP)",
      returnType = "void",
      params = {
        {type = "int", name = "x"},
        {type = "int", name = "y"}
      }
    },
    {
      name = "SetWindowMonitor",
      description = "Set monitor for the current window",
      returnType = "void",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "SetWindowMinSize",
      description = "Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)",
      returnType = "void",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "SetWindowMaxSize",
      description = "Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)",
      returnType = "void",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "SetWindowSize",
      description = "Set window dimensions",
      returnType = "void",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "SetWindowOpacity",
      description = "Set window opacity [0.0f..1.0f] (only PLATFORM_DESKTOP)",
      returnType = "void",
      params = {
        {type = "float", name = "opacity"}
      }
    },
    {
      name = "SetWindowFocused",
      description = "Set window focused (only PLATFORM_DESKTOP)",
      returnType = "void"
    },
    {
      name = "GetWindowHandle",
      description = "Get native window handle",
      returnType = "void *"
    },
    {
      name = "GetScreenWidth",
      description = "Get current screen width",
      returnType = "int"
    },
    {
      name = "GetScreenHeight",
      description = "Get current screen height",
      returnType = "int"
    },
    {
      name = "GetRenderWidth",
      description = "Get current render width (it considers HiDPI)",
      returnType = "int"
    },
    {
      name = "GetRenderHeight",
      description = "Get current render height (it considers HiDPI)",
      returnType = "int"
    },
    {
      name = "GetMonitorCount",
      description = "Get number of connected monitors",
      returnType = "int"
    },
    {
      name = "GetCurrentMonitor",
      description = "Get current connected monitor",
      returnType = "int"
    },
    {
      name = "GetMonitorPosition",
      description = "Get specified monitor position",
      returnType = "Vector2",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "GetMonitorWidth",
      description = "Get specified monitor width (current video mode used by monitor)",
      returnType = "int",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "GetMonitorHeight",
      description = "Get specified monitor height (current video mode used by monitor)",
      returnType = "int",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "GetMonitorPhysicalWidth",
      description = "Get specified monitor physical width in millimetres",
      returnType = "int",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "GetMonitorPhysicalHeight",
      description = "Get specified monitor physical height in millimetres",
      returnType = "int",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "GetMonitorRefreshRate",
      description = "Get specified monitor refresh rate",
      returnType = "int",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "GetWindowPosition",
      description = "Get window position XY on monitor",
      returnType = "Vector2"
    },
    {
      name = "GetWindowScaleDPI",
      description = "Get window scale DPI factor",
      returnType = "Vector2"
    },
    {
      name = "GetMonitorName",
      description = "Get the human-readable, UTF-8 encoded name of the specified monitor",
      returnType = "const char *",
      params = {
        {type = "int", name = "monitor"}
      }
    },
    {
      name = "SetClipboardText",
      description = "Set clipboard text content",
      returnType = "void",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "GetClipboardText",
      description = "Get clipboard text content",
      returnType = "const char *"
    },
    {
      name = "EnableEventWaiting",
      description = "Enable waiting for events on EndDrawing(), no automatic event polling",
      returnType = "void"
    },
    {
      name = "DisableEventWaiting",
      description = "Disable waiting for events on EndDrawing(), automatic events polling",
      returnType = "void"
    },
    {
      name = "ShowCursor",
      description = "Shows cursor",
      returnType = "void"
    },
    {
      name = "HideCursor",
      description = "Hides cursor",
      returnType = "void"
    },
    {
      name = "IsCursorHidden",
      description = "Check if cursor is not visible",
      returnType = "bool"
    },
    {
      name = "EnableCursor",
      description = "Enables cursor (unlock cursor)",
      returnType = "void"
    },
    {
      name = "DisableCursor",
      description = "Disables cursor (lock cursor)",
      returnType = "void"
    },
    {
      name = "IsCursorOnScreen",
      description = "Check if cursor is on the screen",
      returnType = "bool"
    },
    {
      name = "ClearBackground",
      description = "Set background color (framebuffer clear color)",
      returnType = "void",
      params = {
        {type = "Color", name = "color"}
      }
    },
    {
      name = "BeginDrawing",
      description = "Setup canvas (framebuffer) to start drawing",
      returnType = "void"
    },
    {
      name = "EndDrawing",
      description = "End canvas drawing and swap buffers (double buffering)",
      returnType = "void"
    },
    {
      name = "BeginMode2D",
      description = "Begin 2D mode with custom camera (2D)",
      returnType = "void",
      params = {
        {type = "Camera2D", name = "camera"}
      }
    },
    {
      name = "EndMode2D",
      description = "Ends 2D mode with custom camera",
      returnType = "void"
    },
    {
      name = "BeginMode3D",
      description = "Begin 3D mode with custom camera (3D)",
      returnType = "void",
      params = {
        {type = "Camera3D", name = "camera"}
      }
    },
    {
      name = "EndMode3D",
      description = "Ends 3D mode and returns to default 2D orthographic mode",
      returnType = "void"
    },
    {
      name = "BeginTextureMode",
      description = "Begin drawing to render texture",
      returnType = "void",
      params = {
        {type = "RenderTexture2D", name = "target"}
      }
    },
    {
      name = "EndTextureMode",
      description = "Ends drawing to render texture",
      returnType = "void"
    },
    {
      name = "BeginShaderMode",
      description = "Begin custom shader drawing",
      returnType = "void",
      params = {
        {type = "Shader", name = "shader"}
      }
    },
    {
      name = "EndShaderMode",
      description = "End custom shader drawing (use default shader)",
      returnType = "void"
    },
    {
      name = "BeginBlendMode",
      description = "Begin blending mode (alpha, additive, multiplied, subtract, custom)",
      returnType = "void",
      params = {
        {type = "int", name = "mode"}
      }
    },
    {
      name = "EndBlendMode",
      description = "End blending mode (reset to default: alpha blending)",
      returnType = "void"
    },
    {
      name = "BeginScissorMode",
      description = "Begin scissor mode (define screen area for following drawing)",
      returnType = "void",
      params = {
        {type = "int", name = "x"},
        {type = "int", name = "y"},
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "EndScissorMode",
      description = "End scissor mode",
      returnType = "void"
    },
    {
      name = "BeginVrStereoMode",
      description = "Begin stereo rendering (requires VR simulator)",
      returnType = "void",
      params = {
        {type = "VrStereoConfig", name = "config"}
      }
    },
    {
      name = "EndVrStereoMode",
      description = "End stereo rendering (requires VR simulator)",
      returnType = "void"
    },
    {
      name = "LoadVrStereoConfig",
      description = "Load VR stereo config for VR simulator device parameters",
      returnType = "VrStereoConfig",
      params = {
        {type = "VrDeviceInfo", name = "device"}
      }
    },
    {
      name = "UnloadVrStereoConfig",
      description = "Unload VR stereo config",
      returnType = "void",
      params = {
        {type = "VrStereoConfig", name = "config"}
      }
    },
    {
      name = "LoadShader",
      description = "Load shader from files and bind default locations",
      returnType = "Shader",
      params = {
        {type = "const char *", name = "vsFileName"},
        {type = "const char *", name = "fsFileName"}
      }
    },
    {
      name = "LoadShaderFromMemory",
      description = "Load shader from code strings and bind default locations",
      returnType = "Shader",
      params = {
        {type = "const char *", name = "vsCode"},
        {type = "const char *", name = "fsCode"}
      }
    },
    {
      name = "IsShaderReady",
      description = "Check if a shader is ready",
      returnType = "bool",
      params = {
        {type = "Shader", name = "shader"}
      }
    },
    {
      name = "GetShaderLocation",
      description = "Get shader uniform location",
      returnType = "int",
      params = {
        {type = "Shader", name = "shader"},
        {type = "const char *", name = "uniformName"}
      }
    },
    {
      name = "GetShaderLocationAttrib",
      description = "Get shader attribute location",
      returnType = "int",
      params = {
        {type = "Shader", name = "shader"},
        {type = "const char *", name = "attribName"}
      }
    },
    {
      name = "SetShaderValue",
      description = "Set shader uniform value",
      returnType = "void",
      params = {
        {type = "Shader", name = "shader"},
        {type = "int", name = "locIndex"},
        {type = "const void *", name = "value"},
        {type = "int", name = "uniformType"}
      }
    },
    {
      name = "SetShaderValueV",
      description = "Set shader uniform value vector",
      returnType = "void",
      params = {
        {type = "Shader", name = "shader"},
        {type = "int", name = "locIndex"},
        {type = "const void *", name = "value"},
        {type = "int", name = "uniformType"},
        {type = "int", name = "count"}
      }
    },
    {
      name = "SetShaderValueMatrix",
      description = "Set shader uniform value (matrix 4x4)",
      returnType = "void",
      params = {
        {type = "Shader", name = "shader"},
        {type = "int", name = "locIndex"},
        {type = "Matrix", name = "mat"}
      }
    },
    {
      name = "SetShaderValueTexture",
      description = "Set shader uniform value for texture (sampler2d)",
      returnType = "void",
      params = {
        {type = "Shader", name = "shader"},
        {type = "int", name = "locIndex"},
        {type = "Texture2D", name = "texture"}
      }
    },
    {
      name = "UnloadShader",
      description = "Unload shader from GPU memory (VRAM)",
      returnType = "void",
      params = {
        {type = "Shader", name = "shader"}
      }
    },
    {
      name = "GetScreenToWorldRay",
      description = "Get a ray trace from screen position (i.e mouse)",
      returnType = "Ray",
      params = {
        {type = "Vector2", name = "position"},
        {type = "Camera", name = "camera"}
      }
    },
    {
      name = "GetScreenToWorldRayEx",
      description = "Get a ray trace from screen position (i.e mouse) in a viewport",
      returnType = "Ray",
      params = {
        {type = "Vector2", name = "position"},
        {type = "Camera", name = "camera"},
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "GetWorldToScreen",
      description = "Get the screen space position for a 3d world space position",
      returnType = "Vector2",
      params = {
        {type = "Vector3", name = "position"},
        {type = "Camera", name = "camera"}
      }
    },
    {
      name = "GetWorldToScreenEx",
      description = "Get size position for a 3d world space position",
      returnType = "Vector2",
      params = {
        {type = "Vector3", name = "position"},
        {type = "Camera", name = "camera"},
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "GetWorldToScreen2D",
      description = "Get the screen space position for a 2d camera world space position",
      returnType = "Vector2",
      params = {
        {type = "Vector2", name = "position"},
        {type = "Camera2D", name = "camera"}
      }
    },
    {
      name = "GetScreenToWorld2D",
      description = "Get the world space position for a 2d camera screen space position",
      returnType = "Vector2",
      params = {
        {type = "Vector2", name = "position"},
        {type = "Camera2D", name = "camera"}
      }
    },
    {
      name = "GetCameraMatrix",
      description = "Get camera transform matrix (view matrix)",
      returnType = "Matrix",
      params = {
        {type = "Camera", name = "camera"}
      }
    },
    {
      name = "GetCameraMatrix2D",
      description = "Get camera 2d transform matrix",
      returnType = "Matrix",
      params = {
        {type = "Camera2D", name = "camera"}
      }
    },
    {
      name = "SetTargetFPS",
      description = "Set target FPS (maximum)",
      returnType = "void",
      params = {
        {type = "int", name = "fps"}
      }
    },
    {
      name = "GetFrameTime",
      description = "Get time in seconds for last frame drawn (delta time)",
      returnType = "float"
    },
    {
      name = "GetTime",
      description = "Get elapsed time in seconds since InitWindow()",
      returnType = "double"
    },
    {
      name = "GetFPS",
      description = "Get current FPS",
      returnType = "int"
    },
    {
      name = "SwapScreenBuffer",
      description = "Swap back buffer with front buffer (screen drawing)",
      returnType = "void"
    },
    {
      name = "PollInputEvents",
      description = "Register all input events",
      returnType = "void"
    },
    {
      name = "WaitTime",
      description = "Wait for some time (halt program execution)",
      returnType = "void",
      params = {
        {type = "double", name = "seconds"}
      }
    },
    {
      name = "SetRandomSeed",
      description = "Set the seed for the random number generator",
      returnType = "void",
      params = {
        {type = "unsigned int", name = "seed"}
      }
    },
    {
      name = "GetRandomValue",
      description = "Get a random value between min and max (both included)",
      returnType = "int",
      params = {
        {type = "int", name = "min"},
        {type = "int", name = "max"}
      }
    },
    {
      name = "LoadRandomSequence",
      description = "Load random values sequence, no values repeated",
      returnType = "int *",
      params = {
        {type = "unsigned int", name = "count"},
        {type = "int", name = "min"},
        {type = "int", name = "max"}
      }
    },
    {
      name = "UnloadRandomSequence",
      description = "Unload random values sequence",
      returnType = "void",
      params = {
        {type = "int *", name = "sequence"}
      }
    },
    {
      name = "TakeScreenshot",
      description = "Takes a screenshot of current screen (filename extension defines format)",
      returnType = "void",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "SetConfigFlags",
      description = "Setup init configuration flags (view FLAGS)",
      returnType = "void",
      params = {
        {type = "unsigned int", name = "flags"}
      }
    },
    {
      name = "OpenURL",
      description = "Open URL with default system browser (if available)",
      returnType = "void",
      params = {
        {type = "const char *", name = "url"}
      }
    },
    {
      name = "TraceLog",
      description = "Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...)",
      returnType = "void",
      params = {
        {type = "int", name = "logLevel"},
        {type = "const char *", name = "text"},
        {type = "...", name = "args"}
      }
    },
    {
      name = "SetTraceLogLevel",
      description = "Set the current threshold (minimum) log level",
      returnType = "void",
      params = {
        {type = "int", name = "logLevel"}
      }
    },
    {
      name = "MemAlloc",
      description = "Internal memory allocator",
      returnType = "void *",
      params = {
        {type = "unsigned int", name = "size"}
      }
    },
    {
      name = "MemRealloc",
      description = "Internal memory reallocator",
      returnType = "void *",
      params = {
        {type = "void *", name = "ptr"},
        {type = "unsigned int", name = "size"}
      }
    },
    {
      name = "MemFree",
      description = "Internal memory free",
      returnType = "void",
      params = {
        {type = "void *", name = "ptr"}
      }
    },
    {
      name = "SetTraceLogCallback",
      description = "Set custom trace log",
      returnType = "void",
      params = {
        {type = "TraceLogCallback", name = "callback"}
      }
    },
    {
      name = "SetLoadFileDataCallback",
      description = "Set custom file binary data loader",
      returnType = "void",
      params = {
        {type = "LoadFileDataCallback", name = "callback"}
      }
    },
    {
      name = "SetSaveFileDataCallback",
      description = "Set custom file binary data saver",
      returnType = "void",
      params = {
        {type = "SaveFileDataCallback", name = "callback"}
      }
    },
    {
      name = "SetLoadFileTextCallback",
      description = "Set custom file text data loader",
      returnType = "void",
      params = {
        {type = "LoadFileTextCallback", name = "callback"}
      }
    },
    {
      name = "SetSaveFileTextCallback",
      description = "Set custom file text data saver",
      returnType = "void",
      params = {
        {type = "SaveFileTextCallback", name = "callback"}
      }
    },
    {
      name = "LoadFileData",
      description = "Load file data as byte array (read)",
      returnType = "unsigned char *",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "int *", name = "dataSize"}
      }
    },
    {
      name = "UnloadFileData",
      description = "Unload file data allocated by LoadFileData()",
      returnType = "void",
      params = {
        {type = "unsigned char *", name = "data"}
      }
    },
    {
      name = "SaveFileData",
      description = "Save data to file from byte array (write), returns true on success",
      returnType = "bool",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "void *", name = "data"},
        {type = "int", name = "dataSize"}
      }
    },
    {
      name = "ExportDataAsCode",
      description = "Export data to code (.h), returns true on success",
      returnType = "bool",
      params = {
        {type = "const unsigned char *", name = "data"},
        {type = "int", name = "dataSize"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadFileText",
      description = "Load text data from file (read), returns a '\\0' terminated string",
      returnType = "char *",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "UnloadFileText",
      description = "Unload file text data allocated by LoadFileText()",
      returnType = "void",
      params = {
        {type = "char *", name = "text"}
      }
    },
    {
      name = "SaveFileText",
      description = "Save text data to file (write), string must be '\\0' terminated, returns true on success",
      returnType = "bool",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "char *", name = "text"}
      }
    },
    {
      name = "FileExists",
      description = "Check if file exists",
      returnType = "bool",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "DirectoryExists",
      description = "Check if a directory path exists",
      returnType = "bool",
      params = {
        {type = "const char *", name = "dirPath"}
      }
    },
    {
      name = "IsFileExtension",
      description = "Check file extension (including point: .png, .wav)",
      returnType = "bool",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "const char *", name = "ext"}
      }
    },
    {
      name = "GetFileLength",
      description = "Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)",
      returnType = "int",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "GetFileExtension",
      description = "Get pointer to extension for a filename string (includes dot: '.png')",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "GetFileName",
      description = "Get pointer to filename for a path string",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "filePath"}
      }
    },
    {
      name = "GetFileNameWithoutExt",
      description = "Get filename string without extension (uses static string)",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "filePath"}
      }
    },
    {
      name = "GetDirectoryPath",
      description = "Get full path for a given fileName with path (uses static string)",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "filePath"}
      }
    },
    {
      name = "GetPrevDirectoryPath",
      description = "Get previous directory path for a given path (uses static string)",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "dirPath"}
      }
    },
    {
      name = "GetWorkingDirectory",
      description = "Get current working directory (uses static string)",
      returnType = "const char *"
    },
    {
      name = "GetApplicationDirectory",
      description = "Get the directory of the running application (uses static string)",
      returnType = "const char *"
    },
    {
      name = "ChangeDirectory",
      description = "Change working directory, return true on success",
      returnType = "bool",
      params = {
        {type = "const char *", name = "dir"}
      }
    },
    {
      name = "IsPathFile",
      description = "Check if a given path is a file or a directory",
      returnType = "bool",
      params = {
        {type = "const char *", name = "path"}
      }
    },
    {
      name = "IsFileNameValid",
      description = "Check if fileName is valid for the platform/OS",
      returnType = "bool",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadDirectoryFiles",
      description = "Load directory filepaths",
      returnType = "FilePathList",
      params = {
        {type = "const char *", name = "dirPath"}
      }
    },
    {
      name = "LoadDirectoryFilesEx",
      description = "Load directory filepaths with extension filtering and recursive directory scan",
      returnType = "FilePathList",
      params = {
        {type = "const char *", name = "basePath"},
        {type = "const char *", name = "filter"},
        {type = "bool", name = "scanSubdirs"}
      }
    },
    {
      name = "UnloadDirectoryFiles",
      description = "Unload filepaths",
      returnType = "void",
      params = {
        {type = "FilePathList", name = "files"}
      }
    },
    {
      name = "IsFileDropped",
      description = "Check if a file has been dropped into window",
      returnType = "bool"
    },
    {
      name = "LoadDroppedFiles",
      description = "Load dropped filepaths",
      returnType = "FilePathList"
    },
    {
      name = "UnloadDroppedFiles",
      description = "Unload dropped filepaths",
      returnType = "void",
      params = {
        {type = "FilePathList", name = "files"}
      }
    },
    {
      name = "GetFileModTime",
      description = "Get file modification time (last write time)",
      returnType = "long",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "CompressData",
      description = "Compress data (DEFLATE algorithm), memory must be MemFree()",
      returnType = "unsigned char *",
      params = {
        {type = "const unsigned char *", name = "data"},
        {type = "int", name = "dataSize"},
        {type = "int *", name = "compDataSize"}
      }
    },
    {
      name = "DecompressData",
      description = "Decompress data (DEFLATE algorithm), memory must be MemFree()",
      returnType = "unsigned char *",
      params = {
        {type = "const unsigned char *", name = "compData"},
        {type = "int", name = "compDataSize"},
        {type = "int *", name = "dataSize"}
      }
    },
    {
      name = "EncodeDataBase64",
      description = "Encode data to Base64 string, memory must be MemFree()",
      returnType = "char *",
      params = {
        {type = "const unsigned char *", name = "data"},
        {type = "int", name = "dataSize"},
        {type = "int *", name = "outputSize"}
      }
    },
    {
      name = "DecodeDataBase64",
      description = "Decode Base64 string data, memory must be MemFree()",
      returnType = "unsigned char *",
      params = {
        {type = "const unsigned char *", name = "data"},
        {type = "int *", name = "outputSize"}
      }
    },
    {
      name = "LoadAutomationEventList",
      description = "Load automation events list from file, NULL for empty list, capacity = MAX_AUTOMATION_EVENTS",
      returnType = "AutomationEventList",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "UnloadAutomationEventList",
      description = "Unload automation events list from file",
      returnType = "void",
      params = {
        {type = "AutomationEventList", name = "list"}
      }
    },
    {
      name = "ExportAutomationEventList",
      description = "Export automation events list as text file",
      returnType = "bool",
      params = {
        {type = "AutomationEventList", name = "list"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "SetAutomationEventList",
      description = "Set automation event list to record to",
      returnType = "void",
      params = {
        {type = "AutomationEventList *", name = "list"}
      }
    },
    {
      name = "SetAutomationEventBaseFrame",
      description = "Set automation event internal base frame to start recording",
      returnType = "void",
      params = {
        {type = "int", name = "frame"}
      }
    },
    {
      name = "StartAutomationEventRecording",
      description = "Start recording automation events (AutomationEventList must be set)",
      returnType = "void"
    },
    {
      name = "StopAutomationEventRecording",
      description = "Stop recording automation events",
      returnType = "void"
    },
    {
      name = "PlayAutomationEvent",
      description = "Play a recorded automation event",
      returnType = "void",
      params = {
        {type = "AutomationEvent", name = "event"}
      }
    },
    {
      name = "IsKeyPressed",
      description = "Check if a key has been pressed once",
      returnType = "bool",
      params = {
        {type = "int", name = "key"}
      }
    },
    {
      name = "IsKeyPressedRepeat",
      description = "Check if a key has been pressed again (Only PLATFORM_DESKTOP)",
      returnType = "bool",
      params = {
        {type = "int", name = "key"}
      }
    },
    {
      name = "IsKeyDown",
      description = "Check if a key is being pressed",
      returnType = "bool",
      params = {
        {type = "int", name = "key"}
      }
    },
    {
      name = "IsKeyReleased",
      description = "Check if a key has been released once",
      returnType = "bool",
      params = {
        {type = "int", name = "key"}
      }
    },
    {
      name = "IsKeyUp",
      description = "Check if a key is NOT being pressed",
      returnType = "bool",
      params = {
        {type = "int", name = "key"}
      }
    },
    {
      name = "GetKeyPressed",
      description = "Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty",
      returnType = "int"
    },
    {
      name = "GetCharPressed",
      description = "Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty",
      returnType = "int"
    },
    {
      name = "SetExitKey",
      description = "Set a custom key to exit program (default is ESC)",
      returnType = "void",
      params = {
        {type = "int", name = "key"}
      }
    },
    {
      name = "IsGamepadAvailable",
      description = "Check if a gamepad is available",
      returnType = "bool",
      params = {
        {type = "int", name = "gamepad"}
      }
    },
    {
      name = "GetGamepadName",
      description = "Get gamepad internal name id",
      returnType = "const char *",
      params = {
        {type = "int", name = "gamepad"}
      }
    },
    {
      name = "IsGamepadButtonPressed",
      description = "Check if a gamepad button has been pressed once",
      returnType = "bool",
      params = {
        {type = "int", name = "gamepad"},
        {type = "int", name = "button"}
      }
    },
    {
      name = "IsGamepadButtonDown",
      description = "Check if a gamepad button is being pressed",
      returnType = "bool",
      params = {
        {type = "int", name = "gamepad"},
        {type = "int", name = "button"}
      }
    },
    {
      name = "IsGamepadButtonReleased",
      description = "Check if a gamepad button has been released once",
      returnType = "bool",
      params = {
        {type = "int", name = "gamepad"},
        {type = "int", name = "button"}
      }
    },
    {
      name = "IsGamepadButtonUp",
      description = "Check if a gamepad button is NOT being pressed",
      returnType = "bool",
      params = {
        {type = "int", name = "gamepad"},
        {type = "int", name = "button"}
      }
    },
    {
      name = "GetGamepadButtonPressed",
      description = "Get the last gamepad button pressed",
      returnType = "int"
    },
    {
      name = "GetGamepadAxisCount",
      description = "Get gamepad axis count for a gamepad",
      returnType = "int",
      params = {
        {type = "int", name = "gamepad"}
      }
    },
    {
      name = "GetGamepadAxisMovement",
      description = "Get axis movement value for a gamepad axis",
      returnType = "float",
      params = {
        {type = "int", name = "gamepad"},
        {type = "int", name = "axis"}
      }
    },
    {
      name = "SetGamepadMappings",
      description = "Set internal gamepad mappings (SDL_GameControllerDB)",
      returnType = "int",
      params = {
        {type = "const char *", name = "mappings"}
      }
    },
    {
      name = "SetGamepadVibration",
      description = "Set gamepad vibration for both motors",
      returnType = "void",
      params = {
        {type = "int", name = "gamepad"},
        {type = "float", name = "leftMotor"},
        {type = "float", name = "rightMotor"}
      }
    },
    {
      name = "IsMouseButtonPressed",
      description = "Check if a mouse button has been pressed once",
      returnType = "bool",
      params = {
        {type = "int", name = "button"}
      }
    },
    {
      name = "IsMouseButtonDown",
      description = "Check if a mouse button is being pressed",
      returnType = "bool",
      params = {
        {type = "int", name = "button"}
      }
    },
    {
      name = "IsMouseButtonReleased",
      description = "Check if a mouse button has been released once",
      returnType = "bool",
      params = {
        {type = "int", name = "button"}
      }
    },
    {
      name = "IsMouseButtonUp",
      description = "Check if a mouse button is NOT being pressed",
      returnType = "bool",
      params = {
        {type = "int", name = "button"}
      }
    },
    {
      name = "GetMouseX",
      description = "Get mouse position X",
      returnType = "int"
    },
    {
      name = "GetMouseY",
      description = "Get mouse position Y",
      returnType = "int"
    },
    {
      name = "GetMousePosition",
      description = "Get mouse position XY",
      returnType = "Vector2"
    },
    {
      name = "GetMouseDelta",
      description = "Get mouse delta between frames",
      returnType = "Vector2"
    },
    {
      name = "SetMousePosition",
      description = "Set mouse position XY",
      returnType = "void",
      params = {
        {type = "int", name = "x"},
        {type = "int", name = "y"}
      }
    },
    {
      name = "SetMouseOffset",
      description = "Set mouse offset",
      returnType = "void",
      params = {
        {type = "int", name = "offsetX"},
        {type = "int", name = "offsetY"}
      }
    },
    {
      name = "SetMouseScale",
      description = "Set mouse scaling",
      returnType = "void",
      params = {
        {type = "float", name = "scaleX"},
        {type = "float", name = "scaleY"}
      }
    },
    {
      name = "GetMouseWheelMove",
      description = "Get mouse wheel movement for X or Y, whichever is larger",
      returnType = "float"
    },
    {
      name = "GetMouseWheelMoveV",
      description = "Get mouse wheel movement for both X and Y",
      returnType = "Vector2"
    },
    {
      name = "SetMouseCursor",
      description = "Set mouse cursor",
      returnType = "void",
      params = {
        {type = "int", name = "cursor"}
      }
    },
    {
      name = "GetTouchX",
      description = "Get touch position X for touch point 0 (relative to screen size)",
      returnType = "int"
    },
    {
      name = "GetTouchY",
      description = "Get touch position Y for touch point 0 (relative to screen size)",
      returnType = "int"
    },
    {
      name = "GetTouchPosition",
      description = "Get touch position XY for a touch point index (relative to screen size)",
      returnType = "Vector2",
      params = {
        {type = "int", name = "index"}
      }
    },
    {
      name = "GetTouchPointId",
      description = "Get touch point identifier for given index",
      returnType = "int",
      params = {
        {type = "int", name = "index"}
      }
    },
    {
      name = "GetTouchPointCount",
      description = "Get number of touch points",
      returnType = "int"
    },
    {
      name = "SetGesturesEnabled",
      description = "Enable a set of gestures using flags",
      returnType = "void",
      params = {
        {type = "unsigned int", name = "flags"}
      }
    },
    {
      name = "IsGestureDetected",
      description = "Check if a gesture have been detected",
      returnType = "bool",
      params = {
        {type = "unsigned int", name = "gesture"}
      }
    },
    {
      name = "GetGestureDetected",
      description = "Get latest detected gesture",
      returnType = "int"
    },
    {
      name = "GetGestureHoldDuration",
      description = "Get gesture hold time in milliseconds",
      returnType = "float"
    },
    {
      name = "GetGestureDragVector",
      description = "Get gesture drag vector",
      returnType = "Vector2"
    },
    {
      name = "GetGestureDragAngle",
      description = "Get gesture drag angle",
      returnType = "float"
    },
    {
      name = "GetGesturePinchVector",
      description = "Get gesture pinch delta",
      returnType = "Vector2"
    },
    {
      name = "GetGesturePinchAngle",
      description = "Get gesture pinch angle",
      returnType = "float"
    },
    {
      name = "UpdateCamera",
      description = "Update camera position for selected mode",
      returnType = "void",
      params = {
        {type = "Camera *", name = "camera"},
        {type = "int", name = "mode"}
      }
    },
    {
      name = "UpdateCameraPro",
      description = "Update camera movement/rotation",
      returnType = "void",
      params = {
        {type = "Camera *", name = "camera"},
        {type = "Vector3", name = "movement"},
        {type = "Vector3", name = "rotation"},
        {type = "float", name = "zoom"}
      }
    },
    {
      name = "SetShapesTexture",
      description = "Set texture and rectangle to be used on shapes drawing",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "Rectangle", name = "source"}
      }
    },
    {
      name = "GetShapesTexture",
      description = "Get texture that is used for shapes drawing",
      returnType = "Texture2D"
    },
    {
      name = "GetShapesTextureRectangle",
      description = "Get texture source rectangle that is used for shapes drawing",
      returnType = "Rectangle"
    },
    {
      name = "DrawPixel",
      description = "Draw a pixel",
      returnType = "void",
      params = {
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawPixelV",
      description = "Draw a pixel (Vector version)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "position"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawLine",
      description = "Draw a line",
      returnType = "void",
      params = {
        {type = "int", name = "startPosX"},
        {type = "int", name = "startPosY"},
        {type = "int", name = "endPosX"},
        {type = "int", name = "endPosY"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawLineV",
      description = "Draw a line (using gl lines)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "startPos"},
        {type = "Vector2", name = "endPos"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawLineEx",
      description = "Draw a line (using triangles/quads)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "startPos"},
        {type = "Vector2", name = "endPos"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawLineStrip",
      description = "Draw lines sequence (using gl lines)",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawLineBezier",
      description = "Draw line segment cubic-bezier in-out interpolation",
      returnType = "void",
      params = {
        {type = "Vector2", name = "startPos"},
        {type = "Vector2", name = "endPos"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCircle",
      description = "Draw a color-filled circle",
      returnType = "void",
      params = {
        {type = "int", name = "centerX"},
        {type = "int", name = "centerY"},
        {type = "float", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCircleSector",
      description = "Draw a piece of a circle",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "radius"},
        {type = "float", name = "startAngle"},
        {type = "float", name = "endAngle"},
        {type = "int", name = "segments"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCircleSectorLines",
      description = "Draw circle sector outline",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "radius"},
        {type = "float", name = "startAngle"},
        {type = "float", name = "endAngle"},
        {type = "int", name = "segments"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCircleGradient",
      description = "Draw a gradient-filled circle",
      returnType = "void",
      params = {
        {type = "int", name = "centerX"},
        {type = "int", name = "centerY"},
        {type = "float", name = "radius"},
        {type = "Color", name = "color1"},
        {type = "Color", name = "color2"}
      }
    },
    {
      name = "DrawCircleV",
      description = "Draw a color-filled circle (Vector version)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCircleLines",
      description = "Draw circle outline",
      returnType = "void",
      params = {
        {type = "int", name = "centerX"},
        {type = "int", name = "centerY"},
        {type = "float", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCircleLinesV",
      description = "Draw circle outline (Vector version)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawEllipse",
      description = "Draw ellipse",
      returnType = "void",
      params = {
        {type = "int", name = "centerX"},
        {type = "int", name = "centerY"},
        {type = "float", name = "radiusH"},
        {type = "float", name = "radiusV"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawEllipseLines",
      description = "Draw ellipse outline",
      returnType = "void",
      params = {
        {type = "int", name = "centerX"},
        {type = "int", name = "centerY"},
        {type = "float", name = "radiusH"},
        {type = "float", name = "radiusV"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRing",
      description = "Draw ring",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "innerRadius"},
        {type = "float", name = "outerRadius"},
        {type = "float", name = "startAngle"},
        {type = "float", name = "endAngle"},
        {type = "int", name = "segments"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRingLines",
      description = "Draw ring outline",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "innerRadius"},
        {type = "float", name = "outerRadius"},
        {type = "float", name = "startAngle"},
        {type = "float", name = "endAngle"},
        {type = "int", name = "segments"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangle",
      description = "Draw a color-filled rectangle",
      returnType = "void",
      params = {
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangleV",
      description = "Draw a color-filled rectangle (Vector version)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "position"},
        {type = "Vector2", name = "size"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangleRec",
      description = "Draw a color-filled rectangle",
      returnType = "void",
      params = {
        {type = "Rectangle", name = "rec"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectanglePro",
      description = "Draw a color-filled rectangle with pro parameters",
      returnType = "void",
      params = {
        {type = "Rectangle", name = "rec"},
        {type = "Vector2", name = "origin"},
        {type = "float", name = "rotation"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangleGradientV",
      description = "Draw a vertical-gradient-filled rectangle",
      returnType = "void",
      params = {
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "Color", name = "color1"},
        {type = "Color", name = "color2"}
      }
    },
    {
      name = "DrawRectangleGradientH",
      description = "Draw a horizontal-gradient-filled rectangle",
      returnType = "void",
      params = {
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "Color", name = "color1"},
        {type = "Color", name = "color2"}
      }
    },
    {
      name = "DrawRectangleGradientEx",
      description = "Draw a gradient-filled rectangle with custom vertex colors",
      returnType = "void",
      params = {
        {type = "Rectangle", name = "rec"},
        {type = "Color", name = "col1"},
        {type = "Color", name = "col2"},
        {type = "Color", name = "col3"},
        {type = "Color", name = "col4"}
      }
    },
    {
      name = "DrawRectangleLines",
      description = "Draw rectangle outline",
      returnType = "void",
      params = {
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangleLinesEx",
      description = "Draw rectangle outline with extended parameters",
      returnType = "void",
      params = {
        {type = "Rectangle", name = "rec"},
        {type = "float", name = "lineThick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangleRounded",
      description = "Draw rectangle with rounded edges",
      returnType = "void",
      params = {
        {type = "Rectangle", name = "rec"},
        {type = "float", name = "roundness"},
        {type = "int", name = "segments"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangleRoundedLines",
      description = "Draw rectangle lines with rounded edges",
      returnType = "void",
      params = {
        {type = "Rectangle", name = "rec"},
        {type = "float", name = "roundness"},
        {type = "int", name = "segments"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRectangleRoundedLinesEx",
      description = "Draw rectangle with rounded edges outline",
      returnType = "void",
      params = {
        {type = "Rectangle", name = "rec"},
        {type = "float", name = "roundness"},
        {type = "int", name = "segments"},
        {type = "float", name = "lineThick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawTriangle",
      description = "Draw a color-filled triangle (vertex in counter-clockwise order!)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "v1"},
        {type = "Vector2", name = "v2"},
        {type = "Vector2", name = "v3"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawTriangleLines",
      description = "Draw triangle outline (vertex in counter-clockwise order!)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "v1"},
        {type = "Vector2", name = "v2"},
        {type = "Vector2", name = "v3"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawTriangleFan",
      description = "Draw a triangle fan defined by points (first vertex is the center)",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawTriangleStrip",
      description = "Draw a triangle strip defined by points",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawPoly",
      description = "Draw a regular polygon (Vector version)",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "int", name = "sides"},
        {type = "float", name = "radius"},
        {type = "float", name = "rotation"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawPolyLines",
      description = "Draw a polygon outline of n sides",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "int", name = "sides"},
        {type = "float", name = "radius"},
        {type = "float", name = "rotation"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawPolyLinesEx",
      description = "Draw a polygon outline of n sides with extended parameters",
      returnType = "void",
      params = {
        {type = "Vector2", name = "center"},
        {type = "int", name = "sides"},
        {type = "float", name = "radius"},
        {type = "float", name = "rotation"},
        {type = "float", name = "lineThick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineLinear",
      description = "Draw spline: Linear, minimum 2 points",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineBasis",
      description = "Draw spline: B-Spline, minimum 4 points",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineCatmullRom",
      description = "Draw spline: Catmull-Rom, minimum 4 points",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineBezierQuadratic",
      description = "Draw spline: Quadratic Bezier, minimum 3 points (1 control point): [p1, c2, p3, c4...]",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineBezierCubic",
      description = "Draw spline: Cubic Bezier, minimum 4 points (2 control points): [p1, c2, c3, p4, c5, c6...]",
      returnType = "void",
      params = {
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineSegmentLinear",
      description = "Draw spline segment: Linear, 2 points",
      returnType = "void",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineSegmentBasis",
      description = "Draw spline segment: B-Spline, 4 points",
      returnType = "void",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"},
        {type = "Vector2", name = "p3"},
        {type = "Vector2", name = "p4"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineSegmentCatmullRom",
      description = "Draw spline segment: Catmull-Rom, 4 points",
      returnType = "void",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"},
        {type = "Vector2", name = "p3"},
        {type = "Vector2", name = "p4"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineSegmentBezierQuadratic",
      description = "Draw spline segment: Quadratic Bezier, 2 points, 1 control point",
      returnType = "void",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "c2"},
        {type = "Vector2", name = "p3"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSplineSegmentBezierCubic",
      description = "Draw spline segment: Cubic Bezier, 2 points, 2 control points",
      returnType = "void",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "c2"},
        {type = "Vector2", name = "c3"},
        {type = "Vector2", name = "p4"},
        {type = "float", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "GetSplinePointLinear",
      description = "Get (evaluate) spline point: Linear",
      returnType = "Vector2",
      params = {
        {type = "Vector2", name = "startPos"},
        {type = "Vector2", name = "endPos"},
        {type = "float", name = "t"}
      }
    },
    {
      name = "GetSplinePointBasis",
      description = "Get (evaluate) spline point: B-Spline",
      returnType = "Vector2",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"},
        {type = "Vector2", name = "p3"},
        {type = "Vector2", name = "p4"},
        {type = "float", name = "t"}
      }
    },
    {
      name = "GetSplinePointCatmullRom",
      description = "Get (evaluate) spline point: Catmull-Rom",
      returnType = "Vector2",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"},
        {type = "Vector2", name = "p3"},
        {type = "Vector2", name = "p4"},
        {type = "float", name = "t"}
      }
    },
    {
      name = "GetSplinePointBezierQuad",
      description = "Get (evaluate) spline point: Quadratic Bezier",
      returnType = "Vector2",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "c2"},
        {type = "Vector2", name = "p3"},
        {type = "float", name = "t"}
      }
    },
    {
      name = "GetSplinePointBezierCubic",
      description = "Get (evaluate) spline point: Cubic Bezier",
      returnType = "Vector2",
      params = {
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "c2"},
        {type = "Vector2", name = "c3"},
        {type = "Vector2", name = "p4"},
        {type = "float", name = "t"}
      }
    },
    {
      name = "CheckCollisionRecs",
      description = "Check collision between two rectangles",
      returnType = "bool",
      params = {
        {type = "Rectangle", name = "rec1"},
        {type = "Rectangle", name = "rec2"}
      }
    },
    {
      name = "CheckCollisionCircles",
      description = "Check collision between two circles",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "center1"},
        {type = "float", name = "radius1"},
        {type = "Vector2", name = "center2"},
        {type = "float", name = "radius2"}
      }
    },
    {
      name = "CheckCollisionCircleRec",
      description = "Check collision between circle and rectangle",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "radius"},
        {type = "Rectangle", name = "rec"}
      }
    },
    {
      name = "CheckCollisionPointRec",
      description = "Check if point is inside rectangle",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "point"},
        {type = "Rectangle", name = "rec"}
      }
    },
    {
      name = "CheckCollisionPointCircle",
      description = "Check if point is inside circle",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "point"},
        {type = "Vector2", name = "center"},
        {type = "float", name = "radius"}
      }
    },
    {
      name = "CheckCollisionPointTriangle",
      description = "Check if point is inside a triangle",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "point"},
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"},
        {type = "Vector2", name = "p3"}
      }
    },
    {
      name = "CheckCollisionPointPoly",
      description = "Check if point is within a polygon described by array of vertices",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "point"},
        {type = "Vector2 *", name = "points"},
        {type = "int", name = "pointCount"}
      }
    },
    {
      name = "CheckCollisionLines",
      description = "Check the collision between two lines defined by two points each, returns collision point by reference",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "startPos1"},
        {type = "Vector2", name = "endPos1"},
        {type = "Vector2", name = "startPos2"},
        {type = "Vector2", name = "endPos2"},
        {type = "Vector2 *", name = "collisionPoint"}
      }
    },
    {
      name = "CheckCollisionPointLine",
      description = "Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "point"},
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"},
        {type = "int", name = "threshold"}
      }
    },
    {
      name = "CheckCollisionCircleLine",
      description = "Check if circle collides with a line created betweeen two points [p1] and [p2]",
      returnType = "bool",
      params = {
        {type = "Vector2", name = "center"},
        {type = "float", name = "radius"},
        {type = "Vector2", name = "p1"},
        {type = "Vector2", name = "p2"}
      }
    },
    {
      name = "GetCollisionRec",
      description = "Get collision rectangle for two rectangles collision",
      returnType = "Rectangle",
      params = {
        {type = "Rectangle", name = "rec1"},
        {type = "Rectangle", name = "rec2"}
      }
    },
    {
      name = "LoadImage",
      description = "Load image from file into CPU memory (RAM)",
      returnType = "Image",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadImageRaw",
      description = "Load image from RAW file data",
      returnType = "Image",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "int", name = "format"},
        {type = "int", name = "headerSize"}
      }
    },
    {
      name = "LoadImageSvg",
      description = "Load image from SVG file data or string with specified size",
      returnType = "Image",
      params = {
        {type = "const char *", name = "fileNameOrString"},
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "LoadImageAnim",
      description = "Load image sequence from file (frames appended to image.data)",
      returnType = "Image",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "int *", name = "frames"}
      }
    },
    {
      name = "LoadImageAnimFromMemory",
      description = "Load image sequence from memory buffer",
      returnType = "Image",
      params = {
        {type = "const char *", name = "fileType"},
        {type = "const unsigned char *", name = "fileData"},
        {type = "int", name = "dataSize"},
        {type = "int *", name = "frames"}
      }
    },
    {
      name = "LoadImageFromMemory",
      description = "Load image from memory buffer, fileType refers to extension: i.e. '.png'",
      returnType = "Image",
      params = {
        {type = "const char *", name = "fileType"},
        {type = "const unsigned char *", name = "fileData"},
        {type = "int", name = "dataSize"}
      }
    },
    {
      name = "LoadImageFromTexture",
      description = "Load image from GPU texture data",
      returnType = "Image",
      params = {
        {type = "Texture2D", name = "texture"}
      }
    },
    {
      name = "LoadImageFromScreen",
      description = "Load image from screen buffer and (screenshot)",
      returnType = "Image"
    },
    {
      name = "IsImageReady",
      description = "Check if an image is ready",
      returnType = "bool",
      params = {
        {type = "Image", name = "image"}
      }
    },
    {
      name = "UnloadImage",
      description = "Unload image from CPU memory (RAM)",
      returnType = "void",
      params = {
        {type = "Image", name = "image"}
      }
    },
    {
      name = "ExportImage",
      description = "Export image data to file, returns true on success",
      returnType = "bool",
      params = {
        {type = "Image", name = "image"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "ExportImageToMemory",
      description = "Export image to memory buffer",
      returnType = "unsigned char *",
      params = {
        {type = "Image", name = "image"},
        {type = "const char *", name = "fileType"},
        {type = "int *", name = "fileSize"}
      }
    },
    {
      name = "ExportImageAsCode",
      description = "Export image as code file defining an array of bytes, returns true on success",
      returnType = "bool",
      params = {
        {type = "Image", name = "image"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "GenImageColor",
      description = "Generate image: plain color",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "GenImageGradientLinear",
      description = "Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "int", name = "direction"},
        {type = "Color", name = "start"},
        {type = "Color", name = "end"}
      }
    },
    {
      name = "GenImageGradientRadial",
      description = "Generate image: radial gradient",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "float", name = "density"},
        {type = "Color", name = "inner"},
        {type = "Color", name = "outer"}
      }
    },
    {
      name = "GenImageGradientSquare",
      description = "Generate image: square gradient",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "float", name = "density"},
        {type = "Color", name = "inner"},
        {type = "Color", name = "outer"}
      }
    },
    {
      name = "GenImageChecked",
      description = "Generate image: checked",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "int", name = "checksX"},
        {type = "int", name = "checksY"},
        {type = "Color", name = "col1"},
        {type = "Color", name = "col2"}
      }
    },
    {
      name = "GenImageWhiteNoise",
      description = "Generate image: white noise",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "float", name = "factor"}
      }
    },
    {
      name = "GenImagePerlinNoise",
      description = "Generate image: perlin noise",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "int", name = "offsetX"},
        {type = "int", name = "offsetY"},
        {type = "float", name = "scale"}
      }
    },
    {
      name = "GenImageCellular",
      description = "Generate image: cellular algorithm, bigger tileSize means bigger cells",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "int", name = "tileSize"}
      }
    },
    {
      name = "GenImageText",
      description = "Generate image: grayscale image from text data",
      returnType = "Image",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "ImageCopy",
      description = "Create an image duplicate (useful for transformations)",
      returnType = "Image",
      params = {
        {type = "Image", name = "image"}
      }
    },
    {
      name = "ImageFromImage",
      description = "Create an image from another image piece",
      returnType = "Image",
      params = {
        {type = "Image", name = "image"},
        {type = "Rectangle", name = "rec"}
      }
    },
    {
      name = "ImageText",
      description = "Create an image from text (default font)",
      returnType = "Image",
      params = {
        {type = "const char *", name = "text"},
        {type = "int", name = "fontSize"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageTextEx",
      description = "Create an image from text (custom sprite font)",
      returnType = "Image",
      params = {
        {type = "Font", name = "font"},
        {type = "const char *", name = "text"},
        {type = "float", name = "fontSize"},
        {type = "float", name = "spacing"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "ImageFormat",
      description = "Convert image data to desired format",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "newFormat"}
      }
    },
    {
      name = "ImageToPOT",
      description = "Convert image to POT (power-of-two)",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "Color", name = "fill"}
      }
    },
    {
      name = "ImageCrop",
      description = "Crop an image to a defined rectangle",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "Rectangle", name = "crop"}
      }
    },
    {
      name = "ImageAlphaCrop",
      description = "Crop image depending on alpha value",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "float", name = "threshold"}
      }
    },
    {
      name = "ImageAlphaClear",
      description = "Clear alpha channel to desired color",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "Color", name = "color"},
        {type = "float", name = "threshold"}
      }
    },
    {
      name = "ImageAlphaMask",
      description = "Apply alpha mask to image",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "Image", name = "alphaMask"}
      }
    },
    {
      name = "ImageAlphaPremultiply",
      description = "Premultiply alpha channel",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageBlurGaussian",
      description = "Apply Gaussian blur using a box blur approximation",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "blurSize"}
      }
    },
    {
      name = "ImageKernelConvolution",
      description = "Apply Custom Square image convolution kernel",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "float *", name = "kernel"},
        {type = "int", name = "kernelSize"}
      }
    },
    {
      name = "ImageResize",
      description = "Resize image (Bicubic scaling algorithm)",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "newWidth"},
        {type = "int", name = "newHeight"}
      }
    },
    {
      name = "ImageResizeNN",
      description = "Resize image (Nearest-Neighbor scaling algorithm)",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "newWidth"},
        {type = "int", name = "newHeight"}
      }
    },
    {
      name = "ImageResizeCanvas",
      description = "Resize canvas and fill with color",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "newWidth"},
        {type = "int", name = "newHeight"},
        {type = "int", name = "offsetX"},
        {type = "int", name = "offsetY"},
        {type = "Color", name = "fill"}
      }
    },
    {
      name = "ImageMipmaps",
      description = "Compute all mipmap levels for a provided image",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageDither",
      description = "Dither image data to 16bpp or lower (Floyd-Steinberg dithering)",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "rBpp"},
        {type = "int", name = "gBpp"},
        {type = "int", name = "bBpp"},
        {type = "int", name = "aBpp"}
      }
    },
    {
      name = "ImageFlipVertical",
      description = "Flip image vertically",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageFlipHorizontal",
      description = "Flip image horizontally",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageRotate",
      description = "Rotate image by input angle in degrees (-359 to 359)",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "degrees"}
      }
    },
    {
      name = "ImageRotateCW",
      description = "Rotate image clockwise 90deg",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageRotateCCW",
      description = "Rotate image counter-clockwise 90deg",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageColorTint",
      description = "Modify image color: tint",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageColorInvert",
      description = "Modify image color: invert",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageColorGrayscale",
      description = "Modify image color: grayscale",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"}
      }
    },
    {
      name = "ImageColorContrast",
      description = "Modify image color: contrast (-100 to 100)",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "float", name = "contrast"}
      }
    },
    {
      name = "ImageColorBrightness",
      description = "Modify image color: brightness (-255 to 255)",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "int", name = "brightness"}
      }
    },
    {
      name = "ImageColorReplace",
      description = "Modify image color: replace color",
      returnType = "void",
      params = {
        {type = "Image *", name = "image"},
        {type = "Color", name = "color"},
        {type = "Color", name = "replace"}
      }
    },
    {
      name = "LoadImageColors",
      description = "Load color data from image as a Color array (RGBA - 32bit)",
      returnType = "Color *",
      params = {
        {type = "Image", name = "image"}
      }
    },
    {
      name = "LoadImagePalette",
      description = "Load colors palette from image as a Color array (RGBA - 32bit)",
      returnType = "Color *",
      params = {
        {type = "Image", name = "image"},
        {type = "int", name = "maxPaletteSize"},
        {type = "int *", name = "colorCount"}
      }
    },
    {
      name = "UnloadImageColors",
      description = "Unload color data loaded with LoadImageColors()",
      returnType = "void",
      params = {
        {type = "Color *", name = "colors"}
      }
    },
    {
      name = "UnloadImagePalette",
      description = "Unload colors palette loaded with LoadImagePalette()",
      returnType = "void",
      params = {
        {type = "Color *", name = "colors"}
      }
    },
    {
      name = "GetImageAlphaBorder",
      description = "Get image alpha border rectangle",
      returnType = "Rectangle",
      params = {
        {type = "Image", name = "image"},
        {type = "float", name = "threshold"}
      }
    },
    {
      name = "GetImageColor",
      description = "Get image pixel color at (x, y) position",
      returnType = "Color",
      params = {
        {type = "Image", name = "image"},
        {type = "int", name = "x"},
        {type = "int", name = "y"}
      }
    },
    {
      name = "ImageClearBackground",
      description = "Clear image background with given color",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawPixel",
      description = "Draw pixel within an image",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawPixelV",
      description = "Draw pixel within an image (Vector version)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Vector2", name = "position"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawLine",
      description = "Draw line within an image",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "int", name = "startPosX"},
        {type = "int", name = "startPosY"},
        {type = "int", name = "endPosX"},
        {type = "int", name = "endPosY"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawLineV",
      description = "Draw line within an image (Vector version)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Vector2", name = "start"},
        {type = "Vector2", name = "end"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawCircle",
      description = "Draw a filled circle within an image",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "int", name = "centerX"},
        {type = "int", name = "centerY"},
        {type = "int", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawCircleV",
      description = "Draw a filled circle within an image (Vector version)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Vector2", name = "center"},
        {type = "int", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawCircleLines",
      description = "Draw circle outline within an image",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "int", name = "centerX"},
        {type = "int", name = "centerY"},
        {type = "int", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawCircleLinesV",
      description = "Draw circle outline within an image (Vector version)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Vector2", name = "center"},
        {type = "int", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawRectangle",
      description = "Draw rectangle within an image",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawRectangleV",
      description = "Draw rectangle within an image (Vector version)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Vector2", name = "position"},
        {type = "Vector2", name = "size"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawRectangleRec",
      description = "Draw rectangle within an image",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Rectangle", name = "rec"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawRectangleLines",
      description = "Draw rectangle lines within an image",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Rectangle", name = "rec"},
        {type = "int", name = "thick"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDraw",
      description = "Draw a source image within a destination image (tint applied to source)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Image", name = "src"},
        {type = "Rectangle", name = "srcRec"},
        {type = "Rectangle", name = "dstRec"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "ImageDrawText",
      description = "Draw text (using default font) within an image (destination)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "const char *", name = "text"},
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "int", name = "fontSize"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ImageDrawTextEx",
      description = "Draw text (custom sprite font) within an image (destination)",
      returnType = "void",
      params = {
        {type = "Image *", name = "dst"},
        {type = "Font", name = "font"},
        {type = "const char *", name = "text"},
        {type = "Vector2", name = "position"},
        {type = "float", name = "fontSize"},
        {type = "float", name = "spacing"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "LoadTexture",
      description = "Load texture from file into GPU memory (VRAM)",
      returnType = "Texture2D",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadTextureFromImage",
      description = "Load texture from image data",
      returnType = "Texture2D",
      params = {
        {type = "Image", name = "image"}
      }
    },
    {
      name = "LoadTextureCubemap",
      description = "Load cubemap from image, multiple image cubemap layouts supported",
      returnType = "TextureCubemap",
      params = {
        {type = "Image", name = "image"},
        {type = "int", name = "layout"}
      }
    },
    {
      name = "LoadRenderTexture",
      description = "Load texture for rendering (framebuffer)",
      returnType = "RenderTexture2D",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"}
      }
    },
    {
      name = "IsTextureReady",
      description = "Check if a texture is ready",
      returnType = "bool",
      params = {
        {type = "Texture2D", name = "texture"}
      }
    },
    {
      name = "UnloadTexture",
      description = "Unload texture from GPU memory (VRAM)",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"}
      }
    },
    {
      name = "IsRenderTextureReady",
      description = "Check if a render texture is ready",
      returnType = "bool",
      params = {
        {type = "RenderTexture2D", name = "target"}
      }
    },
    {
      name = "UnloadRenderTexture",
      description = "Unload render texture from GPU memory (VRAM)",
      returnType = "void",
      params = {
        {type = "RenderTexture2D", name = "target"}
      }
    },
    {
      name = "UpdateTexture",
      description = "Update GPU texture with new data",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "const void *", name = "pixels"}
      }
    },
    {
      name = "UpdateTextureRec",
      description = "Update GPU texture rectangle with new data",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "Rectangle", name = "rec"},
        {type = "const void *", name = "pixels"}
      }
    },
    {
      name = "GenTextureMipmaps",
      description = "Generate GPU mipmaps for a texture",
      returnType = "void",
      params = {
        {type = "Texture2D *", name = "texture"}
      }
    },
    {
      name = "SetTextureFilter",
      description = "Set texture scaling filter mode",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "int", name = "filter"}
      }
    },
    {
      name = "SetTextureWrap",
      description = "Set texture wrapping mode",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "int", name = "wrap"}
      }
    },
    {
      name = "DrawTexture",
      description = "Draw a Texture2D",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTextureV",
      description = "Draw a Texture2D with position defined as Vector2",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "Vector2", name = "position"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTextureEx",
      description = "Draw a Texture2D with extended parameters",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "Vector2", name = "position"},
        {type = "float", name = "rotation"},
        {type = "float", name = "scale"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTextureRec",
      description = "Draw a part of a texture defined by a rectangle",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "Rectangle", name = "source"},
        {type = "Vector2", name = "position"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTexturePro",
      description = "Draw a part of a texture defined by a rectangle with 'pro' parameters",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "Rectangle", name = "source"},
        {type = "Rectangle", name = "dest"},
        {type = "Vector2", name = "origin"},
        {type = "float", name = "rotation"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTextureNPatch",
      description = "Draws a texture (or part of it) that stretches or shrinks nicely",
      returnType = "void",
      params = {
        {type = "Texture2D", name = "texture"},
        {type = "NPatchInfo", name = "nPatchInfo"},
        {type = "Rectangle", name = "dest"},
        {type = "Vector2", name = "origin"},
        {type = "float", name = "rotation"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "ColorIsEqual",
      description = "Check if two colors are equal",
      returnType = "bool",
      params = {
        {type = "Color", name = "col1"},
        {type = "Color", name = "col2"}
      }
    },
    {
      name = "Fade",
      description = "Get color with alpha applied, alpha goes from 0.0f to 1.0f",
      returnType = "Color",
      params = {
        {type = "Color", name = "color"},
        {type = "float", name = "alpha"}
      }
    },
    {
      name = "ColorToInt",
      description = "Get hexadecimal value for a Color (0xRRGGBBAA)",
      returnType = "int",
      params = {
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ColorNormalize",
      description = "Get Color normalized as float [0..1]",
      returnType = "Vector4",
      params = {
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ColorFromNormalized",
      description = "Get Color from normalized values [0..1]",
      returnType = "Color",
      params = {
        {type = "Vector4", name = "normalized"}
      }
    },
    {
      name = "ColorToHSV",
      description = "Get HSV values for a Color, hue [0..360], saturation/value [0..1]",
      returnType = "Vector3",
      params = {
        {type = "Color", name = "color"}
      }
    },
    {
      name = "ColorFromHSV",
      description = "Get a Color from HSV values, hue [0..360], saturation/value [0..1]",
      returnType = "Color",
      params = {
        {type = "float", name = "hue"},
        {type = "float", name = "saturation"},
        {type = "float", name = "value"}
      }
    },
    {
      name = "ColorTint",
      description = "Get color multiplied with another color",
      returnType = "Color",
      params = {
        {type = "Color", name = "color"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "ColorBrightness",
      description = "Get color with brightness correction, brightness factor goes from -1.0f to 1.0f",
      returnType = "Color",
      params = {
        {type = "Color", name = "color"},
        {type = "float", name = "factor"}
      }
    },
    {
      name = "ColorContrast",
      description = "Get color with contrast correction, contrast values between -1.0f and 1.0f",
      returnType = "Color",
      params = {
        {type = "Color", name = "color"},
        {type = "float", name = "contrast"}
      }
    },
    {
      name = "ColorAlpha",
      description = "Get color with alpha applied, alpha goes from 0.0f to 1.0f",
      returnType = "Color",
      params = {
        {type = "Color", name = "color"},
        {type = "float", name = "alpha"}
      }
    },
    {
      name = "ColorAlphaBlend",
      description = "Get src alpha-blended into dst color with tint",
      returnType = "Color",
      params = {
        {type = "Color", name = "dst"},
        {type = "Color", name = "src"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "GetColor",
      description = "Get Color structure from hexadecimal value",
      returnType = "Color",
      params = {
        {type = "unsigned int", name = "hexValue"}
      }
    },
    {
      name = "GetPixelColor",
      description = "Get Color from a source pixel pointer of certain format",
      returnType = "Color",
      params = {
        {type = "void *", name = "srcPtr"},
        {type = "int", name = "format"}
      }
    },
    {
      name = "SetPixelColor",
      description = "Set color formatted into destination pixel pointer",
      returnType = "void",
      params = {
        {type = "void *", name = "dstPtr"},
        {type = "Color", name = "color"},
        {type = "int", name = "format"}
      }
    },
    {
      name = "GetPixelDataSize",
      description = "Get pixel data size in bytes for certain format",
      returnType = "int",
      params = {
        {type = "int", name = "width"},
        {type = "int", name = "height"},
        {type = "int", name = "format"}
      }
    },
    {
      name = "GetFontDefault",
      description = "Get the default Font",
      returnType = "Font"
    },
    {
      name = "LoadFont",
      description = "Load font from file into GPU memory (VRAM)",
      returnType = "Font",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadFontEx",
      description = "Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character setFont",
      returnType = "Font",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "int", name = "fontSize"},
        {type = "int *", name = "codepoints"},
        {type = "int", name = "codepointCount"}
      }
    },
    {
      name = "LoadFontFromImage",
      description = "Load font from Image (XNA style)",
      returnType = "Font",
      params = {
        {type = "Image", name = "image"},
        {type = "Color", name = "key"},
        {type = "int", name = "firstChar"}
      }
    },
    {
      name = "LoadFontFromMemory",
      description = "Load font from memory buffer, fileType refers to extension: i.e. '.ttf'",
      returnType = "Font",
      params = {
        {type = "const char *", name = "fileType"},
        {type = "const unsigned char *", name = "fileData"},
        {type = "int", name = "dataSize"},
        {type = "int", name = "fontSize"},
        {type = "int *", name = "codepoints"},
        {type = "int", name = "codepointCount"}
      }
    },
    {
      name = "IsFontReady",
      description = "Check if a font is ready",
      returnType = "bool",
      params = {
        {type = "Font", name = "font"}
      }
    },
    {
      name = "LoadFontData",
      description = "Load font data for further use",
      returnType = "GlyphInfo *",
      params = {
        {type = "const unsigned char *", name = "fileData"},
        {type = "int", name = "dataSize"},
        {type = "int", name = "fontSize"},
        {type = "int *", name = "codepoints"},
        {type = "int", name = "codepointCount"},
        {type = "int", name = "type"}
      }
    },
    {
      name = "GenImageFontAtlas",
      description = "Generate image font atlas using chars info",
      returnType = "Image",
      params = {
        {type = "const GlyphInfo *", name = "glyphs"},
        {type = "Rectangle **", name = "glyphRecs"},
        {type = "int", name = "glyphCount"},
        {type = "int", name = "fontSize"},
        {type = "int", name = "padding"},
        {type = "int", name = "packMethod"}
      }
    },
    {
      name = "UnloadFontData",
      description = "Unload font chars info data (RAM)",
      returnType = "void",
      params = {
        {type = "GlyphInfo *", name = "glyphs"},
        {type = "int", name = "glyphCount"}
      }
    },
    {
      name = "UnloadFont",
      description = "Unload font from GPU memory (VRAM)",
      returnType = "void",
      params = {
        {type = "Font", name = "font"}
      }
    },
    {
      name = "ExportFontAsCode",
      description = "Export font as code file, returns true on success",
      returnType = "bool",
      params = {
        {type = "Font", name = "font"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "DrawFPS",
      description = "Draw current FPS",
      returnType = "void",
      params = {
        {type = "int", name = "posX"},
        {type = "int", name = "posY"}
      }
    },
    {
      name = "DrawText",
      description = "Draw text (using default font)",
      returnType = "void",
      params = {
        {type = "const char *", name = "text"},
        {type = "int", name = "posX"},
        {type = "int", name = "posY"},
        {type = "int", name = "fontSize"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawTextEx",
      description = "Draw text using font and additional parameters",
      returnType = "void",
      params = {
        {type = "Font", name = "font"},
        {type = "const char *", name = "text"},
        {type = "Vector2", name = "position"},
        {type = "float", name = "fontSize"},
        {type = "float", name = "spacing"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTextPro",
      description = "Draw text using Font and pro parameters (rotation)",
      returnType = "void",
      params = {
        {type = "Font", name = "font"},
        {type = "const char *", name = "text"},
        {type = "Vector2", name = "position"},
        {type = "Vector2", name = "origin"},
        {type = "float", name = "rotation"},
        {type = "float", name = "fontSize"},
        {type = "float", name = "spacing"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTextCodepoint",
      description = "Draw one character (codepoint)",
      returnType = "void",
      params = {
        {type = "Font", name = "font"},
        {type = "int", name = "codepoint"},
        {type = "Vector2", name = "position"},
        {type = "float", name = "fontSize"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawTextCodepoints",
      description = "Draw multiple character (codepoint)",
      returnType = "void",
      params = {
        {type = "Font", name = "font"},
        {type = "const int *", name = "codepoints"},
        {type = "int", name = "codepointCount"},
        {type = "Vector2", name = "position"},
        {type = "float", name = "fontSize"},
        {type = "float", name = "spacing"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "SetTextLineSpacing",
      description = "Set vertical line spacing when drawing with line-breaks",
      returnType = "void",
      params = {
        {type = "int", name = "spacing"}
      }
    },
    {
      name = "MeasureText",
      description = "Measure string width for default font",
      returnType = "int",
      params = {
        {type = "const char *", name = "text"},
        {type = "int", name = "fontSize"}
      }
    },
    {
      name = "MeasureTextEx",
      description = "Measure string size for Font",
      returnType = "Vector2",
      params = {
        {type = "Font", name = "font"},
        {type = "const char *", name = "text"},
        {type = "float", name = "fontSize"},
        {type = "float", name = "spacing"}
      }
    },
    {
      name = "GetGlyphIndex",
      description = "Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found",
      returnType = "int",
      params = {
        {type = "Font", name = "font"},
        {type = "int", name = "codepoint"}
      }
    },
    {
      name = "GetGlyphInfo",
      description = "Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found",
      returnType = "GlyphInfo",
      params = {
        {type = "Font", name = "font"},
        {type = "int", name = "codepoint"}
      }
    },
    {
      name = "GetGlyphAtlasRec",
      description = "Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found",
      returnType = "Rectangle",
      params = {
        {type = "Font", name = "font"},
        {type = "int", name = "codepoint"}
      }
    },
    {
      name = "LoadUTF8",
      description = "Load UTF-8 text encoded from codepoints array",
      returnType = "char *",
      params = {
        {type = "const int *", name = "codepoints"},
        {type = "int", name = "length"}
      }
    },
    {
      name = "UnloadUTF8",
      description = "Unload UTF-8 text encoded from codepoints array",
      returnType = "void",
      params = {
        {type = "char *", name = "text"}
      }
    },
    {
      name = "LoadCodepoints",
      description = "Load all codepoints from a UTF-8 text string, codepoints count returned by parameter",
      returnType = "int *",
      params = {
        {type = "const char *", name = "text"},
        {type = "int *", name = "count"}
      }
    },
    {
      name = "UnloadCodepoints",
      description = "Unload codepoints data from memory",
      returnType = "void",
      params = {
        {type = "int *", name = "codepoints"}
      }
    },
    {
      name = "GetCodepointCount",
      description = "Get total number of codepoints in a UTF-8 encoded string",
      returnType = "int",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "GetCodepoint",
      description = "Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure",
      returnType = "int",
      params = {
        {type = "const char *", name = "text"},
        {type = "int *", name = "codepointSize"}
      }
    },
    {
      name = "GetCodepointNext",
      description = "Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure",
      returnType = "int",
      params = {
        {type = "const char *", name = "text"},
        {type = "int *", name = "codepointSize"}
      }
    },
    {
      name = "GetCodepointPrevious",
      description = "Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure",
      returnType = "int",
      params = {
        {type = "const char *", name = "text"},
        {type = "int *", name = "codepointSize"}
      }
    },
    {
      name = "CodepointToUTF8",
      description = "Encode one codepoint into UTF-8 byte array (array length returned as parameter)",
      returnType = "const char *",
      params = {
        {type = "int", name = "codepoint"},
        {type = "int *", name = "utf8Size"}
      }
    },
    {
      name = "TextCopy",
      description = "Copy one string to another, returns bytes copied",
      returnType = "int",
      params = {
        {type = "char *", name = "dst"},
        {type = "const char *", name = "src"}
      }
    },
    {
      name = "TextIsEqual",
      description = "Check if two text string are equal",
      returnType = "bool",
      params = {
        {type = "const char *", name = "text1"},
        {type = "const char *", name = "text2"}
      }
    },
    {
      name = "TextLength",
      description = "Get text length, checks for '\\0' ending",
      returnType = "unsigned int",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "TextFormat",
      description = "Text formatting with variables (sprintf() style)",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "text"},
        {type = "...", name = "args"}
      }
    },
    {
      name = "TextSubtext",
      description = "Get a piece of a text string",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "text"},
        {type = "int", name = "position"},
        {type = "int", name = "length"}
      }
    },
    {
      name = "TextReplace",
      description = "Replace text string (WARNING: memory must be freed!)",
      returnType = "char *",
      params = {
        {type = "const char *", name = "text"},
        {type = "const char *", name = "replace"},
        {type = "const char *", name = "by"}
      }
    },
    {
      name = "TextInsert",
      description = "Insert text in a position (WARNING: memory must be freed!)",
      returnType = "char *",
      params = {
        {type = "const char *", name = "text"},
        {type = "const char *", name = "insert"},
        {type = "int", name = "position"}
      }
    },
    {
      name = "TextJoin",
      description = "Join text strings with delimiter",
      returnType = "const char *",
      params = {
        {type = "const char **", name = "textList"},
        {type = "int", name = "count"},
        {type = "const char *", name = "delimiter"}
      }
    },
    {
      name = "TextSplit",
      description = "Split text into multiple strings",
      returnType = "const char **",
      params = {
        {type = "const char *", name = "text"},
        {type = "char", name = "delimiter"},
        {type = "int *", name = "count"}
      }
    },
    {
      name = "TextAppend",
      description = "Append text at specific position and move cursor!",
      returnType = "void",
      params = {
        {type = "char *", name = "text"},
        {type = "const char *", name = "append"},
        {type = "int *", name = "position"}
      }
    },
    {
      name = "TextFindIndex",
      description = "Find first text occurrence within a string",
      returnType = "int",
      params = {
        {type = "const char *", name = "text"},
        {type = "const char *", name = "find"}
      }
    },
    {
      name = "TextToUpper",
      description = "Get upper case version of provided string",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "TextToLower",
      description = "Get lower case version of provided string",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "TextToPascal",
      description = "Get Pascal case notation version of provided string",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "TextToSnake",
      description = "Get Snake case notation version of provided string",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "TextToCamel",
      description = "Get Camel case notation version of provided string",
      returnType = "const char *",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "TextToInteger",
      description = "Get integer value from text (negative values not supported)",
      returnType = "int",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "TextToFloat",
      description = "Get float value from text (negative values not supported)",
      returnType = "float",
      params = {
        {type = "const char *", name = "text"}
      }
    },
    {
      name = "DrawLine3D",
      description = "Draw a line in 3D world space",
      returnType = "void",
      params = {
        {type = "Vector3", name = "startPos"},
        {type = "Vector3", name = "endPos"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawPoint3D",
      description = "Draw a point in 3D space, actually a small line",
      returnType = "void",
      params = {
        {type = "Vector3", name = "position"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCircle3D",
      description = "Draw a circle in 3D world space",
      returnType = "void",
      params = {
        {type = "Vector3", name = "center"},
        {type = "float", name = "radius"},
        {type = "Vector3", name = "rotationAxis"},
        {type = "float", name = "rotationAngle"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawTriangle3D",
      description = "Draw a color-filled triangle (vertex in counter-clockwise order!)",
      returnType = "void",
      params = {
        {type = "Vector3", name = "v1"},
        {type = "Vector3", name = "v2"},
        {type = "Vector3", name = "v3"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawTriangleStrip3D",
      description = "Draw a triangle strip defined by points",
      returnType = "void",
      params = {
        {type = "Vector3 *", name = "points"},
        {type = "int", name = "pointCount"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCube",
      description = "Draw cube",
      returnType = "void",
      params = {
        {type = "Vector3", name = "position"},
        {type = "float", name = "width"},
        {type = "float", name = "height"},
        {type = "float", name = "length"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCubeV",
      description = "Draw cube (Vector version)",
      returnType = "void",
      params = {
        {type = "Vector3", name = "position"},
        {type = "Vector3", name = "size"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCubeWires",
      description = "Draw cube wires",
      returnType = "void",
      params = {
        {type = "Vector3", name = "position"},
        {type = "float", name = "width"},
        {type = "float", name = "height"},
        {type = "float", name = "length"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCubeWiresV",
      description = "Draw cube wires (Vector version)",
      returnType = "void",
      params = {
        {type = "Vector3", name = "position"},
        {type = "Vector3", name = "size"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSphere",
      description = "Draw sphere",
      returnType = "void",
      params = {
        {type = "Vector3", name = "centerPos"},
        {type = "float", name = "radius"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSphereEx",
      description = "Draw sphere with extended parameters",
      returnType = "void",
      params = {
        {type = "Vector3", name = "centerPos"},
        {type = "float", name = "radius"},
        {type = "int", name = "rings"},
        {type = "int", name = "slices"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawSphereWires",
      description = "Draw sphere wires",
      returnType = "void",
      params = {
        {type = "Vector3", name = "centerPos"},
        {type = "float", name = "radius"},
        {type = "int", name = "rings"},
        {type = "int", name = "slices"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCylinder",
      description = "Draw a cylinder/cone",
      returnType = "void",
      params = {
        {type = "Vector3", name = "position"},
        {type = "float", name = "radiusTop"},
        {type = "float", name = "radiusBottom"},
        {type = "float", name = "height"},
        {type = "int", name = "slices"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCylinderEx",
      description = "Draw a cylinder with base at startPos and top at endPos",
      returnType = "void",
      params = {
        {type = "Vector3", name = "startPos"},
        {type = "Vector3", name = "endPos"},
        {type = "float", name = "startRadius"},
        {type = "float", name = "endRadius"},
        {type = "int", name = "sides"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCylinderWires",
      description = "Draw a cylinder/cone wires",
      returnType = "void",
      params = {
        {type = "Vector3", name = "position"},
        {type = "float", name = "radiusTop"},
        {type = "float", name = "radiusBottom"},
        {type = "float", name = "height"},
        {type = "int", name = "slices"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCylinderWiresEx",
      description = "Draw a cylinder wires with base at startPos and top at endPos",
      returnType = "void",
      params = {
        {type = "Vector3", name = "startPos"},
        {type = "Vector3", name = "endPos"},
        {type = "float", name = "startRadius"},
        {type = "float", name = "endRadius"},
        {type = "int", name = "sides"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCapsule",
      description = "Draw a capsule with the center of its sphere caps at startPos and endPos",
      returnType = "void",
      params = {
        {type = "Vector3", name = "startPos"},
        {type = "Vector3", name = "endPos"},
        {type = "float", name = "radius"},
        {type = "int", name = "slices"},
        {type = "int", name = "rings"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawCapsuleWires",
      description = "Draw capsule wireframe with the center of its sphere caps at startPos and endPos",
      returnType = "void",
      params = {
        {type = "Vector3", name = "startPos"},
        {type = "Vector3", name = "endPos"},
        {type = "float", name = "radius"},
        {type = "int", name = "slices"},
        {type = "int", name = "rings"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawPlane",
      description = "Draw a plane XZ",
      returnType = "void",
      params = {
        {type = "Vector3", name = "centerPos"},
        {type = "Vector2", name = "size"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawRay",
      description = "Draw a ray line",
      returnType = "void",
      params = {
        {type = "Ray", name = "ray"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawGrid",
      description = "Draw a grid (centered at (0, 0, 0))",
      returnType = "void",
      params = {
        {type = "int", name = "slices"},
        {type = "float", name = "spacing"}
      }
    },
    {
      name = "LoadModel",
      description = "Load model from files (meshes and materials)",
      returnType = "Model",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadModelFromMesh",
      description = "Load model from generated mesh (default material)",
      returnType = "Model",
      params = {
        {type = "Mesh", name = "mesh"}
      }
    },
    {
      name = "IsModelReady",
      description = "Check if a model is ready",
      returnType = "bool",
      params = {
        {type = "Model", name = "model"}
      }
    },
    {
      name = "UnloadModel",
      description = "Unload model (including meshes) from memory (RAM and/or VRAM)",
      returnType = "void",
      params = {
        {type = "Model", name = "model"}
      }
    },
    {
      name = "GetModelBoundingBox",
      description = "Compute model bounding box limits (considers all meshes)",
      returnType = "BoundingBox",
      params = {
        {type = "Model", name = "model"}
      }
    },
    {
      name = "DrawModel",
      description = "Draw a model (with texture if set)",
      returnType = "void",
      params = {
        {type = "Model", name = "model"},
        {type = "Vector3", name = "position"},
        {type = "float", name = "scale"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawModelEx",
      description = "Draw a model with extended parameters",
      returnType = "void",
      params = {
        {type = "Model", name = "model"},
        {type = "Vector3", name = "position"},
        {type = "Vector3", name = "rotationAxis"},
        {type = "float", name = "rotationAngle"},
        {type = "Vector3", name = "scale"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawModelWires",
      description = "Draw a model wires (with texture if set)",
      returnType = "void",
      params = {
        {type = "Model", name = "model"},
        {type = "Vector3", name = "position"},
        {type = "float", name = "scale"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawModelWiresEx",
      description = "Draw a model wires (with texture if set) with extended parameters",
      returnType = "void",
      params = {
        {type = "Model", name = "model"},
        {type = "Vector3", name = "position"},
        {type = "Vector3", name = "rotationAxis"},
        {type = "float", name = "rotationAngle"},
        {type = "Vector3", name = "scale"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawBoundingBox",
      description = "Draw bounding box (wires)",
      returnType = "void",
      params = {
        {type = "BoundingBox", name = "box"},
        {type = "Color", name = "color"}
      }
    },
    {
      name = "DrawBillboard",
      description = "Draw a billboard texture",
      returnType = "void",
      params = {
        {type = "Camera", name = "camera"},
        {type = "Texture2D", name = "texture"},
        {type = "Vector3", name = "position"},
        {type = "float", name = "size"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawBillboardRec",
      description = "Draw a billboard texture defined by source",
      returnType = "void",
      params = {
        {type = "Camera", name = "camera"},
        {type = "Texture2D", name = "texture"},
        {type = "Rectangle", name = "source"},
        {type = "Vector3", name = "position"},
        {type = "Vector2", name = "size"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "DrawBillboardPro",
      description = "Draw a billboard texture defined by source and rotation",
      returnType = "void",
      params = {
        {type = "Camera", name = "camera"},
        {type = "Texture2D", name = "texture"},
        {type = "Rectangle", name = "source"},
        {type = "Vector3", name = "position"},
        {type = "Vector3", name = "up"},
        {type = "Vector2", name = "size"},
        {type = "Vector2", name = "origin"},
        {type = "float", name = "rotation"},
        {type = "Color", name = "tint"}
      }
    },
    {
      name = "UploadMesh",
      description = "Upload mesh vertex data in GPU and provide VAO/VBO ids",
      returnType = "void",
      params = {
        {type = "Mesh *", name = "mesh"},
        {type = "bool", name = "dynamic"}
      }
    },
    {
      name = "UpdateMeshBuffer",
      description = "Update mesh vertex data in GPU for a specific buffer index",
      returnType = "void",
      params = {
        {type = "Mesh", name = "mesh"},
        {type = "int", name = "index"},
        {type = "const void *", name = "data"},
        {type = "int", name = "dataSize"},
        {type = "int", name = "offset"}
      }
    },
    {
      name = "UnloadMesh",
      description = "Unload mesh data from CPU and GPU",
      returnType = "void",
      params = {
        {type = "Mesh", name = "mesh"}
      }
    },
    {
      name = "DrawMesh",
      description = "Draw a 3d mesh with material and transform",
      returnType = "void",
      params = {
        {type = "Mesh", name = "mesh"},
        {type = "Material", name = "material"},
        {type = "Matrix", name = "transform"}
      }
    },
    {
      name = "DrawMeshInstanced",
      description = "Draw multiple mesh instances with material and different transforms",
      returnType = "void",
      params = {
        {type = "Mesh", name = "mesh"},
        {type = "Material", name = "material"},
        {type = "const Matrix *", name = "transforms"},
        {type = "int", name = "instances"}
      }
    },
    {
      name = "GetMeshBoundingBox",
      description = "Compute mesh bounding box limits",
      returnType = "BoundingBox",
      params = {
        {type = "Mesh", name = "mesh"}
      }
    },
    {
      name = "GenMeshTangents",
      description = "Compute mesh tangents",
      returnType = "void",
      params = {
        {type = "Mesh *", name = "mesh"}
      }
    },
    {
      name = "ExportMesh",
      description = "Export mesh data to file, returns true on success",
      returnType = "bool",
      params = {
        {type = "Mesh", name = "mesh"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "ExportMeshAsCode",
      description = "Export mesh as code file (.h) defining multiple arrays of vertex attributes",
      returnType = "bool",
      params = {
        {type = "Mesh", name = "mesh"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "GenMeshPoly",
      description = "Generate polygonal mesh",
      returnType = "Mesh",
      params = {
        {type = "int", name = "sides"},
        {type = "float", name = "radius"}
      }
    },
    {
      name = "GenMeshPlane",
      description = "Generate plane mesh (with subdivisions)",
      returnType = "Mesh",
      params = {
        {type = "float", name = "width"},
        {type = "float", name = "length"},
        {type = "int", name = "resX"},
        {type = "int", name = "resZ"}
      }
    },
    {
      name = "GenMeshCube",
      description = "Generate cuboid mesh",
      returnType = "Mesh",
      params = {
        {type = "float", name = "width"},
        {type = "float", name = "height"},
        {type = "float", name = "length"}
      }
    },
    {
      name = "GenMeshSphere",
      description = "Generate sphere mesh (standard sphere)",
      returnType = "Mesh",
      params = {
        {type = "float", name = "radius"},
        {type = "int", name = "rings"},
        {type = "int", name = "slices"}
      }
    },
    {
      name = "GenMeshHemiSphere",
      description = "Generate half-sphere mesh (no bottom cap)",
      returnType = "Mesh",
      params = {
        {type = "float", name = "radius"},
        {type = "int", name = "rings"},
        {type = "int", name = "slices"}
      }
    },
    {
      name = "GenMeshCylinder",
      description = "Generate cylinder mesh",
      returnType = "Mesh",
      params = {
        {type = "float", name = "radius"},
        {type = "float", name = "height"},
        {type = "int", name = "slices"}
      }
    },
    {
      name = "GenMeshCone",
      description = "Generate cone/pyramid mesh",
      returnType = "Mesh",
      params = {
        {type = "float", name = "radius"},
        {type = "float", name = "height"},
        {type = "int", name = "slices"}
      }
    },
    {
      name = "GenMeshTorus",
      description = "Generate torus mesh",
      returnType = "Mesh",
      params = {
        {type = "float", name = "radius"},
        {type = "float", name = "size"},
        {type = "int", name = "radSeg"},
        {type = "int", name = "sides"}
      }
    },
    {
      name = "GenMeshKnot",
      description = "Generate trefoil knot mesh",
      returnType = "Mesh",
      params = {
        {type = "float", name = "radius"},
        {type = "float", name = "size"},
        {type = "int", name = "radSeg"},
        {type = "int", name = "sides"}
      }
    },
    {
      name = "GenMeshHeightmap",
      description = "Generate heightmap mesh from image data",
      returnType = "Mesh",
      params = {
        {type = "Image", name = "heightmap"},
        {type = "Vector3", name = "size"}
      }
    },
    {
      name = "GenMeshCubicmap",
      description = "Generate cubes-based map mesh from image data",
      returnType = "Mesh",
      params = {
        {type = "Image", name = "cubicmap"},
        {type = "Vector3", name = "cubeSize"}
      }
    },
    {
      name = "LoadMaterials",
      description = "Load materials from model file",
      returnType = "Material *",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "int *", name = "materialCount"}
      }
    },
    {
      name = "LoadMaterialDefault",
      description = "Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)",
      returnType = "Material"
    },
    {
      name = "IsMaterialReady",
      description = "Check if a material is ready",
      returnType = "bool",
      params = {
        {type = "Material", name = "material"}
      }
    },
    {
      name = "UnloadMaterial",
      description = "Unload material from GPU memory (VRAM)",
      returnType = "void",
      params = {
        {type = "Material", name = "material"}
      }
    },
    {
      name = "SetMaterialTexture",
      description = "Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)",
      returnType = "void",
      params = {
        {type = "Material *", name = "material"},
        {type = "int", name = "mapType"},
        {type = "Texture2D", name = "texture"}
      }
    },
    {
      name = "SetModelMeshMaterial",
      description = "Set material for a mesh",
      returnType = "void",
      params = {
        {type = "Model *", name = "model"},
        {type = "int", name = "meshId"},
        {type = "int", name = "materialId"}
      }
    },
    {
      name = "LoadModelAnimations",
      description = "Load model animations from file",
      returnType = "ModelAnimation *",
      params = {
        {type = "const char *", name = "fileName"},
        {type = "int *", name = "animCount"}
      }
    },
    {
      name = "UpdateModelAnimation",
      description = "Update model animation pose",
      returnType = "void",
      params = {
        {type = "Model", name = "model"},
        {type = "ModelAnimation", name = "anim"},
        {type = "int", name = "frame"}
      }
    },
    {
      name = "UnloadModelAnimation",
      description = "Unload animation data",
      returnType = "void",
      params = {
        {type = "ModelAnimation", name = "anim"}
      }
    },
    {
      name = "UnloadModelAnimations",
      description = "Unload animation array data",
      returnType = "void",
      params = {
        {type = "ModelAnimation *", name = "animations"},
        {type = "int", name = "animCount"}
      }
    },
    {
      name = "IsModelAnimationValid",
      description = "Check model animation skeleton match",
      returnType = "bool",
      params = {
        {type = "Model", name = "model"},
        {type = "ModelAnimation", name = "anim"}
      }
    },
    {
      name = "CheckCollisionSpheres",
      description = "Check collision between two spheres",
      returnType = "bool",
      params = {
        {type = "Vector3", name = "center1"},
        {type = "float", name = "radius1"},
        {type = "Vector3", name = "center2"},
        {type = "float", name = "radius2"}
      }
    },
    {
      name = "CheckCollisionBoxes",
      description = "Check collision between two bounding boxes",
      returnType = "bool",
      params = {
        {type = "BoundingBox", name = "box1"},
        {type = "BoundingBox", name = "box2"}
      }
    },
    {
      name = "CheckCollisionBoxSphere",
      description = "Check collision between box and sphere",
      returnType = "bool",
      params = {
        {type = "BoundingBox", name = "box"},
        {type = "Vector3", name = "center"},
        {type = "float", name = "radius"}
      }
    },
    {
      name = "GetRayCollisionSphere",
      description = "Get collision info between ray and sphere",
      returnType = "RayCollision",
      params = {
        {type = "Ray", name = "ray"},
        {type = "Vector3", name = "center"},
        {type = "float", name = "radius"}
      }
    },
    {
      name = "GetRayCollisionBox",
      description = "Get collision info between ray and box",
      returnType = "RayCollision",
      params = {
        {type = "Ray", name = "ray"},
        {type = "BoundingBox", name = "box"}
      }
    },
    {
      name = "GetRayCollisionMesh",
      description = "Get collision info between ray and mesh",
      returnType = "RayCollision",
      params = {
        {type = "Ray", name = "ray"},
        {type = "Mesh", name = "mesh"},
        {type = "Matrix", name = "transform"}
      }
    },
    {
      name = "GetRayCollisionTriangle",
      description = "Get collision info between ray and triangle",
      returnType = "RayCollision",
      params = {
        {type = "Ray", name = "ray"},
        {type = "Vector3", name = "p1"},
        {type = "Vector3", name = "p2"},
        {type = "Vector3", name = "p3"}
      }
    },
    {
      name = "GetRayCollisionQuad",
      description = "Get collision info between ray and quad",
      returnType = "RayCollision",
      params = {
        {type = "Ray", name = "ray"},
        {type = "Vector3", name = "p1"},
        {type = "Vector3", name = "p2"},
        {type = "Vector3", name = "p3"},
        {type = "Vector3", name = "p4"}
      }
    },
    {
      name = "InitAudioDevice",
      description = "Initialize audio device and context",
      returnType = "void"
    },
    {
      name = "CloseAudioDevice",
      description = "Close the audio device and context",
      returnType = "void"
    },
    {
      name = "IsAudioDeviceReady",
      description = "Check if audio device has been initialized successfully",
      returnType = "bool"
    },
    {
      name = "SetMasterVolume",
      description = "Set master volume (listener)",
      returnType = "void",
      params = {
        {type = "float", name = "volume"}
      }
    },
    {
      name = "GetMasterVolume",
      description = "Get master volume (listener)",
      returnType = "float"
    },
    {
      name = "LoadWave",
      description = "Load wave data from file",
      returnType = "Wave",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadWaveFromMemory",
      description = "Load wave from memory buffer, fileType refers to extension: i.e. '.wav'",
      returnType = "Wave",
      params = {
        {type = "const char *", name = "fileType"},
        {type = "const unsigned char *", name = "fileData"},
        {type = "int", name = "dataSize"}
      }
    },
    {
      name = "IsWaveReady",
      description = "Checks if wave data is ready",
      returnType = "bool",
      params = {
        {type = "Wave", name = "wave"}
      }
    },
    {
      name = "LoadSound",
      description = "Load sound from file",
      returnType = "Sound",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadSoundFromWave",
      description = "Load sound from wave data",
      returnType = "Sound",
      params = {
        {type = "Wave", name = "wave"}
      }
    },
    {
      name = "LoadSoundAlias",
      description = "Create a new sound that shares the same sample data as the source sound, does not own the sound data",
      returnType = "Sound",
      params = {
        {type = "Sound", name = "source"}
      }
    },
    {
      name = "IsSoundReady",
      description = "Checks if a sound is ready",
      returnType = "bool",
      params = {
        {type = "Sound", name = "sound"}
      }
    },
    {
      name = "UpdateSound",
      description = "Update sound buffer with new data",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"},
        {type = "const void *", name = "data"},
        {type = "int", name = "sampleCount"}
      }
    },
    {
      name = "UnloadWave",
      description = "Unload wave data",
      returnType = "void",
      params = {
        {type = "Wave", name = "wave"}
      }
    },
    {
      name = "UnloadSound",
      description = "Unload sound",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"}
      }
    },
    {
      name = "UnloadSoundAlias",
      description = "Unload a sound alias (does not deallocate sample data)",
      returnType = "void",
      params = {
        {type = "Sound", name = "alias"}
      }
    },
    {
      name = "ExportWave",
      description = "Export wave data to file, returns true on success",
      returnType = "bool",
      params = {
        {type = "Wave", name = "wave"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "ExportWaveAsCode",
      description = "Export wave sample data to code (.h), returns true on success",
      returnType = "bool",
      params = {
        {type = "Wave", name = "wave"},
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "PlaySound",
      description = "Play a sound",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"}
      }
    },
    {
      name = "StopSound",
      description = "Stop playing a sound",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"}
      }
    },
    {
      name = "PauseSound",
      description = "Pause a sound",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"}
      }
    },
    {
      name = "ResumeSound",
      description = "Resume a paused sound",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"}
      }
    },
    {
      name = "IsSoundPlaying",
      description = "Check if a sound is currently playing",
      returnType = "bool",
      params = {
        {type = "Sound", name = "sound"}
      }
    },
    {
      name = "SetSoundVolume",
      description = "Set volume for a sound (1.0 is max level)",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"},
        {type = "float", name = "volume"}
      }
    },
    {
      name = "SetSoundPitch",
      description = "Set pitch for a sound (1.0 is base level)",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"},
        {type = "float", name = "pitch"}
      }
    },
    {
      name = "SetSoundPan",
      description = "Set pan for a sound (0.5 is center)",
      returnType = "void",
      params = {
        {type = "Sound", name = "sound"},
        {type = "float", name = "pan"}
      }
    },
    {
      name = "WaveCopy",
      description = "Copy a wave to a new wave",
      returnType = "Wave",
      params = {
        {type = "Wave", name = "wave"}
      }
    },
    {
      name = "WaveCrop",
      description = "Crop a wave to defined frames range",
      returnType = "void",
      params = {
        {type = "Wave *", name = "wave"},
        {type = "int", name = "initFrame"},
        {type = "int", name = "finalFrame"}
      }
    },
    {
      name = "WaveFormat",
      description = "Convert wave data to desired format",
      returnType = "void",
      params = {
        {type = "Wave *", name = "wave"},
        {type = "int", name = "sampleRate"},
        {type = "int", name = "sampleSize"},
        {type = "int", name = "channels"}
      }
    },
    {
      name = "LoadWaveSamples",
      description = "Load samples data from wave as a 32bit float data array",
      returnType = "float *",
      params = {
        {type = "Wave", name = "wave"}
      }
    },
    {
      name = "UnloadWaveSamples",
      description = "Unload samples data loaded with LoadWaveSamples()",
      returnType = "void",
      params = {
        {type = "float *", name = "samples"}
      }
    },
    {
      name = "LoadMusicStream",
      description = "Load music stream from file",
      returnType = "Music",
      params = {
        {type = "const char *", name = "fileName"}
      }
    },
    {
      name = "LoadMusicStreamFromMemory",
      description = "Load music stream from data",
      returnType = "Music",
      params = {
        {type = "const char *", name = "fileType"},
        {type = "const unsigned char *", name = "data"},
        {type = "int", name = "dataSize"}
      }
    },
    {
      name = "IsMusicReady",
      description = "Checks if a music stream is ready",
      returnType = "bool",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "UnloadMusicStream",
      description = "Unload music stream",
      returnType = "void",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "PlayMusicStream",
      description = "Start music playing",
      returnType = "void",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "IsMusicStreamPlaying",
      description = "Check if music is playing",
      returnType = "bool",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "UpdateMusicStream",
      description = "Updates buffers for music streaming",
      returnType = "void",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "StopMusicStream",
      description = "Stop music playing",
      returnType = "void",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "PauseMusicStream",
      description = "Pause music playing",
      returnType = "void",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "ResumeMusicStream",
      description = "Resume playing paused music",
      returnType = "void",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "SeekMusicStream",
      description = "Seek music to a position (in seconds)",
      returnType = "void",
      params = {
        {type = "Music", name = "music"},
        {type = "float", name = "position"}
      }
    },
    {
      name = "SetMusicVolume",
      description = "Set volume for music (1.0 is max level)",
      returnType = "void",
      params = {
        {type = "Music", name = "music"},
        {type = "float", name = "volume"}
      }
    },
    {
      name = "SetMusicPitch",
      description = "Set pitch for a music (1.0 is base level)",
      returnType = "void",
      params = {
        {type = "Music", name = "music"},
        {type = "float", name = "pitch"}
      }
    },
    {
      name = "SetMusicPan",
      description = "Set pan for a music (0.5 is center)",
      returnType = "void",
      params = {
        {type = "Music", name = "music"},
        {type = "float", name = "pan"}
      }
    },
    {
      name = "GetMusicTimeLength",
      description = "Get music time length (in seconds)",
      returnType = "float",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "GetMusicTimePlayed",
      description = "Get current music time played (in seconds)",
      returnType = "float",
      params = {
        {type = "Music", name = "music"}
      }
    },
    {
      name = "LoadAudioStream",
      description = "Load audio stream (to stream raw audio pcm data)",
      returnType = "AudioStream",
      params = {
        {type = "unsigned int", name = "sampleRate"},
        {type = "unsigned int", name = "sampleSize"},
        {type = "unsigned int", name = "channels"}
      }
    },
    {
      name = "IsAudioStreamReady",
      description = "Checks if an audio stream is ready",
      returnType = "bool",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "UnloadAudioStream",
      description = "Unload audio stream and free memory",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "UpdateAudioStream",
      description = "Update audio stream buffers with data",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"},
        {type = "const void *", name = "data"},
        {type = "int", name = "frameCount"}
      }
    },
    {
      name = "IsAudioStreamProcessed",
      description = "Check if any audio stream buffers requires refill",
      returnType = "bool",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "PlayAudioStream",
      description = "Play audio stream",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "PauseAudioStream",
      description = "Pause audio stream",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "ResumeAudioStream",
      description = "Resume audio stream",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "IsAudioStreamPlaying",
      description = "Check if audio stream is playing",
      returnType = "bool",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "StopAudioStream",
      description = "Stop audio stream",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"}
      }
    },
    {
      name = "SetAudioStreamVolume",
      description = "Set volume for audio stream (1.0 is max level)",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"},
        {type = "float", name = "volume"}
      }
    },
    {
      name = "SetAudioStreamPitch",
      description = "Set pitch for audio stream (1.0 is base level)",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"},
        {type = "float", name = "pitch"}
      }
    },
    {
      name = "SetAudioStreamPan",
      description = "Set pan for audio stream (0.5 is centered)",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"},
        {type = "float", name = "pan"}
      }
    },
    {
      name = "SetAudioStreamBufferSizeDefault",
      description = "Default size for new audio streams",
      returnType = "void",
      params = {
        {type = "int", name = "size"}
      }
    },
    {
      name = "SetAudioStreamCallback",
      description = "Audio thread callback to request new data",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"},
        {type = "AudioCallback", name = "callback"}
      }
    },
    {
      name = "AttachAudioStreamProcessor",
      description = "Attach audio stream processor to stream, receives the samples as 'float'",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"},
        {type = "AudioCallback", name = "processor"}
      }
    },
    {
      name = "DetachAudioStreamProcessor",
      description = "Detach audio stream processor from stream",
      returnType = "void",
      params = {
        {type = "AudioStream", name = "stream"},
        {type = "AudioCallback", name = "processor"}
      }
    },
    {
      name = "AttachAudioMixedProcessor",
      description = "Attach audio stream processor to the entire audio pipeline, receives the samples as 'float'",
      returnType = "void",
      params = {
        {type = "AudioCallback", name = "processor"}
      }
    },
    {
      name = "DetachAudioMixedProcessor",
      description = "Detach audio stream processor from the entire audio pipeline",
      returnType = "void",
      params = {
        {type = "AudioCallback", name = "processor"}
      }
    }
  }
}
