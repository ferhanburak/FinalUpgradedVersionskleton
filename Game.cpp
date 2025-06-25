#include "Game.h"
#include <GL/glut.h>
#include <string>

Game::Game() : bulletPool(50), isShooting(false), fireCooldown(15), fireTimer(0), isGameOver(false), enemyBulletPool(50) {
    ship = new Ship(400.0f, 50.0f, 40.0f, 30.0f, Color(0.0f, 1.0f, 1.0f), &bulletPool);
}

void Game::init() {}

void Game::update() {
    if (isGameOver) return;

    if (isShooting && fireTimer <= 0) {
        ship->shoot();
        fireTimer = fireCooldown;
    }
    if (fireTimer > 0) --fireTimer;

    bulletPool.update();
    enemyBulletPool.update();
    level.update();
    for (auto* p : powerUps) p->update();

    // PowerUp toplama kontrolü
    for (auto it = powerUps.begin(); it != powerUps.end(); ) {
        PowerUp* p = *it;
        float dx = ship->getX() - p->getX();
        float dy = ship->getY() - p->getY();
        float distance = sqrt(dx*dx + dy*dy);

        if (distance < ship->getWidth() / 2 + p->getSize() / 2) {
            switch (p->getType()) {
                case PowerUpType::Upgrade: ship->setBulletCount(2); break;
                case PowerUpType::Health: ship->heal(25); break;
                case PowerUpType::Shield: ship->activateShield(); break;
            }
            delete p;
            it = powerUps.erase(it);
        } else {
            ++it;
        }
    }

    auto& bullets = bulletPool.getBullets();
    auto& enemies = level.getEnemies();

    for (Bullet& bullet : bullets) {
        if (!bullet.isActive()) continue;
        for (auto& enemy : enemies) {
            if (!enemy->isDestroyed() && enemy->checkCollision(bullet.getX(), bullet.getY())) {
                bullet.deactivate();
                enemy->onHit();
                maybeSpawnPowerUp(enemy->getX(), enemy->getY());
                break;
            }
        }
    }

    auto& enemyBullets = enemyBulletPool.getBullets();
    for (EnemyBullet& bullet : enemyBullets) {
        if (!bullet.isActive()) continue;

        float sx = ship->getX();
        float sy = ship->getY();
        float sw = ship->getWidth();
        float sh = ship->getHeight();

        float bx = bullet.getX();
        float by = bullet.getY();

        if (bx > sx - sw / 2 && bx < sx + sw / 2 &&
            by > sy && by < sy + sh) {
            bullet.deactivate();
            ship->takeDamage();
            if (ship->getHealth() <= 0) {
                isGameOver = true;
            }
        }
    }
}

void Game::render() {
    ship->draw();
    bulletPool.draw();
    enemyBulletPool.draw();
    level.draw();

    if (isGameOver) {
        glColor3f(1.0f, 0.0f, 0.0f);
        glRasterPos2f(350, 300);
        std::string msg = "GAME OVER";
        for (char c : msg) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

void Game::setShooting(bool value) {
    isShooting = value;
}

void Game::handleKeyPress(int key, float step) {
    if (key == GLUT_KEY_LEFT) ship->moveLeft(step);
    else if (key == GLUT_KEY_RIGHT) ship->moveRight(step);
}

void Game::onTimer() {
    update();
    glutPostRedisplay();
    glutTimerFunc(16, [](int value) {
        reinterpret_cast<Game*>(value)->onTimer();
    }, reinterpret_cast<int>(this));
}


void Game::maybeSpawnPowerUp(float x, float y) {
    if (rand() % 100 < 20) { // %20 ihtimal
        PowerUpType type;
        int r = rand() % 3;
        if (r == 0) type = PowerUpType::Upgrade;
        else if (r == 1) type = PowerUpType::Health;
        else type = PowerUpType::Shield;
        powerUps.push_back(new PowerUp(x, y, type));
    }
}
