#pragma once
#include "physics/body.h"
#include "raylib.h"

typedef struct {
  Font regularFont;
} UIController;

void ui_init(UIController *ui);
void ui_draw_body_data(Font font, Body *body, Vector2 bodyScreenPos);
void ui_shutdown(UIController *ui);
