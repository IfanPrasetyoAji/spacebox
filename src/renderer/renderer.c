#include "renderer.h"
#include "raylib.h"
#include "utils/bodyVector.h"

void draw_bodies(BodyVector bodies, int count) {
  for (int i = 0; i < count; i++) {
    DrawSphere(bodies.data[i].position, bodies.data[i].radius,
               bodies.data[i].color);
  }
}
