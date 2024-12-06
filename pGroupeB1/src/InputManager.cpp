// InputManager.cpp
#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>

InputManager::InputManager() {}

InputManager::~InputManager() {}

void InputManager::handleInput(PlayerController& playerController) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerController.move(-moveSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerController.move(moveSpeed, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        playerController.jump();
    }
}