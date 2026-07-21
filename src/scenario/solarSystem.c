#include "physics/body.h"
#include "utils/bodyVector.h"
#include <raylib.h>

void solar_system_init(BodyVector *bodies) {
  Body sun =
      body_create("Sun", (Vector3){0}, (Vector3){0}, 1000.0f, 8.0f, GOLD);
  vector_add(bodies, sun);

  struct {
    const char *name;
    float distance;
    float mass;
    float orbital_speed;
    float visual_radius;
    Color color;
  } bodies_data[] = {
      {"Mercury", 11.58f, 0.000166f, 0.8184f, 0.5f, GRAY},
      {"Venus", 21.64f, 0.002447f, 0.6052f, 0.8f, ORANGE},
      {"Earth", 29.92f, 0.003003f, 0.5146f, 0.9f, BLUE},
      {"Mars", 45.59f, 0.000323f, 0.4159f, 0.6f, RED},
      {"Ceres", 82.80f, 0.000000472f, 0.3093f, 0.3f, DARKGRAY},
      {"Jupiter", 155.71f, 0.9543f, 0.2259f, 2.5f, BEIGE},
      {"Saturn", 286.71f, 0.2857f, 0.1673f, 2.0f, LIGHTGRAY},
      {"Uranus", 574.49f, 0.04365f, 0.1175f, 1.5f, SKYBLUE},
      {"Neptune", 899.01f, 0.05149f, 0.0938f, 1.4f, DARKBLUE},
      {"Pluto", 1181.28f, 0.00000655f, 0.0819f, 0.3f, BROWN},
  };

  size_t count = sizeof(bodies_data) / sizeof(bodies_data[0]);
  for (size_t i = 0; i < count; i++) {
    Body body = body_create(bodies_data[i].name,
                            (Vector3){bodies_data[i].distance, 0.0f, 0.0f},
                            (Vector3){0}, bodies_data[i].mass,
                            bodies_data[i].visual_radius, bodies_data[i].color);
    body_orbit(&body, &sun, bodies_data[i].orbital_speed);
    vector_add(bodies, body);
  }
}
