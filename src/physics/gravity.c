#include "gravity.h"
#include "raymath.h"

Vector3 calculateGravitationalForce(Body body1, Body body2) {
  Vector3 force = {0.0f, 0.0f, 0.0f};

  Vector3 direction = Vector3Subtract(body1.position, body2.position);

  float distance = Vector3Distance(body1.position, body2.position);

  if (distance == 0.0f) {
    return force;
  }

  const double G = 6.6743e-11;

  double forceMultiplier =
      G * ((body1.mass * body2.mass) / (distance * distance));

  Vector3 unitVector = {direction.x / distance, direction.y / distance,
                        direction.z / distance};

  force = Vector3Scale(unitVector, forceMultiplier);

  return force;
}

void resetAcceleration(Body bodies[], int count) {
  for (int i = 0; i < count; i++) {
    bodies[i].acceleration = Vector3Zero();
  }
}

void applyGravity(Body bodies[], int count) {
  for (int i = 0; i < count; i++) {
    for (int j = i + 1; j < count; j++) {
      Vector3 forceThatBe = calculateGravitationalForce(bodies[i], bodies[j]);

      // Apply the force that be to both bodies
      bodies[i].acceleration = Vector3Add(bodies[i].acceleration, forceThatBe);
      bodies[j].acceleration =
          Vector3Subtract(bodies[j].acceleration, forceThatBe);
    }
  }
}
