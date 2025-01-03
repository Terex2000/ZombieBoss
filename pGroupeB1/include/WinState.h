#ifndef WINSTATE_H
#define WINSTATE_H

#include "State.h"
#include <SFML/Graphics.hpp>

class WinState : public State {
public:
    WinState(sf::RenderWindow& window);
    ~WinState() override;

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
};

#endif // WINSTATE_H
