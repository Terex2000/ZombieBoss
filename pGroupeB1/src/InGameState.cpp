#include "InGameState.h"
#include "OnPauseState.h"
#include "MainMenuState.h"
#include "WinState.h"
#include "LoseState.h"

InGameState::InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                         TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager)
    : window(window), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), stateManager(stateManager), gameController(stateManager, textureManager), changeState(false) {}

InGameState::InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                         TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager, const std::string& saveFile)
    : window(window), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), stateManager(stateManager), gameController(stateManager, textureManager, saveFile), changeState(false) {}

InGameState::~InGameState() {
    std::cout << "InGameState destroyed" << std::endl;
}

void InGameState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::P) {
            std::cout << "P pressed: Switching to OnPauseState" << std::endl;
            gameController.saveTemporaryState();
            nextState = "OnPauseState";
            changeState = true;
        } else if (event.key.code == sf::Keyboard::Escape) {
            std::cout << "Escape pressed: Switching to MainMenuState" << std::endl;
            nextState = "MainMenuState";
            changeState = true;
        } else if (event.key.code == sf::Keyboard::S) {
            std::cout << "S pressed: Save game" << std::endl;
            gameController.saveGame("save.json");
        }
    if (gameController.getWorldController().isBossRoomEmpty() && gameController.getWorldController().isInBossRoom()) {
        if (gameController.getWorldController().getCurrentLevelIndex() == gameController.getWorldController().getLevelSize() - 1) {
            if (gameController.getWorldController().getCurrentWorldIndex() == gameController.getWorldController().getWorldSize() - 1) {
                std::cout << "Boss room empty and final level completed: Switching to WinState" << std::endl;
                nextState = "WinState";
                changeState = true;
            }
        }
    } else if (gameController.getWorldController().getPlayer().getLives() <= 0) {
        nextState = "LoseState";
        changeState = true;
    }
    }
}

void InGameState::update(sf::RenderWindow& window, double deltaTime) {
    gameController.update(deltaTime);

    if (changeState) {
        if (nextState == "OnPauseState") {
            stateManager->setState(std::make_unique<OnPauseState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if (nextState == "MainMenuState") {
            stateManager->setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if (nextState == "WinState") {
            stateManager->setState(std::make_unique<WinState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if (nextState == "LoseState") {
            stateManager->setState(std::make_unique<LoseState>(window, soundManager, textureManager, inputManager, stateManager));
            changeState = false;
        }
    }
}

void InGameState::draw(sf::RenderWindow& window) {
    window.clear();
    gameController.draw(window);
    window.display();
}