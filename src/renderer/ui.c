#include "ui.h"
#include <raylib.h>
#include <stdio.h>

void ui_init(UIController *ui) {
  ui->regularFont =
      LoadFontEx("assets/fonts/IoskeleyMono-Medium.ttf", 24, nullptr, 0);
  GenTextureMipmaps(&ui->regularFont.texture);
  SetTextureFilter(ui->regularFont.texture, TEXTURE_FILTER_BILINEAR);
}

void ui_draw_body_data(Font font, Body *body, Vector2 textScreenPos) {
  int fontSize = 20;
  char bodyDataText[7][128];

  snprintf(bodyDataText[6], sizeof(bodyDataText[6]), "Body ID\t: %d", body->id);
  snprintf(bodyDataText[5], sizeof(bodyDataText[5]), "Name\t: %s", body->name);
  snprintf(bodyDataText[4], sizeof(bodyDataText[4]), "Mass\t: %.2f",
           body->mass);
  snprintf(bodyDataText[3], sizeof(bodyDataText[3]), "Radius\t: %.2f",
           body->radius);
  snprintf(bodyDataText[2], sizeof(bodyDataText[2]),
           "Position\t: (%.2f, %.2f, %.2f)", body->position.x, body->position.y,
           body->position.z);
  snprintf(bodyDataText[1], sizeof(bodyDataText[1]),
           "Acceleration\t: (%.2f, %.2f, %.2f)", body->acceleration.x,
           body->acceleration.y, body->acceleration.z);
  snprintf(bodyDataText[0], sizeof(bodyDataText[0]),
           "Velocity\t: (%.2f, %.2f, %.2f)", body->velocity.x, body->velocity.y,
           body->velocity.z);

  int dataTextCount = sizeof(bodyDataText) / sizeof(bodyDataText[0]);

  for (int i = dataTextCount - 1; i >= 0; i--) {
    Vector2 textPos = {textScreenPos.x - 50.0f, textScreenPos.y - (i * 20.0f)};
    DrawTextEx(font, bodyDataText[i], textPos, fontSize, 1.0f, WHITE);
  }
}

void ui_shutdown(UIController *ui) { UnloadFont(ui->regularFont); }
