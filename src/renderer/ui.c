#include "ui.h"
#include <raylib.h>

void PrintBodyData(Font font, Body body) {
  DrawTextEx(font, TextFormat("Body ID: %i", body.id), (Vector2){10, 10}, 20,
             0.0f, WHITE);

  DrawTextEx(font, TextFormat("Mass: %.2f", body.mass), (Vector2){10, 30}, 20,
             0.0f, WHITE);
  DrawTextEx(font, TextFormat("Radius: %.2f", body.radius), (Vector2){10, 50},
             20, 0.0f, WHITE);
  DrawTextEx(font,
             TextFormat("Position: (%.2f, %.2f, %.2f)", body.position.x,
                        body.position.y, body.position.z),
             (Vector2){10, 70}, 20, 0.0f, WHITE);
  DrawTextEx(font,
             TextFormat("Acceleration: (%.2f, %.2f, %.2f)", body.acceleration.x,
                        body.acceleration.y, body.acceleration.z),
             (Vector2){10, 90}, 20, 0.0f, WHITE);
  DrawTextEx(font,
             TextFormat("Velocity: (%.2f, %.2f, %.2f)", body.velocity.x,
                        body.velocity.y, body.velocity.z),
             (Vector2){10, 110}, 20, 0.0f, WHITE);
}
