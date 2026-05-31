#include "raylib.h"

typedef struct Body {
  Vector3 position;
  Vector3 velocity;
  Vector3 acceleration;

  float mass;
  float radius;

  Color color;
  bool isActive;
} Body;
