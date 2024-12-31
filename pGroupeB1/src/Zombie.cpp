#include "Zombie.h"

Zombie::Zombie(float x, float y, float health, float attack, float speed, float maxDistance)
    : position(x, y), origin(x, y), health(health), attack(attack), speed(speed), maxDistance(maxDistance), direction(1.0f) {}

Zombie::~Zombie() {}

void Zombie::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

const sf::Vector2f& Zombie::getPosition() const {
    return position;
}

void Zombie::setHealth(float health) {
    this->health = health;
}

float Zombie::getHealth() const {
    return health;
}

void Zombie::setAttack(float attack) {
    this->attack = attack;
}

float Zombie::getAttack() const {
    return attack;
}

void Zombie::setSpeed(float speed) {
    this->speed = speed;
}

float Zombie::getSpeed() const {
    return speed;
}

void Zombie::takeDamage(float damage) {
    health -= damage;
}

void Zombie::update(float deltaTime) {
    position.x += direction * speed * deltaTime;
    if (std::abs(position.x - origin.x) > maxDistance) {
        direction = -direction;
    }
}