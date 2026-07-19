#pragma once
#include "physics/body.h"
#include <stdlib.h>

typedef struct {
  Body *data;
  size_t count;
  size_t capacity;
} BodyVector;

void vector_init(BodyVector *vec, size_t initial_capacity);
void vector_add(BodyVector *vec, Body body);
Body *vector_get_by_index(BodyVector *vec, size_t index);
Body *vector_get_by_id(BodyVector *vec, unsigned int id);
void vector_free(BodyVector *vec);
