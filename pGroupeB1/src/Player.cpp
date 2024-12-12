#include "Player.h"

Player::Player() : position(0, 0), color(sf::Color::Red), radius(15.0f), direction(1.0f) {}

Player::Player(const Player& other) : position(other.position), color(other.color), radius(other.radius), direction(other.direction) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        position = other.position;
        color = other.color;
        radius = other.radius;
        direction = other.direction;
    }
    return *this;
}

Player::~Player() {}

void Player::move(float dx, float dy) {
    position.x += dx;
    position.y += dy;
    if (dx != 0) {
        direction = (dx > 0) ? 1.0f : -1.0f;
    }
}

const sf::Vector2f& Player::getPosition() const {
    return position;
}

void Player::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void Player::setColor(const sf::Color& color) {
    this->color = color;
}

const sf::Color& Player::getColor() const {
    return color;
}

float Player::getRadius() const {
    return radius;
}

void Player::setDirection(float direction) {
    this->direction = direction;
}

float Player::getDirection() const {
    return direction;
}