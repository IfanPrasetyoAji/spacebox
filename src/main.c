#include "raylib.h"
#include "physics/gravity.h"
#include "renderer/renderer.h"
#include <stdbool.h>

void printBodyData(Body body);

int main(void) {
  const int screenWidth = 1600;
  const int screenHeight = 800;

  InitWindow(screenWidth, screenHeight, "Testing");

  SetTargetFPS(60);

  Body body1 = {1,
                {0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                15.0f,
                2.0f,
                SKYBLUE,
                true};

  Body body2 = {2,
                {20.0f, 20.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                10.0f,
                4.0f,
                RED,
                true};

  Body bodies[] = {body1, body2};

  Camera3D camera = {0};
  camera.position = (Vector3){5.0f, 5.0f, 5.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  DisableCursor();

  // Main game loop
  while (!WindowShouldClose()) {
    ClearBackground(BLACK);
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);

    BeginDrawing();
    BeginMode3D(camera);
    DrawBodies(bodies, 2);
    DrawGrid(500, 10.0f);
    EndMode3D();

    EndDrawing();
  }

  CloseWindow();
}

void printBodyData(Body body) {
  DrawText(TextFormat("Body ID: %i", body.id), 10, 10, 20, WHITE);
  DrawText(TextFormat("Mass: %.2f", body.mass), 10, 30, 20, WHITE);
  DrawText(TextFormat("Radius: %.2f", body.radius), 10, 50, 20, WHITE);
  DrawText(TextFormat("Position: (%.2f, %.2f, %.2f)", body.position.x,
                      body.position.y, body.position.z),
           10, 70, 20, WHITE);
  DrawText(TextFormat("Velocity: (%.2f, %.2f, %.2f)", body.velocity.x,
                      body.velocity.y, body.velocity.z),
           10, 90, 20, WHITE);
}
