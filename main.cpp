#include "raylib.h"

int main()
{
    const int Window_H{512};
    const int Window_W{380};

    // initiate window
    InitWindow(Window_W,Window_H,"Platform Movement");

    // character size
    const int Char_W{50};
    const int Char_H{80};

    int Char_PosY{Window_H-Char_H};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
   
        ClearBackground(WHITE);

        DrawRectangle(Window_W/2,Char_PosY, Char_W, Char_H, SKYBLUE);

        EndDrawing();
    }

    // Close window
    CloseWindow();
}