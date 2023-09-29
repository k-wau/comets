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

    GameState state = MAINMENU;
    Star starArray[starArraySize];
    int starIndex = 0;

    InitWindow(600, 400, "swag???");

    while(!WindowShouldClose()) {

        if (state == RUNNING) {
            if ((int)GetTime() % 2 == 0) {
                starArray[starIndex].x = GetScreenWidth();
                starArray[starIndex].y = rand() % GetScreenHeight();
                starArray[starIndex].size = rand() % 7;
            }
        }

        for (int i = 0; i < starArraySize; i++) {
            starArray[i].move(GetFrameTime());
        }

        BeginDrawing();
            ClearBackground(BLACK);
            for (int i = 0; i < starArraySize; i++) {
                starArray[i].drawRect();
            }

        EndDrawing();
    }

    return 0;
}