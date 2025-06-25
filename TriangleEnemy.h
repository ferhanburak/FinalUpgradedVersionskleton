#pragma once
#include "Enemy.h"
#include "EnemyBulletPool.h"

class TriangleEnemy : public Enemy {
private:
    EnemyBulletPool* bulletPool;
    int fireCooldown;
    int fireTimer;
    bool dying;
    int animationFrame;
    float currentSize;
    float alpha;
    bool destroyed;

public:
    TriangleEnemy(float x, float y, float size, const Color& color, EnemyBulletPool* pool);
    void update() override;
    void draw() const override;
    bool isDestroyed() const override;
    bool checkCollision(float bulletX, float bulletY) override;
    void onHit() override;
};
