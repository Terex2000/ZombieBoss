#include "StateManager.h"
#include "MainMenuState.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game Menu");
    TextureManager textureManager;
    SoundManager soundManager(50);
    InputManager inputManager;

    if (!textureManager.loadTexture("Idle", "assets/player/idle.png")) {
        std::cerr << "Error: Failed to load Idle texture" << std::endl;
    }
    if (!textureManager.loadTexture("Jump", "assets/player/jump.png")) {
        std::cerr << "Error: Failed to load Jump texture" << std::endl;
    }
    if (!textureManager.loadTexture("Run", "assets/player/run.png")) {
        std::cerr << "Error: Failed to load Run texture" << std::endl;
    }
    if (!textureManager.loadTexture("Shot_2", "assets/player/shot_2.png")) {
        std::cerr << "Error: Failed to load Shot_2 texture" << std::endl;
    }

    StateManager stateManager(window);
    stateManager.setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager));

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            stateManager.handleInput(event);
        }

        double deltaTime = clock.restart().asSeconds();
        stateManager.update(deltaTime);
        stateManager.draw();
    }

    return 0;
}
