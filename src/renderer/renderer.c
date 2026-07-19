#include "renderer.h"
#include "rlgl.h"

void draw_bodies(BodyVector bodies, int count) {
  for (int i = 0; i < count; i++) {
    DrawSphere(bodies.data[i].position, bodies.data[i].radius,
               bodies.data[i].color);
  }
}

void draw_body_outline(Body *body, Color color) {
  rlDrawRenderBatchActive();
  rlSetCullFace(RL_CULL_FACE_FRONT);
  DrawSphere(body->position, body->radius * 1.1f, color);
  rlDrawRenderBatchActive();
  rlSetCullFace(RL_CULL_FACE_BACK);
}
