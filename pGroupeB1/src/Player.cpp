// Player.cpp
#include "Player.h"

Player::Player() {
    shape.setRadius(15);
}

Player::~Player() {}

void Player::move(float dx, float dy) {
    shape.move(dx, dy);
}

const sf::CircleShape& Player::getShape() const {
    return shape;
}

void Player::setPosition(float x, float y) { // Implémentation de la méthode setPosition
    shape.setPosition(x, y);
}