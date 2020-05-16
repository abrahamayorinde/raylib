/*******************************************************************************************
*
*   raylib [models] example - Load 3d model with animations and play them
*
******************************************************************************
*
* To export a model from blender, make sure it is not posed, the vertices need to be in the 
* same position as they would be in edit mode.
* and that the scale of your models is set to 0. Scaling can be done from the export menu.
*   This example has been created using raylib 3.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Snowminx (@gamerfiend) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2020 Snowminx (@gamerfiend) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "raymath.h"

#define DEBUG_DRAW 1

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - model animation gltf");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.type = CAMERA_PERSPECTIVE;                   // Camera mode type

    Model model2 = LoadModel("resources/models/MonsterScaled.glb");
    Vector3 position = { 0.0f, 0.0f, 0.0f };            // Set model position

    // Load animation data
    int animsCount = 0;
    ModelAnimation *anims = LoadModelAnimations("resources/models/MonsterScaled.glb", &animsCount);
    int animFrameCounter = 0;
<<<<<<< HEAD
    //bool isValid = IsModelAnimationValid(model2, anims[0]);
    // if (!isValid) {
    //     printf("\n\n\n\nModel Bone Count: %i, Animation Bone Count: %i, Animation Count: %i\n\n\n\n", model2.boneCount, anims[2].boneCount, animsCount);
    // }
=======
    bool isValid = IsModelAnimationValid(model2, anims[2]);
    if (!isValid) {
        printf("\n\n\n\nModel Bone Count: %i, Animation Bone Count: %i, Animation Count: %i\n\n\n\n", model2.boneCount, anims[2].boneCount, animsCount);
    }

>>>>>>> 7b20e00596cfce39af3b9cb3503fe549575b25d8
    SetCameraMode(camera, CAMERA_FREE); // Set free camera mode

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);

        // Play animation when spacebar is held down
        if (IsKeyDown(KEY_SPACE))
        {
            //animFrameCounter++;
            //UpdateModelAnimation(model2, anims[0], animFrameCounter);
            //if (animFrameCounter >= anims[0].frameCount) animFrameCounter = 0;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
<<<<<<< HEAD

                DrawModelEx(model2, position, (Vector3){ 0.0f, 0.0f, 0.0f }, 0.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
=======
                DrawModelEx(model2, position, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
>>>>>>> 7b20e00596cfce39af3b9cb3503fe549575b25d8

                //Draw debug
                if(DEBUG_DRAW) 
                {
                    for (int i = 0; i < model2.boneCount; i++)
                    {
                        //DrawCube(anims[0].framePoses[animFrameCounter][i].translation, 0.2f, 0.2f, 0.2f, RED);
                        DrawCube(Vector3Negate(model2.bindPose[i].translation), 0.05f, 0.05f, 0.05f, RED);
                    }
                }
                


                DrawGrid(10, 1.0f);         // Draw a grid

            EndMode3D();
            DrawText("PRESS SPACE to PLAY GLTF MODEL ANIMATION", 10, 10, 20, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

   // Unload model animations data
    for (int i = 0; i < animsCount; i++) UnloadModelAnimation(anims[i]);
    RL_FREE(anims);

    UnloadModel(model2);         // Unload model

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
