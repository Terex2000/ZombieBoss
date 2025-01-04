#include "GameController.h"
#include <iostream>

GameController::GameController(StateManager* stateManager, TextureManager& textureManager)
    : playerController(100.0f, 100.0f, textureManager), cameraManager(800.0f, 600.0f), textureManager(textureManager),
      zombieController(zombieFactory, textureManager), bossController(bossFactory, textureManager), stateManager(stateManager) {
    // Load textures
    if (!textureManager.loadTexture("tileset", "assets/img/tileset.png")) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
    if (!textureManager.loadTexture("background", "assets/img/background.jpg")) {
        std::cerr << "Error: Failed to load background texture" << std::endl;
    }

    // Initialize map controller with map data and textures
    mapController = new MapController(fileReader.readMap("assets/map/map.txt"), textureManager, fileReader.readTeleportTiles("assets/map/map.txt"));
    collisionTypes = fileReader.readCollisionTypes("assets/map/map.txt");
    teleportTiles = fileReader.readTeleportTiles("assets/map/map.txt");

    // Create the sprite for the background
    backgroundSprite.setTexture(textureManager.getTexture("background"));

    // Create some enemies
    zombieController.createEnemy(800.0f, 544.0f, 100.0f, 10.0f, 50.0f, 100.0f, 10); // Example max distance and coins
    zombieController.createEnemy(600.0f, 544.0f, 100.0f, 10.0f, 50.0f, 50.0f, 5); // Example max distance and coins



}



GameController::~GameController() {
    delete mapController;
}


void GameController::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Left:
                playerController.move(-5.0f, 0.0f); // Exemple pour déplacer à gauche
                break;
            case sf::Keyboard::Right:
                playerController.move(5.0f, 0.0f); // Exemple pour déplacer à droite
                break;
            case sf::Keyboard::Space:
                playerController.jump(); // Faire sauter le joueur
                break;
            case sf::Keyboard::Z: // Touche pour tirer
                playerController.shoot();
                break;
            default:
                break;
        }
    }
}

void GameController::draw(sf::RenderWindow& window) {
    // Dessiner les éléments de jeu
    window.setView(window.getDefaultView());
    window.draw(backgroundSprite);

    window.setView(cameraManager.getView());
    mapController->draw(window);
    playerController.draw(window);
    zombieController.draw(window);
    bossController.draw(window);
}

void GameController::update(float deltaTime) {
    handleCollisions();

    // Mettre à jour les entités du jeu
    playerController.update(deltaTime, cameraManager.getView());
    zombieController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer());
    bossController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer());

    // Mettre à jour la caméra
    cameraManager.update(playerController, *mapController);
}

void GameController::loadMap(const std::string& mapPath) {
    mapController = new MapController(fileReader.readMap(mapPath), textureManager, fileReader.readTeleportTiles(mapPath));
    collisionTypes = fileReader.readCollisionTypes(mapPath);
    teleportTiles = fileReader.readTeleportTiles(mapPath);
}

void GameController::handleCollisions() {
    const auto& playerShape = playerController.getPlayerShape();
    const auto& mapData = mapController->getMap().getData();
    bool onGround = false;

    // Vérification des collisions avec la carte
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

    // Gestion de la téléportation
    if (mapController->checkTeleport(playerController.getPlayer().getPosition())) {
        std::cout << "Teleporting to boss room!" << std::endl;
        loadMap("assets/map/bossMap.txt");
        playerController.setPosition(100.0f, 100.0f);
        zombieController.getEnemies().clear();
        bossController.createBoss(544.0f, 510.0f, 10.0f, 20.0f, 30.0f, 50, true, 50.0);
    }

    // Vérification des collisions avec les projectiles
    auto& projectiles = playerController.getProjectiles();
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        if (collisionManager.checkProjectileCollisions(*it, mapController->getMap(), collisionTypes)) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }

    // Collisions entre projectiles et ennemis
    collisionManager.checkProjectileEnemyCollisions(projectiles, zombieController);
    collisionManager.checkProjectileEnemyCollisions(projectiles, bossController);

    // Collisions entre projectiles ennemis et joueur
    collisionManager.checkEnemyProjectileCollisions(zombieController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes, cameraManager.getView());
    collisionManager.checkEnemyProjectileCollisions(bossController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes, cameraManager.getView());
}

