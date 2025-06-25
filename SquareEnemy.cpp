#include "SquareEnemy.h"
#include <GL/glut.h>

SquareEnemy::SquareEnemy(float x, float y, float size, const Color& color)
    : Enemy(x, y, size, color), currentSize(size), alpha(1.0f), destroyed(false), dying(false), animationFrame(0) {}

void SquareEnemy::update() {
    if (dying) {
        animationFrame++;
        alpha -= 0.1f;
        currentSize -= 1.5f;
        if (animationFrame >= 10 || alpha <= 0.0f || currentSize <= 0.0f) {
            destroyed = true;
        }
    }
}

void SquareEnemy::draw() const {
    if (destroyed) return;
    glColor4f(color.r, color.g, color.b, alpha);
    glBegin(GL_QUADS);
    glVertex2f(x - currentSize / 2, y - currentSize / 2);
    glVertex2f(x + currentSize / 2, y - currentSize / 2);
    glVertex2f(x + currentSize / 2, y + currentSize / 2);
    glVertex2f(x - currentSize / 2, y + currentSize / 2);
    glEnd();
}

bool SquareEnemy::isDestroyed() const { return destroyed; }

bool SquareEnemy::checkCollision(float bulletX, float bulletY) {
    return bulletX > x - size / 2 && bulletX < x + size / 2 &&
           bulletY > y - size / 2 && bulletY < y + size / 2;
}

void SquareEnemy::onHit() {
    if (!dying) {
        dying = true;
        animationFrame = 0;
    }
}
