#pragma once

class Bullet {
private:
    float x, y;
    float speed;
    float length;
    float animAlpha;
    bool active;

public:
    Bullet();
    void activate(float startX, float startY);
    void update();
    void draw() const;
    void deactivate();
    bool isActive() const;
    bool isOffScreen() const;
    float getX() const;
    float getY() const;
};
