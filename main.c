#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Repetitime");

    // Colors

    Color colorBackground = GetColor(0xcbb99dFF);
    Color colorMiddleground1 = GetColor(0x8b6341FF);
    Color colorForeground1 = GetColor(0x4e2d18FF);

    Color colorMiddleground2 = GetColor(0x112921FF);
    Color colorForeground2 = GetColor(0x4d6443FF);


    float playerPosX = 50;
    float playerPosY = 50;

    bool showText = true;
    const char* message = "Welcome to Repeti-time\n\nPress any key to play";

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(pondering);

        if (GetKeyPressed() != 0){
            showText = false;
        }

        if (!showText){


            DrawRectangle(playerPosX, playerPosY, 50, 50, colorForeground2);
            DrawRectangle(0, 400, 800, 50, colorMiddleground1);

            if (IsKeyDown(KEY_A)){
                playerPosX -= 4;
            }
            if (IsKeyDown(KEY_D)){
                playerPosX += 4;
            }
            if (playerPosY < 350) {
                playerPosY += 4;
            }
        }

        BeginDrawing();

        ClearBackground(colorBackground);

        if (showText){
            DrawText(message, (screenWidth/2) - (MeasureText(message, 20)/2) , (screenHeight/2) - (20/2), 20, colorForeground1);
        }

        EndDrawing();
    }


    CloseWindow();

    return 0;
}