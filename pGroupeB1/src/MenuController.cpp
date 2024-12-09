#include "MenuController.h"

MenuController::MenuController(MainMenu& model, MainMenuView& view)
    : model(model), view(view) {}

MenuController::~MenuController() {}

void MenuController::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            model.selectPrevious();
        } else if (event.key.code == sf::Keyboard::Down) {
            model.selectNext();
        } else if (event.key.code == sf::Keyboard::Enter) {
            model.confirmSelection();
        }
    }
}

void MenuController::update() {
    // Optional logic
}
