#include "core/application.h"
#include "core/simulation.h"
#include "input/camera.h"
#include "raylib.h"
#include "renderer/renderer.h"
#include "renderer/ui.h"
#include "stdlib.h"

void app_run() {
  const int screenWidth = 1600;
  const int screenHeight = 800;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(screenWidth, screenHeight, "SpaceBox");

  SetTargetFPS(60);

  Simulation *sim = malloc(sizeof(Simulation));
  CameraController cc;
  UIController ui;

  simulation_init(sim);
  camera_init(&cc);
  ui_init(&ui);

  // Main game loop
  while (!WindowShouldClose()) {
    float dt = GetFrameTime();
    simulation_update(sim, dt);
    camera_update(&cc);

    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode3D(get_camera(&cc));

    draw_bodies(sim->bodies, sim->bodies.count);
    DrawGrid(500, 10.0f);

    EndMode3D();

    EndDrawing();
  }

  CloseWindow();
  ui_shutdown(&ui);

  free(sim);
}
