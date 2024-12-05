// Player.cpp
#include "Player.h"

Player::Player() {
    shape.setRadius(15);
    shape.setFillColor(sf::Color::Red);
}

Player::Player(const Player& other) : shape(other.shape) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        shape = other.shape;
    }
    return *this;
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