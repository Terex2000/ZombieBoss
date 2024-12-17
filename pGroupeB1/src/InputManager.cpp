#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>

InputManager::InputManager() {}

InputManager::~InputManager() {}

// Handles input for the player controller.
void InputManager::handleInput(PlayerController& playerController) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerController.move(-moveSpeed, 0);
        playerController.getPlayer().setDirection(-1.0f); // Update the direction
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerController.move(moveSpeed, 0);
        playerController.getPlayer().setDirection(1.0f); // Update the direction
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { // Player Jump
        playerController.jump();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { // Example key for shooting
        playerController.shoot();
    }
}