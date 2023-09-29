#include <raylib.h>

class Entity {
    virtual void move(float delTime);
};

class Star : public Entity {
    public:
        float x;
        float y;
        float size;
        Rectangle rect;

        void move(float delTime);
        void drawRect();
};