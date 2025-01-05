#include "Boss.h"

Boss::Boss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture, bool isFinalBoss, float shield)
    : position(x, y), origin(x, y), health(health), attack(attack), speed(speed), coins(coins), finalBoss(isFinalBoss), shield(shield) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(150.0f / texture.getSize().x, 150.0f / texture.getSize().y); // Scale the sprite to 150 pixels
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f); // Center the sprite
}

Boss::~Boss() {}

void Boss::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
    sprite.setPosition(position);
}

const sf::Vector2f& Boss::getPosition() const {
    return position;
}

void Boss::setHealth(float health) {
    this->health = health;
}

float Boss::getHealth() const {
    return health;
}

void Boss::setAttack(float attack) {
    this->attack = attack;
}

float Boss::getAttack() const {
    return attack;
}

void Boss::setSpeed(float speed) {
    this->speed = speed;
}

float Boss::getSpeed() const {
    return speed;
}

void Boss::setMaxDistance(float maxDistance) {
    this->maxDistance = maxDistance;
}

float Boss::getMaxDistance() const {
    return maxDistance;
}

void Boss::setCoins(int coins) {
    this->coins = coins;
}

int Boss::getCoins() const {
    return coins;
}

void Boss::setShield(float shield) {
    this->shield = shield;
}

float Boss::getShield() const {
    return shield;
}

void Boss::setFinalBoss(bool isFinalBoss) {
    this->finalBoss = isFinalBoss;
}

bool Boss::isFinalBoss() const {
    return finalBoss;
}

const sf::Vector2f& Boss::getinitialPosition() const {
    return origin;
}

void Boss::takeDamage(float damage) {
    if (shield > 0) {
        shield -= damage;
        if (shield < 0) {
            health += shield; // Apply remaining damage to health
            shield = 0;
        }
    } else {
        health -= damage;
    }
}

void Boss::update(float deltaTime) {
    // Implement any specific behavior for the boss here
}

const sf::Sprite& Boss::getSprite() const {
    return sprite;
}