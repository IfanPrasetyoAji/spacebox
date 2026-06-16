#include "body.c"
#include "raylib.h"
#include <math.h>

Vector3 calculateGravitationalForce(Body body1, Body body2) {
  Vector3 force = {0.0f, 0.0f, 0.0f};

  Vector3 direction = {body2.position.x - body1.position.x,
                       body2.position.y - body1.position.y,
                       body2.position.z - body1.position.z};

  float distance = sqrt(direction.x * direction.x + direction.y * direction.y +
                        direction.z * direction.z);

  if (distance == 0.0f) {
    return force;
  }

  const double G = 6.6743e-11;

  double forceMultiplier =
      G * ((body1.mass * body2.mass) / (distance * distance));

  Vector3 unitVector = {direction.x / distance, direction.y / distance,
                        direction.z / distance};

  force.x = unitVector.x * forceMultiplier;
  force.y = unitVector.y * forceMultiplier;
  force.z = unitVector.z * forceMultiplier;

  return force;
}

void resetAcceleration(Body bodies[], int count) {
  for (int i = 0; i < count; i++) {
    bodies[i].acceleration = (Vector3){0.0f, 0.0f, 0.0f};
  }
}

void applyGravity(Body bodies[], int count) {
  for (int i = 0; i < count; i++) {
    for (int j = i + 1; j < count; j++) {
      Vector3 forceThatBe = calculateGravitationalForce(bodies[i], bodies[j]);

      // Apply the force that be to both bodies
      bodies[i].acceleration.x += forceThatBe.x;
      bodies[i].acceleration.y += forceThatBe.y;
      bodies[i].acceleration.z += forceThatBe.z;

      bodies[j].acceleration.x -= forceThatBe.x;
      bodies[j].acceleration.y -= forceThatBe.y;
      bodies[j].acceleration.z -= forceThatBe.z;
    }
  }
}
