#include <raylib.h>
#include "entities.h"

int starSpeed = 100;

void Star::move(float delTime) {
    x -= size * starSpeed * delTime;
}

void Star::drawRect() {
    DrawRectangle(x, y, size, size, WHITE);
}