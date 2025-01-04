#ifndef LOSESTATE_H
#define LOSESTATE_H

#include "State.h"
#include <SFML/Graphics.hpp>

class LoseState : public State {
public:
    LoseState(sf::RenderWindow& window); // Ajout du constructeur avec fen�tre
    ~LoseState() override;

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
};

#endif // LOSESTATE_H
