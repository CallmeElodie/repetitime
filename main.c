#include "raylib.h"

int main(){
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Repetitime");
    
    // colors
    Color colorBackground = GetColor(0xcbb99dFF);
    Color colorMiddleground1 = GetColor(0x8b6341FF);
    Color colorForeground1 = GetColor(0x4e2d18FF);
    Color colorMiddleground2 = GetColor(0x112921FF);
    Color colorForeground2 = GetColor(0x4d6443FF);
    
    typedef struct MovableRectangle {
        Rectangle rect;
        Vector2 velocity;
    } MovableRectangle;
    
    MovableRectangle player = { { 100, 100, 50, 50 }, { 0, 0 } };
    Rectangle ground = { 0, 400, 800, 50 };
    
    const float JUMP_VELOCITY = -11.0f;
    const float GRAVITY = 0.5f;
    
    bool isGrounded = false;
    bool showText = true;
    const char* message = "Welcome to Repeti-time\n\nPress any key to play\nA/D to move, SPACE to jump";
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()){
        if (GetKeyPressed() != 0){
            showText = false;
        }
        
        if (!showText){

            if (IsKeyDown(KEY_A)){
                player.rect.x -= 4;
            }
            if (IsKeyDown(KEY_D)){
                player.rect.x += 4;
            }
            
            if (IsKeyPressed(KEY_SPACE) && isGrounded){
                player.velocity.y = JUMP_VELOCITY;
            }
            
            // gravity
            player.velocity.y += GRAVITY;
            
            // Apply velocity to position
            player.rect.y += player.velocity.y;
            
            // collision
            if (CheckCollisionRecs(player.rect, ground)){
                Rectangle overlap = GetCollisionRec(player.rect, ground);
                player.rect.y -= overlap.height;
                player.velocity.y = 0;
                isGrounded = true;
            }
            else {
                isGrounded = false;
            }
        }
        
        BeginDrawing();
        ClearBackground(colorBackground);
        
        if (showText){
            DrawText(message, (screenWidth/2) - (MeasureText(message, 20)/2), (screenHeight/2) - (20/2), 20, colorForeground1);
        }
        else {
            DrawRectangle(player.rect.x, player.rect.y, player.rect.width, player.rect.height, colorForeground2);
            DrawRectangle(ground.x, ground.y, ground.width, ground.height, colorMiddleground1);
        }
        
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}