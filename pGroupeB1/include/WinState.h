#ifndef WINSTATE_H
#define WINSTATE_H

#include "State.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "GameController.h"
#include <vector>
#include <string>


class WinState : public State {
public:
    WinState(sf::RenderWindow& window, SoundManager& soundManager,
                TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager);
    ~WinState() override;

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    StateManager* stateManager;
    SoundManager& soundManager;
    TextureManager& textureManager;
    InputManager& inputManager;

    sf::Font font;
    std::vector<std::string> options;
    size_t selectedOption;
        sf::Text winText;

        void navigateUp();
    void navigateDown();
    void executeOption();
};

#endif // WINSTATE_H
