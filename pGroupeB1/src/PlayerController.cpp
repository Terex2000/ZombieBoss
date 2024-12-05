// PlayerController.cpp
#include "PlayerController.h"

PlayerController::PlayerController(float startX, float startY) 
    : player(), playerView(player), verticalSpeed(0.0f), isJumping(false), onGround(false) {
    player.setPosition(startX, startY);
    player.setColor(sf::Color::Red); // Définir la couleur du joueur en rouge
}

PlayerController::~PlayerController() {}

void PlayerController::draw(sf::RenderWindow& window) {
    playerView.draw(window);
}

void PlayerController::move(float dx, float dy) {
    player.move(dx, dy);
}

void PlayerController::update(float deltaTime) {
    if (!onGround) {
        verticalSpeed += gravity * deltaTime;
        move(0, verticalSpeed * deltaTime);
    }
}

const sf::CircleShape& PlayerController::getPlayerShape() const {
    return player.getShape();
}

void PlayerController::setPosition(float x, float y) {
    player.setPosition(x, y);
}

void PlayerController::jump() {
    if (onGround) {
        isJumping = true;
        onGround = false;
        verticalSpeed = jumpSpeed;
    }
}

void PlayerController::resetVerticalSpeed() {
    verticalSpeed = 0.0f;
}

void PlayerController::setJumping(bool jumping) {
    isJumping = jumping;
}

void PlayerController::setOnGround(bool onGround) {
    this->onGround = onGround;
}

bool PlayerController::isOnGround() const {
    return onGround;
}