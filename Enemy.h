#pragma once
#include "Color.h"

class Enemy {
protected:
    float x, y;
    float size;
    Color color;

public:
    Enemy(float x, float y, float size, const Color& color)
        : x(x), y(y), size(size), color(color) {}
    virtual ~Enemy() = default;

    virtual void update() = 0;
    virtual void draw() const = 0;
    virtual bool isDestroyed() const = 0;
    virtual bool checkCollision(float bulletX, float bulletY) = 0;
    virtual void onHit() = 0;
};
