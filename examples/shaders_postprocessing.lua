-------------------------------------------------------------------------------------------
--
--  raylib [shaders] example - Apply a postprocessing shader to a scene
--
--  NOTE: This example requires raylib OpenGL 3.3 or ES2 versions for shaders support,
--        OpenGL 1.1 does not support shaders, recompile raylib to OpenGL 3.3 version.
--
--  NOTE: Shaders used in this example are #version 330 (OpenGL 3.3), to test this example
--        on OpenGL ES 2.0 platforms (Android, Raspberry Pi, HTML5), use #version 100 shaders
--        raylib comes with shaders ready for both versions, check raylib/shaders install folder
--
--  This example has been created using raylib 1.6 (www.raylib.com)
--  raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
--
--  Copyright (c) 2014-2016 Ramon Santamaria (@raysan5)
--
-------------------------------------------------------------------------------------------

-- Initialization
-------------------------------------------------------------------------------------------
local screenWidth = 800
local screenHeight = 450

SetConfigFlags(FLAG.MSAA_4X_HINT)      -- Enable Multi Sampling Anti Aliasing 4x (if available)

InitWindow(screenWidth, screenHeight, "raylib [shaders] example - postprocessing shader")

-- Define the camera to look into our 3d world
local camera = Camera(Vector3(3.0, 3.0, 3.0), Vector3(0.0, 1.5, 0.0), Vector3(0.0, 1.0, 0.0), 45.0)

local dwarf = LoadModel("resources/model/dwarf.obj")                   -- Load OBJ model
local texture = LoadTexture("resources/model/dwarf_diffuse.png")       -- Load model texture (diffuse map)
dwarf.material.texDiffuse = texture                                    -- Set dwarf model diffuse texture

local position = Vector3(0.0, 0.0, 0.0)                                -- Set model position

local shader = LoadShader("resources/shaders/glsl330/base.vs", 
                          "resources/shaders/glsl330/bloom.fs")        -- Load postpro shader

-- Create a RenderTexture2D to be used for render to texture
local target = LoadRenderTexture(screenWidth, screenHeight)

-- Setup orbital camera
SetCameraMode(CameraMode.ORBITAL)          -- Set an orbital camera mode
SetCameraPosition(camera.position)     -- Set internal camera position to match our camera position
SetCameraTarget(camera.target)         -- Set internal camera target to match our camera target

SetTargetFPS(60)                       -- Set our game to run at 60 frames-per-second
-------------------------------------------------------------------------------------------

-- Main game loop
while not WindowShouldClose() do       -- Detect window close button or ESC key
    -- Update
    ---------------------------------------------------------------------------------------
    camera = UpdateCamera(camera)      -- Update internal camera and our camera
    ---------------------------------------------------------------------------------------

    -- Draw
    ---------------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        BeginTextureMode(target)       -- Enable drawing to texture

            Begin3dMode(camera)

                DrawModel(dwarf, position, 2.0, WHITE)   -- Draw 3d model with texture

                DrawGrid(10, 1.0)      -- Draw a grid

            End3dMode()
      
            DrawText("HELLO POSTPROCESSING!", 70, 190, 50, RED)
            
        EndTextureMode()           -- End drawing to texture (now we have a texture available for next passes)
        
        BeginShaderMode(shader)
        
            -- NOTE: Render texture must be y-flipped due to default OpenGL coordinates (left-bottom)
            DrawTextureRec(target.texture, Rectangle(0, 0, target.texture.width, -target.texture.height), Vector2(0, 0), WHITE)
            
        EndShaderMode()
        
        DrawText("(c) Dwarf 3D model by David Moreno", screenWidth - 200, screenHeight - 20, 10, DARKGRAY)

        DrawFPS(10, 10)

    EndDrawing()
    ---------------------------------------------------------------------------------------
end

-- De-Initialization
-------------------------------------------------------------------------------------------
UnloadShader(shader)           -- Unload shader
UnloadTexture(texture)         -- Unload texture
UnloadModel(dwarf)             -- Unload model
UnloadRenderTexture(target)    -- Unload render texture

CloseWindow()                  -- Close window and OpenGL context
-------------------------------------------------------------------------------------------