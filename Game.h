#pragma once
#include "Ship.h"
#include "BulletPool.h"
#include "EnemyBulletPool.h"
#include "Level.h"
#include "PowerUp.h"
#include <vector>

class Game {
private:
    std::vector<PowerUp*> powerUps;
    void maybeSpawnPowerUp(float x, float y);
private:
    Ship* ship;
    BulletPool bulletPool;
    EnemyBulletPool enemyBulletPool;
    Level level;
    bool isShooting;
    int fireCooldown;
    int fireTimer;
    bool isGameOver;

public:
    Game();
    void init();
    void update();
    void render();
    void setShooting(bool value);
    void handleKeyPress(int key, float step);
    void onTimer();
};
