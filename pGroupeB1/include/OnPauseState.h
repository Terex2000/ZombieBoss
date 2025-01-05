#ifndef ONPAUSESTATE_H
#define ONPAUSESTATE_H

#include "State.h"
#include "StateManager.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "GameController.h"
#include "HUDController.h"
#include "Player.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include "ShopState.h"
#include <vector>
#include <string>


class OnPauseState : public State {
public:
    OnPauseState(sf::RenderWindow& window, SoundManager& soundManager,
                 TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager, Player& player, HUDController& hudController);

    OnPauseState(sf::RenderWindow& window, SoundManager& soundManager,
                 TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager);

    virtual ~OnPauseState();

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    StateManager* stateManager;
    SoundManager& soundManager;
    TextureManager& textureManager;
    InputManager& inputManager;
    HUDController& hudController;
    GameController gameController;
    Player& player;


    sf::Font font;
    std::vector<std::string> options;
    size_t selectedOption;

    void navigateUp();
    void navigateDown();
    void executeOption();
};

#endif // ONPAUSESTATE_H
