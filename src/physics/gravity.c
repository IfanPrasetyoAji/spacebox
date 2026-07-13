#include "gravity.h"
#include <raymath.h>

Vector3 calculateGravitationalForce(Body body1, Body body2) {
  const float G = 1.0f;

  Vector3 direction = Vector3Subtract(body2.position, body1.position);
  float distanceSquared = Vector3LengthSqr(direction);

  if (distanceSquared <= 0.0000001f) {
    return Vector3Zero();
  }

  float forceManitude = (G * body1.mass * body2.mass) / distanceSquared;
  return Vector3Scale(Vector3Normalize(direction), forceManitude);
}

void resetAcceleration(Body bodies[], int count) {
  for (int i = 0; i < count; i++) {
    bodies[i].acceleration = Vector3Zero();
  }
}

void applyGravity(Body bodies[], int count) {
  for (int i = 0; i < count; i++) {
    if (!bodies[i].isActive || bodies[i].mass == 0.0f)
      continue;

    for (int j = i + 1; j < count; j++) {
      if (!bodies[j].isActive || bodies[j].mass == 0.0f)
        continue;

      Vector3 forceThatBe = calculateGravitationalForce(bodies[i], bodies[j]);

      bodies[i].acceleration = Vector3Scale(forceThatBe, 1.0f / bodies[i].mass);
      bodies[j].acceleration = Vector3Scale(forceThatBe, 1.0f / bodies[j].mass);
    }
  }
}
