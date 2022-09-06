#include "raylib.h"

int x = GetScreenWidth() / 2;
int y = GetScreenHeight() / 2;

void update()
{
    if(IsKeyDown(KEY_RIGHT))
    {
        x++;
    } 
    if (IsKeyDown(KEY_LEFT))
    {
        x--;
    }
    if (IsKeyDown(KEY_UP))
    {
        y--;
    }
    if (IsKeyDown(KEY_DOWN))
    {
        y++;
    }
}

void draw()
{
    DrawRectangle(x,y, 50, 50, { 245, 245, 245, 255 });
}

int main(void)
{
    InitWindow(1000, 700, "raylib");
    while (!WindowShouldClose())
    {
        update();
        BeginDrawing();
            ClearBackground(BLACK);
            draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}