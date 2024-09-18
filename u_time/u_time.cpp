#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Shaders");

  Shader shader = LoadShader(0, "../shader.fs");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    float time = GetTime();
    SetShaderValue(shader, GetShaderLocation(shader, "u_time"), &time,
                   SHADER_UNIFORM_FLOAT);
    BeginDrawing();
    {
      ClearBackground(RAYWHITE);

      BeginShaderMode(shader);

      DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);

      EndShaderMode();
    }
    EndDrawing();
  }

  UnloadShader(shader);

  CloseWindow();

  return 0;
}
