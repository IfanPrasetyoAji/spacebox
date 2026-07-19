#include "selection.h"

unsigned int selection_pick_body(BodyVector *bodies, Camera camera,
                                 Vector2 mousePosition) {
  Ray ray = GetMouseRay(mousePosition, camera);

  for (size_t i = 0; i < bodies->count; i++) {
    Body body = bodies->data[i];
    RayCollision collision =
        GetRayCollisionSphere(ray, body.position, body.radius);

    if (collision.hit) {
      return body.id;
    }
  }

  return 0; // Placeholder implementation
}
