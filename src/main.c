#include "physics/body.h"
#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 800;

  InitWindow(screenWidth, screenHeight, "Testing");

  SetTargetFPS(60);

  Body body_test = {{0.0f, 0.0f, 0.0f},
                    {0.0f, 0.0f, 0.0f},
                    {0.0f, 0.0f, 0.0f},
                    15.0f,
                    10.0f,
                    SKYBLUE,
                    true};

  Camera3D camera = {0};
  camera.position = (Vector3){5.0f, 5.0f, 5.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  // Main game loop
  while (!WindowShouldClose()) {
    ClearBackground(BLACK);
    UpdateCamera(&camera, CAMERA_ORBITAL);

    BeginDrawing();
        BeginMode3D(camera);
            DrawSphere((Vector3)body_test.position, body_test.radius, body_test.color);
            DrawGrid(100, 1.0f);
        EndMode3D();
    EndDrawing();
  }

  CloseWindow();
}
