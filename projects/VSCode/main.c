#include <math.h>
#include "raylib.h"

int main() {
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib");

	Camera cam;
	cam.position = (Vector3){ 0.f, 10.f, 8.f };
	cam.target = (Vector3){ 0.f, 0.f, 0.f };
	cam.up = (Vector3){ 0.f, 1.f, 0.f };
	cam.fovy = 60.f;
	cam.type = CAMERA_PERSPECTIVE;

	Vector3 cubePos = { 0.f, 0.f, 0.f };

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		cam.position.x = sin(GetTime()) * 10.f;
		cam.position.z = cos(GetTime()) * 10.f;

		BeginDrawing();
			ClearBackground(RL_RAYWHITE);
			BeginMode3D(cam);
				DrawCube(cubePos, 2.f, 2.f, 2.f, RL_RED);
				DrawCubeWires(cubePos, 2.f, 2.f, 2.f, RL_MAROON);
				DrawGrid(10, 1.f);
			EndMode3D();
			DrawText("This is a raylib example", 10, 40, 20, RL_DARKGRAY);
			DrawFPS(10, 10);
		EndDrawing();
	}
	
	CloseWindow();
	return 0;
}