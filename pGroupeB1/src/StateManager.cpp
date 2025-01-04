#include "StateManager.h"
#include <iostream>

StateManager::StateManager(sf::RenderWindow& window) : window(window) {}

StateManager::~StateManager() = default;

void StateManager::setState(std::unique_ptr<State> newState) {
    if (!newState) {
        std::cerr << "Error: Attempted to set a null state!" << std::endl;
        return;
    }

    if (currentState) {
        std::cout << "StateManager: Deleting current state" << std::endl;
        currentState.reset(); // Supprime l'�tat actuel
    }

    currentState = std::move(newState);

    if (currentState) {
        std::cout << "StateManager: State changed successfully to " << typeid(*currentState).name() << std::endl;
    } else {
        std::cerr << "Error: Failed to set new state!" << std::endl;
    }
}


void StateManager::handleInput(sf::Event event) {
    if (currentState) {
        currentState->handleInput(window, event);
    } else {
        std::cout << "StateManager: No currentState set" << std::endl;
    }
}

void StateManager::update(double deltaTime) {
    if (currentState) {
        currentState->update(window, deltaTime);
    }
}

void StateManager::draw() {
    if (currentState) {
        currentState->draw(window);
    }
}
