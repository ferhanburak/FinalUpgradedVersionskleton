
#include "PowerUp.h"
#include "graphics.h"

PowerUp::PowerUp(float x, float y, PowerUpType type) : x(x), y(y), size(20), type(type) {
    switch (type) {
        case PowerUpType::Upgrade: color = Color(255, 215, 0); break; // Gold
        case PowerUpType::Health: color = Color(0, 255, 0); break;    // Green
        case PowerUpType::Shield: color = Color(0, 200, 255); break;  // Blue
    }
}

void PowerUp::update() {
    y += 2.0f; // Slide down
}

void PowerUp::draw() const {
    graphics::Brush br;
    br.fill_color[0] = color.r / 255.0f;
    br.fill_color[1] = color.g / 255.0f;
    br.fill_color[2] = color.b / 255.0f;
    graphics::drawDisk(x, y, size / 2, br);
}

float PowerUp::getX() const { return x; }
float PowerUp::getY() const { return y; }
float PowerUp::getSize() const { return size; }
PowerUpType PowerUp::getType() const { return type; }
