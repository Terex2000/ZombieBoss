#include "GameController.h"
#include <iostream>

GameController::GameController()
    : playerController(100.0f, 100.0f, textureManager), cameraManager(800.0f, 600.0f) // Initial position of the player and camera size
{
    if (!textureManager.loadTexture("tileset", "assets/img/tileset.png")) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
    if (!textureManager.loadTexture("background", "assets/img/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }
    if (!textureManager.loadTexture("bullet", "assets/img/bullet.png")) {
        std::cerr << "Error: Failed to load bullet texture" << std::endl;
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
        playerController.update(deltaTime, cameraManager.getView());

        // Vérification des collisions du joueur
        const auto& playerShape = playerController.getPlayerShape();
        const auto& mapData = mapController->getMap().getData();
        bool onGround = false;

        for (size_t i = 0; i < mapData.size(); ++i) {
            for (size_t j = 0; j < mapData[i].size(); ++j) {
                const auto& tile = mapData[i][j];
                if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                    sf::RectangleShape tileShape(sf::Vector2f(32, 32));
                    tileShape.setPosition(tile.getX() * 32, tile.getY() * 32);
                    if (collisionManager.isColliding(playerShape, tileShape)) {
                        playerController.handleCollision(tileShape);
                        onGround = true;
                    }
                }
            }
        }

        playerController.setOnGround(onGround);

        // Vérification des collisions des projectiles
        auto& projectiles = playerController.getProjectiles();
        for (auto it = projectiles.begin(); it != projectiles.end();) {
            if (collisionManager.checkProjectileCollisions(*it, mapController->getMap(), collisionTypes)) {
                it = playerController.getProjectiles().erase(it);
            } else {
                ++it;
            }
        }

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