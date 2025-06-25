#pragma once
#include "Color.h"
#include "BulletPool.h"

class Ship {
private:
    float x, y;
    float width, height;
    Color color;
    BulletPool* bulletPool;
    int health;
    int bulletCount;
    bool shieldActive;
    unsigned int shieldStartTime;

public:
    Ship(float x, float y, float width, float height, const Color& color, BulletPool* bulletPool);
    void draw() const;
    void moveLeft(float step);
    void moveRight(float step);
    void shoot();
    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    void takeDamage();
    int getHealth() const;
    void setBulletCount(int count);
    void heal(int amount);
    void activateShield();
    bool isShieldActive() const;
};
