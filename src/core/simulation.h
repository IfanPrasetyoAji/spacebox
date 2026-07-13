#pragma once
#include "../physics/body.h"
#include "../physics/gravity.h"
#include "../physics/integrator.h"
#include "../renderer/renderer.h"
#include "../renderer/ui.h"
#include "camera.h"
#include "raylib.h"
#include <stdlib.h>

#define MAX_BODIES 1000000

typedef struct {
  Body bodies[MAX_BODIES];
  int bodyCount;
  float timeScale;

  Font regularFont;
} Simulation;

void SimulationInit(Simulation *sim);
void SimulationUpdate(Simulation *sim, float dt);
void SimulationDraw(Simulation *sim);
void SimulationShutdown(Simulation *sim);

bool _AddBody(Simulation *sim, Body body);
bool _LoadFont(Simulation *sim);
