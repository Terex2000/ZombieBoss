#include "MenuController.h"
#include <SFML/Window/Keyboard.hpp>

MenuController::MenuController(MainMenu& model, InputManager& inputManager)
    : model(model), inputManager(inputManager) {}

void MenuController::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        model.selectPrevious();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        model.selectNext();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (model.getSelectedOption() == MainMenu::Quit) {
            exit(0); // Quitter le jeu
        }
    }
}
