#include <iostream>
#include <raylib.h>
#include <cstdlib>
#include <vector>

const int windowWidth = 1280;
const int windowHeight = 720;

int main() {
    InitWindow(windowWidth, windowHeight, "swag???");
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}