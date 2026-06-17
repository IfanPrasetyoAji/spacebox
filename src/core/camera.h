#pragma once
#include "raylib.h"

typedef struct {
  Camera3D cam;

  Vector3 movement;
  Vector3 rotation;
  float zoom;

  float movementSpeed;
  float rotationSpeed;
  float zoomMultiplier;

  Vector2 lastCursorLocation;
} CameraController;

void CameraInit(CameraController *cc);
void CameraUpdate(CameraController *cc);
Camera3D GetCamera(CameraController *cc);
void PrintCameraData(CameraController *cc);

void _HandleCameraMovement(CameraController *cc);
void _HandleCameraRotation(CameraController *cc);
void _HandleCameraZoom(CameraController *cc);
