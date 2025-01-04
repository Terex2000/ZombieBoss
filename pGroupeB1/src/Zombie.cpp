#include "Zombie.h"

Zombie::Zombie(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture)
    : position(x, y), origin(x, y), health(health), attack(attack), speed(speed), maxDistance(maxDistance), direction(1.0f), coins(coins) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(32.0f / texture.getSize().x, 32.0f / texture.getSize().y); // Scale the sprite to 15 pixels
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f); // Center the sprite
}

Zombie::~Zombie() {}

void Zombie::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
    sprite.setPosition(position);
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
    sprite.setPosition(position);
}

const sf::Sprite& Zombie::getSprite() const {
    return sprite;
}

int Zombie::getCoins() const {
    return coins;
}