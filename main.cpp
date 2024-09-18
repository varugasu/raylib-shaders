#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Shaders");

  Shader shader = LoadShader(0, "../shader.fs");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    BeginShaderMode(shader);

    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);

    EndShaderMode();

    EndDrawing();
  }

  UnloadShader(shader);

  CloseWindow();

  return 0;
}
