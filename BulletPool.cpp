#include "BulletPool.h"

BulletPool::BulletPool(int initialSize) {
    bullets.resize(initialSize);
}

Bullet* BulletPool::getBullet() {
    for (Bullet& bullet : bullets) {
        if (!bullet.isActive()) return &bullet;
    }
    return nullptr;
}

void BulletPool::update() {
    for (Bullet& bullet : bullets)
        if (bullet.isActive()) bullet.update();
}

void BulletPool::draw() const {
    for (const Bullet& bullet : bullets)
        if (bullet.isActive()) bullet.draw();
}

std::vector<Bullet>& BulletPool::getBullets() {
    return bullets;
}
