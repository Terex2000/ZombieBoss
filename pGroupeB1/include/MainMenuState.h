#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "State.h"
#include "MainMenu.h"
#include "MainMenuView.h"
#include "MenuController.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "GameController.h"
#include "Settings.h"
#include "StateManager.h"
#include "InGameState.h"
#include "OnPauseState.h"

class MainMenuState : public State {
public:
    MainMenuState(sf::RenderWindow& window, SoundManager& soundManager,
                  TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager, GameController& gameController);
    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;


private:

    enum class MenuType { MainMenu, Settings };
    MenuType currentMenu;

    StateManager* stateManager;

    MainMenu model;
    MainMenuView view;
    Settings settings;
    MenuController controller;
    SoundManager& soundManager;
    GameController& gameController;

    bool launchGame;
    bool loadGame;
    int selectedSettingOption;
    bool isFullscreen;

    sf::RenderWindow& window;
    TextureManager& textureManager;
    InputManager& inputManager;

    sf::Texture settingsBackgroundTexture;
    sf::Sprite settingsBackgroundSprite;


    void toggleFullscreen();
    void adjustWindowToScreen();
};

#endif // MAINMENUSTATE_H
