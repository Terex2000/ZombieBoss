#include "Boss.h"

// Constructor: Initializes the Boss with position, health, attack, speed, coins, texture, final boss status, and shield
Boss::Boss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture, bool isFinalBoss, float shield)
    : position(x, y), origin(x, y), health(health), attack(attack), speed(speed), coins(coins), finalBoss(isFinalBoss), shield(shield) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(150.0f / texture.getSize().x, 150.0f / texture.getSize().y); // Scale the sprite to 150 pixels
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f); // Center the sprite
}

// Destructor: Cleans up any resources used by the Boss
Boss::~Boss() {}

// Sets the position of the Boss
void Boss::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
    sprite.setPosition(position);
}

// Returns the current position of the Boss
const sf::Vector2f& Boss::getPosition() const {
    return position;
}

// Sets the health of the Boss
void Boss::setHealth(float health) {
    this->health = health;
}

// Returns the current health of the Boss
float Boss::getHealth() const {
    return health;
}

// Sets the attack power of the Boss
void Boss::setAttack(float attack) {
    this->attack = attack;
}

// Returns the current attack power of the Boss
float Boss::getAttack() const {
    return attack;
}

// Sets the speed of the Boss
void Boss::setSpeed(float speed) {
    this->speed = speed;
}

// Returns the current speed of the Boss
float Boss::getSpeed() const {
    return speed;
}

// Sets the maximum distance the Boss can move
void Boss::setMaxDistance(float maxDistance) {
    this->maxDistance = maxDistance;
}

// Returns the maximum distance the Boss can move
float Boss::getMaxDistance() const {
    return maxDistance;
}

// Sets the number of coins the Boss drops upon defeat
void Boss::setCoins(int coins) {
    this->coins = coins;
}

// Returns the number of coins the Boss drops upon defeat
int Boss::getCoins() const {
    return coins;
}

// Sets the shield value of the Boss
void Boss::setShield(float shield) {
    this->shield = shield;
}

// Returns the current shield value of the Boss
float Boss::getShield() const {
    return shield;
}

// Sets whether the Boss is the final boss
void Boss::setFinalBoss(bool isFinalBoss) {
    this->finalBoss = isFinalBoss;
}

// Returns whether the Boss is the final boss
bool Boss::isFinalBoss() const {
    return finalBoss;
}

// Returns the initial position of the Boss
const sf::Vector2f& Boss::getinitialPosition() const {
    return origin;
}

// Applies damage to the Boss, reducing shield first, then health
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

// Updates the Boss's state (implement specific behavior here)
void Boss::update(float deltaTime) {
    // Implement any specific behavior for the boss here
}

// Returns the sprite of the Boss for rendering
const sf::Sprite& Boss::getSprite() const {
    return sprite;
}
