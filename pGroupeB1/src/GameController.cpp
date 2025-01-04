#include "GameController.h"
#include <iostream>

GameController::GameController(TextureManager& textureManager)
    : playerController(100.0f, 100.0f, textureManager), worldController(textureManager, playerController), textureManager(textureManager) {}

void GameController::run(sf::RenderWindow& window) {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            handleInput(event);
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

void GameController::handleInput(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::F11) {
            // Handle fullscreen toggle
        } else if (event.key.code == sf::Keyboard::Escape) {
            // Handle game exit
        }
    }
}