// Player.cpp
#include "Player.h"

Player::Player() {
    shape.setRadius(15);
    shape.setFillColor(sf::Color::Red); // Définir la couleur initiale en rouge
}

Player::~Player() {}

void Player::move(float dx, float dy) {
    shape.move(dx, dy);
}

const sf::CircleShape& Player::getShape() const {
    return shape;
}

void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

void Player::setColor(const sf::Color& color) {
    shape.setFillColor(color);
}