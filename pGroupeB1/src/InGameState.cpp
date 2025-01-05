#include "InGameState.h"
#include "OnPauseState.h"
#include "MainMenuState.h"
#include "WinState.h"
#include "LoseState.h"

InGameState::InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                         TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager)
    : window(window), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), stateManager(stateManager), gameController(stateManager, textureManager), hudController(gameController.getWorldController().getPlayer(), nullptr), changeState(false) {}

InGameState::InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                         TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager, const std::string& saveFile)
    : window(window), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), stateManager(stateManager), gameController(stateManager, textureManager, saveFile), hudController(gameController.getWorldController().getPlayer(), nullptr), changeState(false) {}

InGameState::~InGameState() {
    std::cout << "InGameState destroyed" << std::endl;
}

void InGameState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::P) {
            std::cout << "P pressed: Switching to OnPauseState" << std::endl;
            gameController.saveTemporaryState(); // Save the temporary game state
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
    }

    if (gameController.getWorldController().isBossRoomEmpty() && gameController.getWorldController().isInBossRoom()) {
        if (gameController.getWorldController().getCurrentLevelIndex() == gameController.getWorldController().getLevelSize() - 1) {
            if (gameController.getWorldController().getCurrentWorldIndex() == gameController.getWorldController().getWorldSize() - 1) {
                std::cout << "Boss room empty and final level completed: Switching to WinState" << std::endl;
                nextState = "WinState";
                changeState = true;
            }
        }
    } else if (gameController.getWorldController().getPlayer().getHealth() <= 0) {
        std::cout << "Player health <= 0: Switching to LoseState" << std::endl;
        nextState = "LoseState";
        changeState = true;
    }
}

void InGameState::update(sf::RenderWindow& window, double deltaTime) {
    gameController.update(deltaTime);
    Boss* currentBoss = nullptr;
    if (!gameController.getWorldController().getBossController().getEnemies().empty()) {
        currentBoss = dynamic_cast<Boss*>(gameController.getWorldController().getBossController().getEnemies().front());
    }
    hudController.setBoss(currentBoss); // Update the HUDController with the current boss
    hudController.update(); // Update the HUD

    if (changeState) {
        std::cout << "Changing state to " << nextState << std::endl;
        if (nextState == "OnPauseState") {
            stateManager->setState(std::make_unique<OnPauseState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if (nextState == "MainMenuState") {
            stateManager->setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if (nextState == "WinState") {
            stateManager->setState(std::make_unique<WinState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if (nextState == "LoseState") {
            stateManager->setState(std::make_unique<LoseState>(window, soundManager, textureManager, inputManager, stateManager));
        }
        changeState = false;
    }
}

void InGameState::draw(sf::RenderWindow& window) {
    window.clear();
    gameController.draw(window);
    sf::View originalView = window.getView();
    window.setView(hudView);
    hudController.draw(window); // Draw the HUD
        window.setView(originalView);

    window.display();
}