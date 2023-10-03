#include <raylib.h>
#include "entities.h"

int starSpeed = 20;

Star::Star() {
    x = 0;
    y = 0;
    size = 0;
}

void Star::move(float delTime) {
    x -= (size * size - 8) * starSpeed * delTime;
}

void Star::drawRect() {
    DrawRectangle(x, y, size, size, WHITE);
}