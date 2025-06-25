#pragma once
#include "EnemyBullet.h"
#include <vector>

class EnemyBulletPool {
private:
    std::vector<EnemyBullet> bullets;

public:
    EnemyBulletPool(int initialSize = 50);
    EnemyBullet* getBullet();
    void update();
    void draw() const;
    std::vector<EnemyBullet>& getBullets();
};
