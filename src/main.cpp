#include <raylib.h>

int main() 
{
    InitWindow(1000, 700, "Sandbox");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetExitKey(KEY_ESCAPE);

    ChangeDirectory("/home/archspect/Code/Raylib/Playground/");

    Camera camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f}; 
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};      
    camera.up =
        (Vector3){0.0f, 1.0f, 0.0f}; 
    camera.fovy = 45.0f;             
    camera.projection = CAMERA_PERSPECTIVE;
    Vector3 position = {0.0f, 0.0f, 0.0f}; 
    Model model = LoadModel("model.gltf");
    Texture2D texture = LoadTexture("steve.png");
    SetMaterialTexture(&model.materials[0], MATERIAL_MAP_DIFFUSE, texture);

    while (!WindowShouldClose()) 
    {
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
