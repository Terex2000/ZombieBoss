#include "StateManager.h"
#include <iostream>

// Constructor for StateManager, initializes with a reference to the main window
StateManager::StateManager(sf::RenderWindow& window) : window(window) {}

// Default destructor for StateManager
StateManager::~StateManager() = default;

// Set a new state for the StateManager
void StateManager::setState(std::unique_ptr<State> newState) {
    if (!newState) {
        std::cerr << "Error: Attempted to set a null state!" << std::endl;
        return;
    }

    // If there is a current state, delete it
    if (currentState) {
        std::cout << "StateManager: Deleting current state" << std::endl;
        currentState.reset(); // Delete the current state
    }

    // Set the new state
    currentState = std::move(newState);

    // Confirm the state change
    if (currentState) {
        std::cout << "StateManager: State changed successfully to " << typeid(*currentState).name() << std::endl;
    } else {
        std::cerr << "Error: Failed to set new state!" << std::endl;
    }
}

// Handle input events and pass them to the current state
void StateManager::handleInput(sf::Event event) {
    if (currentState) {
        currentState->handleInput(window, event);
    } else {
        std::cout << "StateManager: No currentState set" << std::endl;
    }
}

// Update the current state with the elapsed time
void StateManager::update(double deltaTime) {
    if (currentState) {
        currentState->update(window, deltaTime);
    }
}

// Draw the current state
void StateManager::draw() {
    if (currentState) {
        currentState->draw(window);
    }
}
