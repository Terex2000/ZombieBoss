#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.h"
#include <memory>
#include <SFML/Graphics.hpp>

class StateManager {
private:
    std::unique_ptr<State> currentState;
    sf::RenderWindow& window;

public:
    StateManager(sf::RenderWindow& window);
    ~StateManager();

    void setState(std::unique_ptr<State> newState);
    void handleInput(sf::Event event);
    void update(double deltaTime);
    void draw();

    State* getCurrentState() const {
        return currentState.get();
    }
};

#endif // STATEMANAGER_H
