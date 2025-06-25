#include "EnemyBullet.h"
#include <GL/glut.h>

EnemyBullet::EnemyBullet() : x(0), y(0), speed(4.0f), length(10.0f), active(false) {}

void EnemyBullet::activate(float startX, float startY) {
    x = startX;
    y = startY;
    active = true;
}

void EnemyBullet::update() {
    if (!active) return;
    y -= speed;
    if (isOffScreen()) deactivate();
}

void EnemyBullet::draw() const {
    if (!active) return;
    glColor3f(1.0f, 0.2f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y - length);
    glEnd();
}

void EnemyBullet::deactivate() { active = false; }
bool EnemyBullet::isActive() const { return active; }
bool EnemyBullet::isOffScreen() const { return y < 0; }
float EnemyBullet::getX() const { return x; }
float EnemyBullet::getY() const { return y; }
