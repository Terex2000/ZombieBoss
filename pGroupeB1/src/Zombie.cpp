#include "Zombie.h"

// Constructor: Initializes the Zombie with position, health, attack, speed, max distance, coins, and texture
Zombie::Zombie(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture)
    : position(x, y), origin(x, y), health(health), attack(attack), speed(speed), maxDistance(maxDistance), direction(1.0f), coins(coins), shield(0.0f), finalBoss(false) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(32.0f / texture.getSize().x, 32.0f / texture.getSize().y); // Scale the sprite to 32 pixels
    sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f); // Center the sprite
}

// Destructor: Cleans up any resources used by the Zombie
Zombie::~Zombie() {}

// Sets the position of the Zombie
void Zombie::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
    sprite.setPosition(position);
}

// Returns the current position of the Zombie
const sf::Vector2f& Zombie::getPosition() const {
    return position;
}

// Sets the health of the Zombie
void Zombie::setHealth(float health) {
    this->health = health;
}

// Returns the current health of the Zombie
float Zombie::getHealth() const {
    return health;
}

// Sets the attack power of the Zombie
void Zombie::setAttack(float attack) {
    this->attack = attack;
}

// Returns the current attack power of the Zombie
float Zombie::getAttack() const {
    return attack;
}

// Sets the speed of the Zombie
void Zombie::setSpeed(float speed) {
    this->speed = speed;
}

// Returns the current speed of the Zombie
float Zombie::getSpeed() const {
    return speed;
}

// Sets the maximum distance the Zombie can move
void Zombie::setMaxDistance(float maxDistance) {
    this->maxDistance = maxDistance;
}

// Returns the maximum distance the Zombie can move
float Zombie::getMaxDistance() const {
    return maxDistance;
}

// Sets the number of coins the Zombie drops upon defeat
void Zombie::setCoins(int coins) {
    this->coins = coins;
}

// Returns the number of coins the Zombie drops upon defeat
int Zombie::getCoins() const {
    return coins;
}

// Sets the shield value of the Zombie
void Zombie::setShield(float shield) {
    this->shield = shield;
}

// Returns the current shield value of the Zombie
float Zombie::getShield() const {
    return shield;
}

// Sets whether the Zombie is the final boss
void Zombie::setFinalBoss(bool isFinalBoss) {
    this->finalBoss = isFinalBoss;
}

// Returns whether the Zombie is the final boss
bool Zombie::isFinalBoss() const {
    return finalBoss;
}

// Returns the initial position of the Zombie
const sf::Vector2f& Zombie::getinitialPosition() const {
    return origin;
}

// Applies damage to the Zombie, reducing health
void Zombie::takeDamage(float damage) {
    health -= damage;
}

// Updates the Zombie's position based on the elapsed time
void Zombie::update(float deltaTime) {
    position.x += direction * speed * deltaTime;
    if (std::abs(position.x - origin.x) > maxDistance) {
        direction = -direction;
        sprite.setScale(direction * std::abs(sprite.getScale().x), sprite.getScale().y); // Flip the sprite horizontally
    }
    sprite.setPosition(position);
}

// Returns the sprite of the Zombie for rendering
const sf::Sprite& Zombie::getSprite() const {
    return sprite;
}
