#include "Bullet.h"
#include <GL/glut.h>

Bullet::Bullet() : x(0), y(0), speed(10.0f), length(15.0f), animAlpha(1.0f), active(false) {}

void Bullet::activate(float startX, float startY) {
    x = startX;
    y = startY;
    animAlpha = 1.0f;
    active = true;
}

void Bullet::update() {
    if (!active) return;
    y += speed;
    animAlpha -= 0.03f;
    if (isOffScreen()) deactivate();
}

void Bullet::draw() const {
    if (!active) return;
    glColor4f(1.0f, 0.8f, 0.0f, animAlpha);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y + length);
    glEnd();
}

void Bullet::deactivate() { active = false; }
bool Bullet::isActive() const { return active; }
bool Bullet::isOffScreen() const { return y > 600; }
float Bullet::getX() const { return x; }
float Bullet::getY() const { return y; }
