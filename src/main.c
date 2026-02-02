#include <raylib.h>

int main()
{
    InitWindow(320, 200, "Test Window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        
        ClearBackground(RAYWHITE);
        DrawText("Hello, world!", 160, 100, 20, LIGHTGRAY);
        
        EndDrawing();
    }

    CloseWindow();
}