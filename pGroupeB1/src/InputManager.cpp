#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>

InputManager::InputManager() {}

InputManager::~InputManager() {}

void InputManager::handleInput(PlayerController& playerController) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerController.move(-moveSpeed, 0);
        playerController.getPlayer().setDirection(-1.0f); // Mettre à jour la direction
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerController.move(moveSpeed, 0);
        playerController.getPlayer().setDirection(1.0f); // Mettre à jour la direction
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        playerController.jump();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { // Exemple de touche pour tirer
        playerController.shoot();
    }
}