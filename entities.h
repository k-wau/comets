#include <raylib.h>

class Star {
    public:
        int x;
        int y;
        int size;

        void move(float delTime);
        void drawRect();
        Star();
};