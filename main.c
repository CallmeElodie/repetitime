#include "raylib.h"

int main(){

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Repetitime");

    // Colors

    Color colorBackground = GetColor(0xcbb99dFF);
    Color colorMiddleground1 = GetColor(0x8b6341FF);
    Color colorForeground1 = GetColor(0x4e2d18FF);

    Color colorMiddleground2 = GetColor(0x112921FF);
    Color colorForeground2 = GetColor(0x4d6443FF);


    Rectangle player = { 100, 100, 50, 50 };
    Rectangle ground = { 0, 400, 800, 50 };

    bool isGrounded;
    bool showText = true;
    const char* message = "Welcome to Repeti-time\n\np,Press any key to play";

    SetTargetFPS(60);

    while (!WindowShouldClose()){


        if (GetKeyPressed() != 0){
            showText = false;
        }

        if (!showText){

            player.y += 4;

            DrawRectangle(player.x, player.y, player.width, player.height, colorForeground2);
            DrawRectangle(ground.x, ground.y, ground.width, ground.height, colorMiddleground1);

            if (IsKeyDown(KEY_A)){
                player.x -= 4;
            }
            if (IsKeyDown(KEY_D)){
                player.x += 4;
            }

            if (CheckCollisionRecs(player, ground)){
                
                Rectangle overlap = GetCollisionRec(player, ground);
                
                player.y -= overlap.height; 
            
                isGrounded = true; 
            }
            else
            {
                isGrounded = false;
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