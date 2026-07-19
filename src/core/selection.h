#pragma once

#include "raylib.h"
#include "utils/bodyVector.h"

unsigned int selection_pick_body(BodyVector *bodies, Camera camera,
                                 Vector2 mousePosition);
