/*******************************************************************************************
*
*   raylib [models] example - Mesh picking in 3d mode, ground plane, triangle, mesh
*
*   This example has been created using raylib 1.7 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Joel Davis (@joeld42) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2017 Joel Davis (@joeld42) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"

#define FLT_MAX     340282346638528859811704183484516925440.0f     // Maximum value of a float, from bit pattern 01111111011111111111111111111111

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - mesh picking");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 20.0f, 20.0f, 20.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 8.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.6f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;                   // Camera mode type

    Ray ray = { 0 };        // Picking ray

    Model tower = LoadModel("resources/models/turret.obj");                 // Load OBJ model
    Texture2D texture = LoadTexture("resources/models/turret_diffuse.png"); // Load model texture
    tower.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;                 // Set model diffuse texture

    Vector3 towerPos = { 0.0f, 0.0f, 0.0f };                    // Set model position
    BoundingBox towerBBox = GetMeshBoundingBox(tower.meshes[0]);   // Get mesh bounding box

    // Test triangle
    Vector3 ta = (Vector3){ -25.0f, 0.5f, 0.0f };
    Vector3 tb = (Vector3){ -4.0f, 2.5f, 1.0f };
    Vector3 tc = (Vector3){ -8.0f, 6.5f, 0.0f };

    Vector3 bary = { 0.0f, 0.0f, 0.0f };

    // Test sphere
    Vector3 sp = (Vector3){ -30.0f, 5.0f, 5.0f };
    float sr = 4.0f;

    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);          // Update camera

        // Display information about closest hit
        RayCollisionInfo nearestHit = { 0 };
        char *hitObjectName = "None";
        nearestHit.distance = FLT_MAX;
        nearestHit.hit = false;
        Color cursorColor = WHITE;

        // Get ray and test against objects
        ray = GetMouseRay(GetMousePosition(), camera);

        // Check ray collision against ground plane
        /*RayCollisionInfo groundHitInfo = GetCollisionRayQuad(ray, 0.0f);

        if ((groundHitInfo.hit) && (groundHitInfo.distance < nearestHit.distance))
        {
            nearestHit = groundHitInfo;
            cursorColor = GREEN;
            hitObjectName = "Ground";
        }*/

        // Check ray collision against test triangle
        RayCollisionInfo triHitInfo = GetCollisionRayTriangle(ray, ta, tb, tc);

        if ((triHitInfo.hit) && (triHitInfo.distance < nearestHit.distance))
        {
            nearestHit = triHitInfo;
            cursorColor = ORANGE;
            hitObjectName = "Triangle";

            bary = Vector3Barycenter(nearestHit.position, ta, tb, tc);
        }
        
        // Check ray collision against test sphere
        RayCollisionInfo sphHitInfo = GetCollisionRaySphere(ray, sp, sr);
        
        if ((sphHitInfo.hit) && (sphHitInfo.distance < nearestHit.distance)) {
            nearestHit = sphHitInfo;
            cursorColor = ORANGE;
            hitObjectName = "Sphere";
        }

        // Check ray collision against bounding box first, before trying the full ray-mesh test
        // Note: distance becomes negative if ray.position is inside the box!
        RayCollisionInfo boxHitInfo = GetCollisionRayBox(ray, towerBBox);

        if ((boxHitInfo.hit) && (boxHitInfo.distance < nearestHit.distance))
        {
            nearestHit = boxHitInfo;
            cursorColor = PURPLE;
            hitObjectName = "Box";

            // Check ray collision against model
            // NOTE: It considers model.transform matrix!
            RayCollisionInfo meshHitInfo = GetCollisionRayModel(ray, tower);

            if (meshHitInfo.hit)
            {
                nearestHit = meshHitInfo;
                cursorColor = ORANGE;
                hitObjectName = "Mesh";
            }
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw the tower
                // WARNING: If scale is different than 1.0f,
                // not considered by GetCollisionRayModel()
                DrawModel(tower, towerPos, 1.0f, WHITE);

                // Draw the test triangle
                DrawLine3D(ta, tb, PURPLE);
                DrawLine3D(tb, tc, PURPLE);
                DrawLine3D(tc, ta, PURPLE);

                // Draw the test sphere
                DrawSphereWires(sp, sr, 8, 8, PURPLE);

                // Draw the mesh bbox if we hit it
                if (boxHitInfo.hit) DrawBoundingBox(towerBBox, LIME);

                // If we hit something, draw the cursor at the hit point
                if (nearestHit.hit)
                {
                    DrawCube(nearestHit.position, 0.3f, 0.3f, 0.3f, cursorColor);
                    DrawCubeWires(nearestHit.position, 0.3f, 0.3f, 0.3f, RED);

                    Vector3 normalEnd;
                    normalEnd.x = nearestHit.position.x + nearestHit.normal.x;
                    normalEnd.y = nearestHit.position.y + nearestHit.normal.y;
                    normalEnd.z = nearestHit.position.z + nearestHit.normal.z;

                    DrawLine3D(nearestHit.position, normalEnd, RED);
                }
                float scale = 10000;
                DrawLine3D(Vector3Add(ray.position, Vector3Scale(ray.direction, 10)), Vector3Add(ray.position, Vector3Scale(ray.direction, scale)), RED);
                Vector3 p1 = { 0, 0, 0 };
                Vector3 p2 = { 10, 10, 10 };
                DrawLine3D(ray.position, p1, RED);
                DrawRay(ray, MAROON); // TODO
                
                DrawGrid(10, 10.0f);

            EndMode3D();

            // Draw some debug GUI text
            DrawText(TextFormat("Hit Object: %s", hitObjectName), 10, 50, 10, BLACK);

            if (nearestHit.hit)
            {
                int ypos = 70;

                DrawText(TextFormat("Distance: %3.2f", nearestHit.distance), 10, ypos, 10, BLACK);
                if (nearestHit.distance < 0) DrawText("(Inside Box)", 100, ypos, 10, BLACK);

                DrawText(TextFormat("Hit Pos: %3.2f %3.2f %3.2f",
                                    nearestHit.position.x,
                                    nearestHit.position.y,
                                    nearestHit.position.z), 10, ypos + 15, 10, BLACK);

                DrawText(TextFormat("Hit Norm: %3.2f %3.2f %3.2f",
                                    nearestHit.normal.x,
                                    nearestHit.normal.y,
                                    nearestHit.normal.z), 10, ypos + 30, 10, BLACK);

                if (triHitInfo.hit) DrawText(TextFormat("Barycenter: %3.2f %3.2f %3.2f",  bary.x, bary.y, bary.z), 10, ypos + 45, 10, BLACK);
            }

            DrawText("Use Mouse to Move Camera", 10, 430, 10, GRAY);

            DrawText("(c) Turret 3D model by Alberto Cano", screenWidth - 200, screenHeight - 20, 10, GRAY);

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadModel(tower);         // Unload model
    UnloadTexture(texture);     // Unload texture

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}