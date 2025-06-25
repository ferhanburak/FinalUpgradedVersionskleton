#include "TriangleEnemy.h"
#include <GL/glut.h>

TriangleEnemy::TriangleEnemy(float x, float y, float size, const Color& color, EnemyBulletPool* pool)
    : Enemy(x, y, size, color), bulletPool(pool), fireCooldown(120), fireTimer(0), dying(false),
      animationFrame(0), currentSize(size), alpha(1.0f), destroyed(false) {}

void TriangleEnemy::update() {
    if (dying) {
        animationFrame++;
        alpha -= 0.1f;
        currentSize -= 1.0f;
        if (animationFrame >= 10 || alpha <= 0.0f || currentSize <= 0.0f) {
            destroyed = true;
        }
    } else {
        if (--fireTimer <= 0) {
            EnemyBullet* bullet = bulletPool->getBullet();
            if (bullet) bullet->activate(x, y - size / 2);
            fireTimer = fireCooldown;
        }
    }
}

void TriangleEnemy::draw() const {
    if (destroyed) return;
    glColor4f(color.r, color.g, color.b, alpha);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + currentSize / 2);
    glVertex2f(x - currentSize / 2, y - currentSize / 2);
    glVertex2f(x + currentSize / 2, y - currentSize / 2);
    glEnd();
}

bool TriangleEnemy::isDestroyed() const { return destroyed; }

bool TriangleEnemy::checkCollision(float bulletX, float bulletY) {
    return bulletX > x - size / 2 && bulletX < x + size / 2 &&
           bulletY > y - size / 2 && bulletY < y + size / 2;
}

void TriangleEnemy::onHit() {
    if (!dying) {
        dying = true;
        animationFrame = 0;
    }
}
