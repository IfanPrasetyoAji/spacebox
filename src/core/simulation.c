#include "simulation.h"
#include "physics/gravity.h"
#include "physics/integrator.h"
#include "utils/bodyVector.h"
#include <raylib.h>
#include <stddef.h>

void simulation_init(Simulation *sim) {
  vector_init(&sim->bodies, 10);
  Body body1 = {1,
                "Earth",
                {-20.0f, 0.0f, 0.0f},
                {1.0f, 0.0f, 2.0f},
                {0.0f, 0.0f, 0.0f},
                15.0f,
                2.0f,
                SKYBLUE,
                true};

  Body body2 = {2,
                "Earth 2",
                {20.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                {0.0f, 0.0f, 0.0f},
                10.0f,
                4.0f,
                RED,
                true};

  vector_add(&sim->bodies, body1);
  vector_add(&sim->bodies, body2);
}

void simulation_update(Simulation *sim, float dt) {
  reset_acceleration(sim->bodies, sim->bodies.count);
  apply_gravity(sim->bodies, sim->bodies.count);

  for (size_t i = 0; i < sim->bodies.count; i++) {
    symplectic_euler(&sim->bodies.data[i], dt);
  }
}
