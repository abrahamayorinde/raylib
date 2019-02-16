/*******************************************************************************************
 *
 *   raylib [core] example - Basic window
 *
 *   Welcome to raylib!
 *
 *   To test examples, just press F6 and execute raylib_compile_execute script
 *   Note that compiled executable is placed in the same folder as .c file
 *
 *   You can find all basic examples on C:\raylib\raylib\examples folder or
 *   raylib official webpage: www.raylib.com
 *
 *   Enjoy using raylib. :)
 *
 *   This example has been created using raylib 1.0 (www.raylib.com)
 *   raylib is licensed under an unmodified zlib/libpng license (View raylib.h
 *for details)
 *
 *   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h" 

int main()
{
	// Setup
	int screenWidth  = 800;
	int screenHeight = 450;
	InitWindow(
		screenWidth, screenHeight, "raylib [network] example - ping pong");
	SetTargetFPS(60);

	// Networking
	TCPSocket server;
	TCPSocket client;
	TCPSocket connection;
	ResetSocket(&server);
	ResetSocket(&client);
	ResetSocket(&connection);

	InitNetwork();
	CreateTCPListenServer(&server, "127.0.0.1", "3490");
	CreateTCPClient(&client, "127.0.0.1", "3490");

	// Timer
	float elapsed = 0.0f, delay = 1.0f; // ms
	bool  ping = false, pong = false;
	char  recvBuffer[512];
	memset(&recvBuffer, 0, 8);

	// Main game loop
	while (!WindowShouldClose()) {

		// Draw
		BeginDrawing();

		// Clear
		ClearBackground(RAYWHITE);

		// A valid connection will != -1
		if (!connection.ready) {
			AcceptIncomingConnections(&connection, server.sockfd);
			ping = true;
		}

		// Connected
		if (connection.ready) {

			int bytesRecv = ReceiveTCP(connection.sockfd, recvBuffer, 5);
			if (bytesRecv > 0) {
				if (strcmp(recvBuffer, "Ping!") == 0) {
					pong = true;
					printf("Ping!\n");
				}
				if (strcmp(recvBuffer, "Pong!") == 0) {
					ping = true;
					printf("Pong!\n");
				}
			}

			elapsed += GetFrameTime();
			if (elapsed > delay) {
				if (ping) {
					ping = false;
					SendTCP(client.sockfd, "Ping!", 5);
				} else if (pong) {
					pong = false;
					SendTCP(client.sockfd, "Pong!", 5);
				}
				elapsed = 0.0f;
			}
		}

		// End draw
		EndDrawing();
	}

	// Cleanup
	CloseWindow();
	return 0;
}