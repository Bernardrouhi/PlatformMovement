#include "raylib.h"

int main()
{
    const int Window_H{512};
    const int Window_W{380};

    // initiate window
    InitWindow(Window_W,Window_H,"Platform Movement");
    
    // World Property
    const int gravity{1};

    // character size
    const int Char_W{50};
    const int Char_H{50};

    int Char_PosY{Window_H-Char_H};
    int Char_PosX{Window_W/2};
    int Char_Velocity{0};
    const int Char_JumpVelocity{-22};
    const int Char_Speed{10};

    bool isInAir{false};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
   
        ClearBackground(WHITE);

        if (Char_PosY >= Window_H - Char_H)
        {
            Char_Velocity = 0;
            isInAir = false;
        }
        else
        {
            // Apply gravity
            Char_Velocity += gravity;
            isInAir = true;
        }

        // Jump
        if(IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            // add Velocity
            Char_Velocity += Char_JumpVelocity;
        }

        // Movement
        if(IsKeyDown(KEY_A))
        {
            if(Char_PosX > 0)
            {
                Char_PosX -= Char_Speed;
            }
            else
            {
                Char_PosX = 0;
            }
        }
        if(IsKeyDown(KEY_D))
        {
            if (Char_PosX < Window_W-Char_W)
            {
                Char_PosX += Char_Speed;
            }
            else
            {
                Char_PosX = Window_W-Char_W;
            }
        }

        // update character position
        Char_PosY += Char_Velocity;

        DrawRectangle(Char_PosX,Char_PosY, Char_W, Char_H, SKYBLUE);

        EndDrawing();
    }

    // Close window
    CloseWindow();
}