#include "GameController.h"
#include <iostream>

GameController::GameController(StateManager* stateManager, TextureManager& textureManager)
    : stateManager(stateManager), playerController(100.0f, 100.0f, textureManager), worldController(textureManager, playerController), textureManager(textureManager) {
    // Load textures
    if (!textureManager.loadTexture("background", "assets/img/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }

    // Create the sprite for the background
    backgroundSprite.setTexture(textureManager.getTexture("background"));
}

void GameController::run(sf::RenderWindow& window) {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        // Update world
        worldController.update(deltaTime);

        window.clear();

        // Draw world
        worldController.draw(window);

        window.display();
    }
}

void GameController::update(float deltaTime) {

    // Update world
    worldController.update(deltaTime);
}

void GameController::draw(sf::RenderWindow& window) {

    worldController.draw(window);
}