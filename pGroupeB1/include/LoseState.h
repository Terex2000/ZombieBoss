#ifndef LOSESTATE_H
#define LOSESTATE_H

#include "State.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "GameController.h"

#include <vector>
#include <string>

class LoseState : public State {
public:
    LoseState(sf::RenderWindow& window, SoundManager& soundManager,
                TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager, GameController& gameController);
    ~LoseState() override;

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    StateManager* stateManager;
    SoundManager& soundManager;
    TextureManager& textureManager;
    InputManager& inputManager;
    GameController& gameController;


    sf::Font font;
    std::vector<std::string> options;
    size_t selectedOption;
    sf::Text loseText;

    void navigateUp();
    void navigateDown();
    void executeOption();
};

#endif // LOSESTATE_H
