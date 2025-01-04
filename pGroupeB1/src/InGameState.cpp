#include "InGameState.h"
#include "OnPauseState.h"
#include "MainMenuState.h"

InGameState::InGameState(sf::RenderWindow& window, SoundManager& soundManager,
                         TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager)
    : window(window), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), stateManager(stateManager), gameController(stateManager, textureManager) {}


InGameState::~InGameState() {
    std::cout << "InGameState destroyed" << std::endl;
}

void InGameState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
        gameController.handleInput(event);
        std::cout << "Key pressed: " << event.key.code << std::endl;
        if (event.key.code == sf::Keyboard::P) {
            std::cout << "Escape pressed: Switching to OnPauseState" << std::endl;
            stateManager->setState(std::make_unique<OnPauseState>(window,soundManager, textureManager, inputManager,stateManager));
        }else if (event.key.code == sf::Keyboard::Escape) {
            std::cout << "Escape pressed: Switching to OnPauseState" << std::endl;
            stateManager->setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, stateManager));
        }
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
