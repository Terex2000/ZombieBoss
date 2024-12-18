#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow& window) : window(window) {}

StateManager::~StateManager() {}

void StateManager::setState(std::unique_ptr<State> newState) {
    currentState = std::move(newState);
}

void StateManager::handleInput(sf::Event event) {
    if (currentState) {
        currentState->handleInput(window, event);
    }
}

void StateManager::update(double deltaTime) {
    if (currentState) {
        currentState->update(window, deltaTime);

        // Transition vers un nouvel �tat si n�cessaire
        if (currentState->shouldChangeState()) {
            std::string nextState = currentState->getNextState();
            if (!nextState.empty()) {
                // Chargez ici le nouvel �tat en fonction de `nextState`
                // Exemple : setState(std::make_unique<NextState>(window));
            }
        }
    }
}

void StateManager::draw() {
    if (currentState) {
        currentState->draw(window);
    }
}
