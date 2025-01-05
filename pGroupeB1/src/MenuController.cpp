#include "MenuController.h"
#include <SFML/Window/Keyboard.hpp>

// Constructor: Initializes the MenuController with a reference to the main menu model and input manager
MenuController::MenuController(MainMenu& model, InputManager& inputManager)
    : model(model), inputManager(inputManager) {}

// Handles user input for navigating the menu
void MenuController::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        model.selectPrevious(); // Select the previous menu option
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        model.selectNext(); // Select the next menu option
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        if (model.getSelectedOption() == MainMenu::Quit) {
            exit(0); // Quit the game
        }
    }
}
