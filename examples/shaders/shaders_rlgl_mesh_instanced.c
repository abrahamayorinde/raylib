/*******************************************************************************************
*
*   raylib [shaders] example - rlgl module usage for instanced meshes
*
*   This example uses [rlgl] module funtionality (pseudo-OpenGL 1.1 style coding)
*
*   This example has been created using raylib 3.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2018 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#define GRAPHICS_API_OPENGL_33
#define GLSL_VERSION 330

#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1024;
    const int screenHeight = 768;

    const float sunRadius = 4.0f;
    const float earthRadius = 0.6f;
    const float earthOrbitRadius = 8.0f;
    const float moonRadius = 0.16f;
    const float moonOrbitRadius = 1.5f;

    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable Multi Sampling Anti Aliasing 4x (if available)
    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - rlgl module usage for instanced meshes");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 125.0f, 125.0f, 125.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.type = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);

    const int count = 10000;                                 // Number of instances to display 
    Mesh cube = GenMeshCube(1.0f, 1.0f, 1.0f);

    Matrix* rotations = RL_MALLOC(count * sizeof(Matrix));    // Rotation state of instances
    Matrix* rotationsInc = RL_MALLOC(count * sizeof(Matrix)); // Per-frame rotation animation of instances
    Matrix* translations = RL_MALLOC(count * sizeof(Matrix)); // Locations of instances

    // Scatter random cubes around
    for (int i = 0; i < count; i++)
    {
        float x = GetRandomValue(-50, 50);
        float y = GetRandomValue(-50, 50);
        float z = GetRandomValue(-50, 50);
        translations[i] = MatrixTranslate(x, y, z); 

        x = GetRandomValue(0, 360);
        y = GetRandomValue(0, 360);
        z = GetRandomValue(0, 360);
        Vector3 axis = Vector3Normalize((Vector3){x, y, z});
        float angle = (float)GetRandomValue(0, 10) * DEG2RAD;

        rotationsInc[i] = MatrixRotate(axis, angle);

        rotations[i] = MatrixIdentity();
    }

    Matrix* transforms = RL_MALLOC(count * sizeof(Matrix));   // Pre-multiplied transformations passed to rlgl

    Shader shader = LoadShader(FormatText("resources/shaders/glsl%i/base_lighting_instanced.vs", GLSL_VERSION), 
                               FormatText("resources/shaders/glsl%i/lighting.fs", GLSL_VERSION));

    // Get some shader loactions
    shader.locs[LOC_MATRIX_MVP] = GetShaderLocation(shader, "mvp");
    shader.locs[LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    shader.locs[LOC_MATRIX_MODEL] = GetShaderLocationAttrib(shader, "instance");

    // ambient light level
    int ambientLoc = GetShaderLocation(shader, "ambient");
    SetShaderValue(shader, ambientLoc, (float[4]){ 0.2f, 0.2f, 0.2f, 1.0f }, UNIFORM_VEC4);

    CreateLight(LIGHT_DIRECTIONAL, (Vector3){ 50, 50, 0 }, Vector3Zero(), WHITE, shader);

    Material material = LoadMaterialDefault();
    material.shader = shader;
    material.maps[MAP_DIFFUSE].color = RED;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);

        // Update the light shader with the camera view position
        float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
        SetShaderValue(shader, shader.locs[LOC_VECTOR_VIEW], cameraPos, UNIFORM_VEC3);

        // Apply per-instance rotations
        for (int i = 0; i < count; i++)
        {
            rotations[i] = MatrixMultiply(rotations[i], rotationsInc[i]);
            transforms[i] = MatrixMultiply(rotations[i], translations[i]);
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                rlDrawMeshInstanced(cube, material, transforms, count);
            EndMode3D();

            DrawText("A CUBE OF DANCING CUBES!", 400, 10, 20, MAROON);
            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
