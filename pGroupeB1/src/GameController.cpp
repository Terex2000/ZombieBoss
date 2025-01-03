#include "GameController.h"
#include <iostream>

GameController::GameController(TextureManager& textureManager)
    : playerController(100.0f, 100.0f, textureManager), worldController(textureManager, playerController), textureManager(textureManager) {
    // Load background texture
    if (!textureManager.loadTexture("background", "assets/img/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }
    backgroundSprite.setTexture(textureManager.getTexture("background"));
}

void GameController::run(sf::RenderWindow& window) {
    sf::Clock clock;

    // Adjust background
    textureManager.adjustSpriteToWindow(backgroundSprite, window);

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

        // Draw background
        window.setView(window.getDefaultView());
        window.draw(backgroundSprite);

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