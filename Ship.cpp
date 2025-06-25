#include "Ship.h"
#include <GL/glut.h>

Ship::Ship(float x, float y, float width, float height, const Color& color, BulletPool* bulletPool) : bulletCount(1), shieldActive(false), shieldStartTime(0)
    : x(x), y(y), width(width), height(height), color(color), bulletPool(bulletPool), health(3) {}

void Ship::draw() const {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + height);
    glVertex2f(x - width / 2, y);
    glVertex2f(x + width / 2, y);
    glEnd();
}

void Ship::moveLeft(float step) {
    x -= step;
    if (x - width / 2 < 0) x = width / 2;
}

void Ship::moveRight(float step) {
    x += step;
    if (x + width / 2 > 800) x = 800 - width / 2;
}

void Ship::shoot() {
    Bullet* bullet = bulletPool->getBullet();
    if (bullet) {
        bullet->activate(x, y + height);
    }
}

float Ship::getX() const { return x; }
float Ship::getY() const { return y; }
float Ship::getWidth() const { return width; }
float Ship::getHeight() const { return height; }
void Ship::takeDamage() {
    if (isShieldActive()) return;
    health -= 10;
    if (health < 0) health = 0;
}
int Ship::getHealth() const { return health; }


void Ship::setBulletCount(int count) {
    bulletCount = count;
}

void Ship::heal(int amount) {
    health += amount;
    if (health > 100) health = 100;
}

void Ship::activateShield() {
    shieldActive = true;
    shieldStartTime = clock();
}

bool Ship::isShieldActive() const {
    return shieldActive && ((clock() - shieldStartTime) / (float)CLOCKS_PER_SEC < 10);
}
