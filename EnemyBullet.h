#pragma once

class EnemyBullet {
private:
    float x, y;
    float speed;
    float length;
    bool active;

public:
    EnemyBullet();
    void activate(float startX, float startY);
    void update();
    void draw() const;
    void deactivate();
    bool isActive() const;
    bool isOffScreen() const;
    float getX() const;
    float getY() const;
};
