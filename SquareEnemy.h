#pragma once
#include "Enemy.h"

class SquareEnemy : public Enemy {
public:
    SquareEnemy(float x, float y, float size, const Color& color);
    void update() override;
    void draw() const override;
    bool isDestroyed() const override;
    bool checkCollision(float bulletX, float bulletY) override;
    void onHit() override;

private:
    bool destroyed;
    bool dying;
    int animationFrame;
    float currentSize;
    float alpha;
};
