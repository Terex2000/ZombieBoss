// GameController.cpp
#include "GameController.h"
#include <iostream>

GameController::GameController() 
    : playerController(100.0f, 100.0f) // Initial position of the player
{
    if (!textureManager.loadTexture("tileset", "assets/tileset.png")) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
    if (!textureManager.loadTexture("background", "assets/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }
    mapController = new MapController(fileReader.readMap("assets/map.txt"), textureManager);
    collisionTypes = fileReader.readCollisionTypes("assets/map.txt");
    std::cout << "Total collision types: " << collisionTypes.size() << std::endl; // Debug message
}

void GameController::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Map");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        inputManager.handleInput(playerController);
        collisionManager.checkCollisions(playerController, mapController->getMap(), collisionTypes);

        window.clear();
        mapController->draw(window);
        playerController.draw(window);
        window.display();
    }

    delete mapController;
}