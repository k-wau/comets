#include <iostream>
#include <raylib.h>
#include <cstdlib>
#include <vector>

#include "entities.h"

enum GameState {
    MAINMENU,
    RUNNING,
    DIALOGUE,
    PAUSED
};

const int starArraySize = 15;

const int windowWidth = 1280;
const int windowHeight = 720;

int main() {

    GameState state = RUNNING;
    InitWindow(windowWidth, windowHeight, "swag???");
    SetTargetFPS(120);

    // make star array pog
    Star starArray[starArraySize];
    int starIndex = 0;

    // initialize sprites
    Texture2D shipSprite = LoadTexture("sprites/ship.png");
    int playerX = 0;
    int playerY = 0;

    while(!WindowShouldClose()) {
        
        // fullscreen shortcut: f11
        // if (IsKeyPressed(KEY_F11)) {
        //     int display = GetCurrentMonitor();

        //     if (IsWindowFullscreen()) {
        //         ToggleFullscreen();
        //         SetWindowSize(windowWidth, windowHeight);
        //     } 
        //     else {
        //         SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        //         ToggleFullscreen();
        //     }
        // }





        // star generator //
        if (rand() % 100 == 0) {
            starArray[starIndex].x = GetScreenWidth();
            starArray[starIndex].y = rand() % GetScreenHeight();
            starArray[starIndex].size = (rand() % 4) + 3;
            starIndex++;
            if (starIndex == starArraySize) {
                starIndex = 0;
            }
        }

        // star mover //
        for (int i = 0; i < starArraySize; i++) {
            starArray[i].move(GetFrameTime());
        }

        if (IsKeyDown(KEY_S)) {
            playerY += 2;
        }
        if (IsKeyDown(KEY_W)) {
            playerY -= 2;
        }
        if (IsKeyDown(KEY_A)) {
            playerX -= 2;
        }
        if (IsKeyDown(KEY_D)) {
            playerX += 2;
        }

        // display block
        BeginDrawing();
            
            ClearBackground(BLACK);

            // star displayer //
            for (int i = 0; i < starArraySize; i++) {
                if (starArray[i].x > 0) {
                    starArray[i].drawRect();
                }
            }

            DrawTexture(shipSprite, playerX, playerY, WHITE);

        EndDrawing();
    }

    return 0;
}