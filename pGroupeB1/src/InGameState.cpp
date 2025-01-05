#include "InGameState.h"
#include "OnPauseState.h"
#include "MainMenuState.h"
#include "WinState.h"
#include "LoseState.h"

InGameState::InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                         TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager)
    : window(window), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), stateManager(stateManager), gameController(stateManager, textureManager) {}


InGameState::~InGameState() {
    std::cout << "InGameState destroyed" << std::endl;
}

void InGameState::handleInput(sf::RenderWindow& window, sf::Event event) {
        if (event.key.code == sf::Keyboard::P) {
            std::cout << "Escape pressed: Switching to OnPauseState" << std::endl;
            stateManager->setState(std::make_unique<OnPauseState>(window,soundManager, textureManager, inputManager,stateManager));
        }else if (event.key.code == sf::Keyboard::Escape) {
            std::cout << "Escape pressed: Switching to OnPauseState" << std::endl;
            stateManager->setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if(gameController.getWorldController().isBossRoomEmpty() && gameController.getWorldController().isInBossRoom()){
            if(gameController.getWorldController().getCurrentLevelIndex() == gameController.getWorldController().getLevelSize() -1){
                if(gameController.getWorldController().getCurrentWorldIndex() == gameController.getWorldController().getWorldSize() -1){
                    stateManager->setState(std::make_unique<WinState>(window, soundManager, textureManager, inputManager, stateManager));

                }
            }
        } else if(gameController.getWorldController().getPlayerLives()){
                    stateManager->setState(std::make_unique<LoseState>(window, soundManager, textureManager, inputManager, stateManager));
        } else if(event.key.code == sf::Keyboard::S) {
            gameController.saveGame("save.json");
        }

}


void InGameState::update(sf::RenderWindow& window, double deltaTime) {
     gameController.update(deltaTime);
}

void InGameState::draw(sf::RenderWindow& window) {
    window.clear();
    gameController.draw(window);
    window.display();
}
