// GameController.cpp
#include "GameController.h"
#include <iostream>

GameController::GameController()
    : playerController(100.0f, 100.0f), cameraManager(800.0f, 600.0f) // Initial position of the player and camera size
{
    if (!textureManager.loadTexture("tileset", "assets/img/tileset.png")) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
    if (!textureManager.loadTexture("background", "assets/img/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }
    mapController = new MapController(fileReader.readMap("assets/map/map.txt"), textureManager);
    collisionTypes = fileReader.readCollisionTypes("assets/map/map.txt");
    std::cout << "Total collision types: " << collisionTypes.size() << std::endl; // Debug message

    // Créer le sprite pour le fond d'écran
    backgroundSprite.setTexture(textureManager.getTexture("background"));
}

void GameController::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Map");
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        inputManager.handleInput(playerController);
        playerController.update(deltaTime);
        collisionManager.checkCollisions(playerController, mapController->getMap(), collisionTypes);
        cameraManager.update(playerController, *mapController);

        window.clear();

        // Réinitialiser la vue à la vue par défaut pour dessiner le fond d'écran fixe
        window.setView(window.getDefaultView());
        window.draw(backgroundSprite);

        // Définir la vue de la caméra
        window.setView(cameraManager.getView());

        // Dessiner la carte et le joueur
        mapController->draw(window);
        playerController.draw(window);

        window.display();
    }

    delete mapController;
}
