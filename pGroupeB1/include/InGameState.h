#ifndef INGAMESTATE_H
#define INGAMESTATE_H

#include "State.h"
#include "GameController.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "StateManager.h"
#include "HUDController.h"
#include <SFML/Graphics.hpp>

class InGameState : public State {
public:
    InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager);
    InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager, const std::string& saveFile); // Add this constructor

    ~InGameState() override;

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    SoundManager& soundManager;
    TextureManager& textureManager;
    InputManager& inputManager;
    StateManager* stateManager;
    GameController gameController;
        HUDController hudController; // Add this member to manage the HUD
            sf::View hudView; // Add this member for the HUD view



    bool changeState;
    std::string nextState;
};

#endif // INGAMESTATE_H