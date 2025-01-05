#include "Player.h"

// Constructor for Player
Player::Player() : position(0, 0), color(sf::Color::Red), radius(14.5f), direction(1.0f), coins(50), state(State::Idle), health(100.0f), lives(3), bulletDamage(10) {
    shape.setRadius(radius); // Set the radius of the shape
    shape.setOrigin(radius, radius); // Center the origin of the shape
    shape.setPosition(position);
}

// Copy constructor for Player
Player::Player(const Player& other) : position(other.position), color(other.color), radius(other.radius), direction(other.direction), coins(other.coins), state(State::Idle), health(other.health), lives(other.lives) {
}

// Copy assignment operator for Player
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        position = other.position;
        color = other.color;
        radius = other.radius;
        direction = other.direction;
        coins = other.coins;
        shape = other.shape;
        health = other.health;
        lives = other.lives;
    }
    return *this;
}

// Destructor for Player
Player::~Player() {}

// Moves the player by the specified amounts.
void Player::move(float dx, float dy) {
    position.x += dx;
    position.y += dy;

    // Update hitbox position
    if (dx != 0) {
        direction = (dx > 0) ? 1.0f : -1.0f;
    }
}

// Returns the position of the player.
const sf::Vector2f& Player::getPosition() const {
    return position;
}

// Sets the position of the player.
void Player::setPosition(float x, float y) {
    position.x = x;
    position.y = y;

}

// Sets the direction the player is facing.
void Player::setDirection(float direction) {
    this->direction = direction;
}

void Player::setColor(const sf::Color& color) {
    this->color = color;
}

// Returns the color of the player.
const sf::Color& Player::getColor() const {
    return color;
}

// Returns the radius of the player.
float Player::getRadius() const {
    return radius;
}

// Returns the direction the player is facing.
float Player::getDirection() const {
    return direction;
}

// Adds coins to the player's total.
void Player::addCoins(int amount) {
    coins += amount;
}

// Returns the number of coins the player has.
int Player::getCoins() const {
    return coins;
}

void Player::setCoins(int coins) {
    this->coins = coins;
}

void Player::setState(State newState) {
    state = newState;
}

Player::State Player::getState() const {
    return state;
}

// Sets the player's health.
void Player::setHealth(float health) {
    this->health = health;
}

// Returns the player's health.
float Player::getHealth() const {
    return health;
}

// Reduces the player's health by the specified amount.
void Player::takeDamage(float damage) {
    health -= damage;
    if (health <= 0) {
        loseLife();
        health = 100.0f; // Reset health after losing a life
    }
}

// Increases the player's health by the specified amount.
void Player::heal(float amount) {
    health += amount;
    if (health > 100.0f) {
        health = 100.0f; // Cap health at 100
    }
}

// Sets the player's lives.
void Player::setLives(int lives) {
    this->lives = lives;
}

// Returns the player's lives.
const int Player::getLives() const {
    return lives;
}

// Reduces the player's lives by one.
void Player::loseLife() {
    lives--;
    if (lives < 0) {
        lives = 0; // Ensure lives don't go below 0
    }
}

// Increases the player's lives by one.
void Player::gainLife() {
    lives++;
}

// Sets the damage dealt by the player's bullets.
void Player::setBulletDamage(int damage) {
    bulletDamage = damage;
}

// Returns the damage dealt by the player's bullets.
int Player::getBulletDamage() const {
    return bulletDamage;
}

// Returns the player's shape
sf::CircleShape Player::getShape() const {
    return shape;
}

// Sets the texture for the player
void Player::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);
    shape.setTexture(&texture);
}
