#include "integrator.h"
#include "raymath.h"

void symplectic_euler(Body *body, float dt) {
  body->velocity =
      Vector3Add(body->velocity, Vector3Scale(body->acceleration, dt));
  body->position = Vector3Add(body->position, Vector3Scale(body->velocity, dt));
}
