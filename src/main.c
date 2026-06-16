#include "core/simulation.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
  const int screenWidth = 1600;
  const int screenHeight = 800;

  InitWindow(screenWidth, screenHeight, "N-Sim");

  SetTargetFPS(60);

  Simulation *sim = malloc(sizeof(Simulation));
  SimulationInit(sim);

  // Main game loop
  while (!WindowShouldClose()) {
    ClearBackground(BLACK);
    float dt = GetFrameTime();
    SimulationUpdate(sim, dt);
    SimulationDraw(sim);
  }

  SimulationShutdown(sim);
  free(sim);
}
