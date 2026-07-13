#include "simulation.h"
#include "input/camera.h"
#include "physics/gravity.h"
#include "physics/integrator.h"
#include "renderer/renderer.h"
#include "renderer/ui.h"
#include <raylib.h>
#include <stdlib.h>

CameraController cc;

void SimulationInit(Simulation *sim) {
  sim->bodyCount = 0;

  Body body1 = {1,
                {-20.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 2.0f},
                {0.0f, 0.0f, 0.0f},
                15.0f,
                2.0f,
                SKYBLUE,
                true};

  Body body2 = {2,
                {20.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                10.0f,
                4.0f,
                RED,
                true};

  _AddBody(sim, body1);
  _AddBody(sim, body2);

  _LoadFont(sim);

  CameraInit(&cc);
}

void SimulationUpdate(Simulation *sim, float dt) {
  CameraUpdate(&cc);

  resetAcceleration(sim->bodies, sim->bodyCount);
  applyGravity(sim->bodies, sim->bodyCount);

  for (int i = 0; i < sim->bodyCount; i++) {
    SymplecticEuler(&sim->bodies[i], dt);
  }
}

void SimulationDraw(Simulation *sim) {
  BeginDrawing();

  ClearBackground(BLACK);

  BeginMode3D(GetCamera(&cc));

  DrawBodies(sim->bodies, sim->bodyCount);
  DrawGrid(500, 10.0f);

  EndMode3D();

  PrintBodyData(sim->regularFont, sim->bodies[0]);
  EndDrawing();
}

void SimulationShutdown(Simulation *sim) {
  UnloadFont(sim->regularFont);
  CloseWindow();
}

bool _AddBody(Simulation *sim, Body body) {
  if (sim->bodyCount >= MAX_BODIES) {
    return false;
  }

  sim->bodies[sim->bodyCount] = body;
  sim->bodyCount++;

  return true;
}

bool _LoadFont(Simulation *sim) {
  sim->regularFont =
      LoadFontEx("assets/fonts/IoskeleyMono-Medium.ttf", 24, NULL, 0);
  GenTextureMipmaps(&sim->regularFont.texture);
  SetTextureFilter(sim->regularFont.texture, TEXTURE_FILTER_BILINEAR);

  return IsFontValid(sim->regularFont);
}
