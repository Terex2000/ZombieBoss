#include "GameController.h"
#include <iostream>

GameController::GameController() {
    if (!textureManager.loadTexture("tileset", "assets/tileset.png")) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
    if (!textureManager.loadTexture("background", "assets/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }
    mapController = new MapController(fileReader.readMap("assets/map.txt"), textureManager);
}

void GameController::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Map");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mapController->draw(window);
        window.display();
    }

    delete mapController;
}