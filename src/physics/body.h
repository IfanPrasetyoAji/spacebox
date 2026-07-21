#pragma once
#include "raylib.h"

typedef struct Body {
  unsigned int id;
  char name[64];

  Vector3 position;
  Vector3 velocity;
  Vector3 acceleration;

  float mass;
  float radius;

  Color color;
  bool isActive;
} Body;

Body body_create(const char *name, Vector3 position, Vector3 velocity,
                 float mass, float radius, Color color);
void body_orbit(Body *body1, Body *body2, float orbital_speed);
void body_orbit_auto(Body *body1, Body *body2);
