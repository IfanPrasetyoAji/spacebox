#pragma once
#include "utils/bodyVector.h"

typedef struct {
  BodyVector bodies;
  float timeMultiplier;
} Simulation;

void simulation_init(Simulation *sim);
void simulation_update(Simulation *sim, float dt);
bool simulation_add_body(Simulation *sim, Body body);
