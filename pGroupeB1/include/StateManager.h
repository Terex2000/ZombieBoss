#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "State.h"
#include <memory>
#include <unordered_map>
#include <string>
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
};

#endif // STATEMANAGER_H
