#pragma once
#include "Enemy.h"
#include "SquareEnemy.h"
#include "TriangleEnemy.h"
#include "EnemyBulletPool.h"
#include <vector>
#include <memory>

class Level {
private:
    std::vector<std::unique_ptr<Enemy>> enemies;
    float enemySpeed;
    EnemyBulletPool* bulletPool;

public:
    Level();
    void setEnemyBulletPool(EnemyBulletPool* pool);
    void spawnEnemies();
    void update();
    void draw() const;
    std::vector<std::unique_ptr<Enemy>>& getEnemies();
};
