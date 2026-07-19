#pragma once
#include "utils/bodyVector.h"
#include <raylib.h>

void draw_bodies(BodyVector bodies, int count);
void draw_body_outline(Body *body, Color color);
