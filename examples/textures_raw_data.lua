-------------------------------------------------------------------------------------------
--
--  raylib [textures] example - Load textures from raw data
--
--  NOTE: Images are loaded in CPU memory (RAM) textures are loaded in GPU memory (VRAM)
--
--  This example has been created using raylib 1.6 (www.raylib.com)
--  raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
--
--  Copyright (c) 2014-2016 Ramon Santamaria (@raysan5)
--
-------------------------------------------------------------------------------------------

--#include <stdlib.h>     -- Required for malloc() and free()

-- Initialization
-------------------------------------------------------------------------------------------
local screenWidth = 800
local screenHeight = 450

InitWindow(screenWidth, screenHeight, "raylib [textures] example - texture from raw data")

-- NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

-- Load RAW image data (512x512, 32bit RGBA, no file header)
local sonicRaw = LoadImageRaw("resources/texture_formats/sonic_R8G8B8A8.raw", 512, 512, TextureFormat.UNCOMPRESSED_R8G8B8A8, 0)
local sonic = LoadTextureFromImage(sonicRaw)   -- Upload CPU (RAM) image to GPU (VRAM)
UnloadImage(sonicRaw)                              -- Unload CPU (RAM) image data

-- Generate a checked texture by code (1024x1024 pixels)
local width = 1024
local height = 1024

-- Dynamic memory allocation to store pixels data (Color type)
local pixels = {}

for y = 1, height do
    for x = 1, width do
        if ((((x - 1)/32+(y - 1)//32)//1)%2 == 0) then pixels[(y - 1)*height + x] = DARKBLUE
        else pixels[(y - 1)*height + x] = SKYBLUE end
    end
end

-- Load pixels data into an image structure and create texture
local checkedIm = LoadImageEx(pixels, width, height)
local checked = LoadTextureFromImage(checkedIm)
UnloadImage(checkedIm)     -- Unload CPU (RAM) image data

-- Dynamic memory must be freed after using it
--free(pixels)               -- Unload CPU (RAM) pixels data
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

        DrawTexture(checked, screenWidth/2 - checked.width/2, screenHeight/2 - checked.height/2, Fade(WHITE, 0.3))
        DrawTexture(sonic, 330, -20, WHITE)

        DrawText("CHECKED TEXTURE ", 84, 100, 30, DARKBLUE)
        DrawText("GENERATED by CODE", 72, 164, 30, DARKBLUE)
        DrawText("and RAW IMAGE LOADING", 46, 226, 30, DARKBLUE)

    EndDrawing()
    ---------------------------------------------------------------------------------------
end

-- De-Initialization
-------------------------------------------------------------------------------------------
UnloadTexture(sonic)       -- Texture unloading
UnloadTexture(checked)     -- Texture unloading

CloseWindow()              -- Close window and OpenGL context
-------------------------------------------------------------------------------------------