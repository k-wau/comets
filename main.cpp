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

int main() {

    GameState state = RUNNING;
    Star starArray[starArraySize];
    int starIndex = 0;

    InitWindow(600, 400, "swag???");
    SetTargetFPS(120);

    while(!WindowShouldClose()) {

        if (state == RUNNING) {
            
        }

        if (rand() % 120 == 0) {
            starArray[starIndex].x = GetScreenWidth();
            starArray[starIndex].y = rand() % GetScreenHeight();
            starArray[starIndex].size = (rand() % 4) + 3;
            starIndex++;
            if (starIndex == starArraySize) {
                starIndex = 0;
            }
        }

        for (int i = 0; i < starArraySize; i++) {
            starArray[i].move(GetFrameTime());
        }

        BeginDrawing();

            ClearBackground(BLACK);
            for (int i = 0; i < starArraySize; i++) {
                if (starArray[i].x > 0) {
                    starArray[i].drawRect();
                }
            }

        EndDrawing();
    }

    return 0;
}