
#pragma once
#include "Color.h"

enum class PowerUpType { Upgrade, Health, Shield };

class PowerUp {
private:
    float x, y;
    float size;
    Color color;
    PowerUpType type;

public:
    PowerUp(float x, float y, PowerUpType type);
    void update();
    void draw() const;
    float getX() const;
    float getY() const;
    float getSize() const;
    PowerUpType getType() const;
};
