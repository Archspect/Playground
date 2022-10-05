#include <raylib.h>

int main() {
  InitWindow(1000, 700, "Sandbox");
  SetWindowState(FLAG_WINDOW_RESIZABLE);
  SetExitKey(KEY_ESCAPE);

  // TODO: stop using absolute paths
  ChangeDirectory("/home/archspect/Code/raylib/Playground/");

 Camera camera = { 0 };
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
  Vector3 position = {0.0f, 0.0f, 0.0f};
  Model model = LoadModel("model.gltf");
  Texture2D texture = LoadTexture("steve.png");
  SetMaterialTexture(&model.materials[1], MATERIAL_MAP_DIFFUSE, texture);
      SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode
  while (!WindowShouldClose()) {
    UpdateCamera(&camera);
    BeginDrawing();
    ClearBackground({0, 0, 0, 255});
    BeginMode3D(camera);
    DrawModelEx(model, position, (Vector3){1.0f, 0.0f, 0.0f}, -90.0f,
                (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
    EndMode3D();
    EndDrawing();
  }
}
