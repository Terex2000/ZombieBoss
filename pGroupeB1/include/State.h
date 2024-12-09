#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include <string>

class State {
public:
    State(); // D�clare le constructeur par d�faut
    virtual ~State(); // D�clare le destructeur

    virtual void handleInput(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update(sf::RenderWindow& window, double deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    virtual bool shouldChangeState() const { return false; }
    virtual std::string getNextState() const { return ""; }
};

#endif // STATE_H
