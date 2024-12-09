#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
#include "StateManager.h"
#include "SoundManager.h"
#include <SFML/Graphics.hpp>

class MainMenuState : public State {
private:
    sf::Font font;
    sf::Text title;
    sf::Text newGameOption;
    sf::Text quitOption;

    int selectedOption; // 0 = New Game, 1 = Quit
    SoundManager& soundManager;

    bool changeState;
    std::string nextState;

public:
    MainMenuState(sf::RenderWindow& window, SoundManager& soundManager);
    virtual ~MainMenuState();

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

    bool shouldChangeState() const override;
    std::string getNextState() const override;
};

#endif // MAINMENUSTATE_H
