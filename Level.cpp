#include "Level.h"

Level::Level() : enemySpeed(1.0f), bulletPool(nullptr) {
    spawnEnemies();
}

void Level::setEnemyBulletPool(EnemyBulletPool* pool) {
    bulletPool = pool;
}

void Level::spawnEnemies() {
    enemies.clear();
    for (int i = 0; i < 10; ++i) {
        float x = 60 + i * 70;
        float y = 500;
        if (i % 2 == 0)
            enemies.push_back(std::make_unique<SquareEnemy>(x, y, 30.0f, Color(1.0f, 0.0f, 0.0f)));
        else
            enemies.push_back(std::make_unique<TriangleEnemy>(x, y, 30.0f, Color(0.5f, 0.2f, 1.0f), bulletPool));
    }
}

void Level::update() {
    for (auto& enemy : enemies)
        enemy->update();

    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
                       [](const std::unique_ptr<Enemy>& e) { return e->isDestroyed(); }),
        enemies.end());
}

void Level::draw() const {
    for (const auto& enemy : enemies)
        enemy->draw();
}

std::vector<std::unique_ptr<Enemy>>& Level::getEnemies() {
    return enemies;
}
