-------------------------------------------------------------------------------------------
--
--  raylib [shaders] example - Apply a shader to some shape or texture
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

InitWindow(screenWidth, screenHeight, "raylib [shaders] example - shapes and texture shaders")

local sonic = LoadTexture("resources/texture_formats/sonic.png")

-- NOTE: Using GLSL 330 shader version, on OpenGL ES 2.0 use GLSL 100 shader version 
local shader = LoadShader("resources/shaders/glsl330/base.vs", 
                          "resources/shaders/glsl330/grayscale.fs")
                           
-- Shader usage is also different than models/postprocessing, shader is just activated when required

SetTargetFPS(60)                        -- Set our game to run at 60 frames-per-second
-------------------------------------------------------------------------------------------

-- Main game loop
while not WindowShouldClose() do        -- Detect window close button or ESC key
    -- Update
    ---------------------------------------------------------------------------------------
    -- TODO: Update your variables here
    ---------------------------------------------------------------------------------------

    -- Draw
    ---------------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)
        
        -- Start drawing with default shader

        DrawText("USING DEFAULT SHADER", 20, 40, 10, RED)
        
        DrawCircle(80, 120, 35, DARKBLUE)
        DrawCircleGradient(80, 220, 60, GREEN, SKYBLUE)
        DrawCircleLines(80, 340, 80, DARKBLUE)

        
        -- Activate our custom shader to be applied on next shapes/textures drawings
        BeginShaderMode(shader)
        
            DrawText("USING CUSTOM SHADER", 190, 40, 10, RED)

            DrawRectangle(250 - 60, 90, 120, 60, RED)
            DrawRectangleGradient(250 - 90, 170, 180, 130, MAROON, GOLD)
            DrawRectangleLines(250 - 40, 320, 80, 60, ORANGE)

        -- Activate our default shader for next drawings
        EndShaderMode()
        
        DrawText("USING DEFAULT SHADER", 370, 40, 10, RED)
        
        DrawTriangle(Vector2(430, 80),
                     Vector2(430 - 60, 150),
                     Vector2(430 + 60, 150), VIOLET)
                     
        DrawTriangleLines(Vector2(430, 160),
                          Vector2(430 - 20, 230),
                          Vector2(430 + 20, 230), DARKBLUE)

        DrawPoly(Vector2(430, 320), 6, 80, 0, BROWN)
        
        -- Activate our custom shader to be applied on next shapes/textures drawings
        BeginShaderMode(shader)

            DrawTexture(sonic, 380, -10, WHITE)    -- Using custom shader
        
        -- Activate our default shader for next drawings
        EndShaderMode()
        
    EndDrawing()
    ---------------------------------------------------------------------------------------
end

-- De-Initialization
-------------------------------------------------------------------------------------------
UnloadShader(shader)   -- Unload shader
UnloadTexture(sonic)   -- Unload texture

CloseWindow()          -- Close window and OpenGL context
-------------------------------------------------------------------------------------------