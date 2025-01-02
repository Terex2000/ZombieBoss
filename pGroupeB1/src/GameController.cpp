#include "GameController.h"
#include <iostream>

GameController::GameController(TextureManager& textureManager)
    : playerController(100.0f, 100.0f, textureManager), cameraManager(800.0f, 600.0f), textureManager(textureManager), 
      zombieController(zombieFactory, textureManager), bossController(bossFactory, textureManager) {
    // Load textures
    if (!textureManager.loadTexture("tileset", "assets/img/tileset.png")) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
    if (!textureManager.loadTexture("background", "assets/img/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }
    if (!textureManager.loadTexture("bullet", "assets/img/bullet.png")) {
        std::cerr << "Error: Failed to load bullet texture" << std::endl;
    }
    if (!textureManager.loadTexture("zombie", "assets/img/zombie.png")) {
        std::cerr << "Error: Failed to load zombie texture" << std::endl;
    }

    // Initialize map controller with map data and textures
    mapController = new MapController(fileReader.readMap("assets/map/map.txt"), textureManager, fileReader.readTeleportTiles("assets/map/map.txt"));
    collisionTypes = fileReader.readCollisionTypes("assets/map/map.txt");
    teleportTiles = fileReader.readTeleportTiles("assets/map/map.txt");
    std::cout << "Total teleport tiles: " << teleportTiles.size() << std::endl;


    std::cout << "Total collision types: " << collisionTypes.size() << std::endl;

    // Create the sprite for the background
    backgroundSprite.setTexture(textureManager.getTexture("background"));

    // Create some enemies
    zombieController.createEnemy(800.0f, 256.0f, 100.0f, 10.0f, 50.0f, 100.0f, 10); // Example max distance and coins
    zombieController.createEnemy(128.0f, 768.0f, 100.0f, 10.0f, 50.0f, 50.0f, 5); // Example max distance and coins

    
    
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
        }

        float deltaTime = clock.restart().asSeconds();

        // Handle player input
        inputManager.handleInput(playerController);
        playerController.update(deltaTime, cameraManager.getView());

        // Check player collisions
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
                        if (playerController.isOnGround()) {
                            onGround = true;
                        }
                    }
                }
            }
        }

        playerController.setOnGround(onGround);

        if (mapController->checkTeleport(playerController.getPlayer().getPosition())) {
            if (!textureManager.loadTexture("tileset", "assets/img/tileset.png")) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
            std::cout << "Teleporting to boss room!" << std::endl;
            mapController = new MapController(fileReader.readMap("assets/map/bossMap.txt"), textureManager, fileReader.readTeleportTiles("assets/map/bossMap.txt"));
            collisionTypes = fileReader.readCollisionTypes("assets/map/bossMap.txt");
            std::cout << "Total Collision tiles: " << collisionTypes.size() << std::endl;
            teleportTiles = fileReader.readTeleportTiles("assets/map/bossMap.txt");
            std::cout << "Total teleport tiles: " << teleportTiles.size() << std::endl;
            
            playerController.setPosition(100.0f, 100.0f); // Set player position in the boss room
            zombieController.getEnemies().clear(); // Clear the zombies
            // Create a boss
            bossController.createBoss(544.0f, 510.0f, 10.0f, 20.0f, 30.0f, 50, true, 50.0); // Example boss

        }

        // Check projectile collisions
        auto& projectiles = playerController.getProjectiles();
        for (auto it = projectiles.begin(); it != projectiles.end();) {
            if (collisionManager.checkProjectileCollisions(*it, mapController->getMap(), collisionTypes)) {
                it = playerController.getProjectiles().erase(it);
            } else {
                ++it;
            }
        }

        // Check projectile-enemy collisions
        collisionManager.checkProjectileEnemyCollisions(projectiles, zombieController);
        collisionManager.checkProjectileEnemyCollisions(projectiles, bossController);

        // Update enemies
        zombieController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer());
        bossController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer());

        // Check enemy projectile collisions
        collisionManager.checkEnemyProjectileCollisions(zombieController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes, cameraManager.getView());
        collisionManager.checkEnemyProjectileCollisions(bossController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes, cameraManager.getView());

        // Update camera position
        cameraManager.update(playerController, *mapController);

        window.clear();

        // Reset the view to the default view to draw the fixed background
        window.setView(window.getDefaultView());
        window.draw(backgroundSprite);

        // Set the camera view
        window.setView(cameraManager.getView());

        // Draw the map, player, and enemies
        mapController->draw(window);
        playerController.draw(window);
        zombieController.draw(window);
        bossController.draw(window);

        window.display();
    }

    delete mapController;
}