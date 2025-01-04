#include "Player.h"

// Constructor for Player
Player::Player() : position(0, 0), color(sf::Color::Red), radius(15.0f), direction(1.0f), coins(0), state(State::Idle) {
    hitbox = sf::FloatRect(position.x, position.y, 42, 69); // Adjust hitbox size
}

// Copy constructor for Player
Player::Player(const Player& other) : position(other.position), color(other.color), radius(other.radius), direction(other.direction), coins(other.coins), state(State::Idle) {
    hitbox = other.hitbox;
}

// Copy assignment operator for Player
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        position = other.position;
        color = other.color;
        radius = other.radius;
        direction = other.direction;
        coins = other.coins;
        hitbox = other.hitbox;
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
    hitbox.left = position.x;
    hitbox.top = position.y;
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

    // Update hitbox position
    hitbox.left = position.x;
    hitbox.top = position.y;
}

// Sets the color of the player.
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

// Sets the direction the player is facing.
void Player::setDirection(float direction) {
    this->direction = direction;
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

void Player::setState(State newState) {
    state = newState;
}

Player::State Player::getState() const {
    return state;
}

// Returns the player's hitbox
sf::FloatRect Player::getHitbox() const {
    return hitbox;
}

