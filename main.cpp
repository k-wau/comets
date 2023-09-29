#include <iostream>
#include <raylib.h>

int main() {
    std::cout << "yo" << std::endl;
    InitWindow(600, 400, "swag???");

    while(!WindowShouldClose()) {
        BeginDrawing();
        EndDrawing();
    }

    return 0;
}