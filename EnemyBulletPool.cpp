#include "EnemyBulletPool.h"

EnemyBulletPool::EnemyBulletPool(int initialSize) {
    bullets.resize(initialSize);
}

EnemyBullet* EnemyBulletPool::getBullet() {
    for (EnemyBullet& bullet : bullets) {
        if (!bullet.isActive()) return &bullet;
    }
    return nullptr;
}

void EnemyBulletPool::update() {
    for (EnemyBullet& bullet : bullets)
        if (bullet.isActive()) bullet.update();
}

void EnemyBulletPool::draw() const {
    for (const EnemyBullet& bullet : bullets)
        if (bullet.isActive()) bullet.draw();
}

std::vector<EnemyBullet>& EnemyBulletPool::getBullets() {
    return bullets;
}
