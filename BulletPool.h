#pragma once
#include "Bullet.h"
#include <vector>

class BulletPool {
private:
    std::vector<Bullet> bullets;

public:
    BulletPool(int initialSize = 50);
    Bullet* getBullet();
    void update();
    void draw() const;
    std::vector<Bullet>& getBullets();
};
