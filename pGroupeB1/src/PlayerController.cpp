// PlayerController.cpp
#include "PlayerController.h"

PlayerController::PlayerController(float startX, float startY) : player(), playerView(player) {
    player.setPosition(startX, startY);
}

PlayerController::~PlayerController() {}

void PlayerController::draw(sf::RenderWindow& window) {
    playerView.draw(window);
}

void PlayerController::move(float dx, float dy) {
    player.move(dx, dy);
}

const sf::CircleShape& PlayerController::getPlayerShape() const {
    return player.getShape();
}

void PlayerController::setPosition(float x, float y) {
    player.setPosition(x, y);
}