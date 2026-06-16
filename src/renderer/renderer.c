#include "renderer.h"
#include "raylib.h"

void DrawBodies(Body bodies[], int count) {
  for (int i = 0; i < count; i++) {
    DrawSphere(bodies[i].position, bodies[i].radius, bodies[i].color);
  }
}
