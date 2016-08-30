-------------------------------------------------------------------------------------------
--
--  raylib [textures] example - Image loading and texture creation
--
--  NOTE: Images are loaded in CPU memory (RAM) textures are loaded in GPU memory (VRAM)
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

InitWindow(screenWidth, screenHeight, "raylib [textures] example - image loading")

-- NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

local image = LoadImage("resources/raylib_logo.png")  -- Loaded in CPU memory (RAM)
local texture = LoadTextureFromImage(image)           -- Image converted to texture, GPU memory (VRAM)

UnloadImage(image)   -- Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
-------------------------------------------------------------------------------------------

-- Main game loop
while not WindowShouldClose() do            -- Detect window close button or ESC key
    -- Update
    ---------------------------------------------------------------------------------------
    -- TODO: Update your variables here
    ---------------------------------------------------------------------------------------

    -- Draw
    ---------------------------------------------------------------------------------------
    BeginDrawing()

        ClearBackground(RAYWHITE)

        DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE)

        DrawText("this IS a texture loaded from an image!", 300, 370, 10, GRAY)

    EndDrawing()
    ---------------------------------------------------------------------------------------
end

-- De-Initialization
-------------------------------------------------------------------------------------------
UnloadTexture(texture)       -- Texture unloading

CloseWindow()                -- Close window and OpenGL context
-------------------------------------------------------------------------------------------