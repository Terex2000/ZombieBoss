#include "WorldController.h"
#include <iostream>

WorldController::WorldController(TextureManager& textureManager, PlayerController& playerController)
    : textureManager(textureManager), playerController(playerController), zombieController(zombieFactory, textureManager), bossController(bossFactory, textureManager), currentWorldIndex(0), currentLevelIndex(0), cameraManager(800.0f, 600.0f), inBossRoom(false) {
    // Initialize the worlds and levels
    std::cerr << "Create Worlds" << std::endl;
std::vector<World> worlds = {
        World({
            Level("assets/map/level.txt", "assets/map/bossMap.txt", 
                  {{800.0f, 544.0f, 100.0f, 10.0f, 50.0f, 100.0f, 10}, {600.0f, 544.0f, 100.0f, 10.0f, 50.0f, 50.0f, 5}}, 
                  {{800.0f, 544.0f, 500.0f, 50.0f, 30.0f, 200.0f, true, 20}}),
            Level("assets/map/map.txt", "assets/map/bossMap.txt", 
                  {{700.0f, 544.0f, 120.0f, 15.0f, 60.0f, 120.0f, 15}, {500.0f, 544.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8}}, 
                  {{700.0f, 544.0f, 600.0f, 60.0f, 35.0f, 250.0f, false, 25}})
        }, "assets/img/tileset.png"),
        World({
            Level("assets/map/map2.txt", "assets/map/bossMap2.txt", 
                  {{700.0f, 544.0f, 120.0f, 15.0f, 60.0f, 120.0f, 15}, {500.0f, 544.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8}}, 
                  {{700.0f, 544.0f, 600.0f, 60.0f, 35.0f, 250.0f, false, 25}}),
            Level("assets/map/map2.txt", "assets/map/bossMap2.txt", 
                  {{600.0f, 544.0f, 110.0f, 12.0f, 55.0f, 110.0f, 12}, {400.0f, 544.0f, 80.0f, 7.0f, 35.0f, 55.0f, 7}}, 
                  {{600.0f, 544.0f, 550.0f, 55.0f, 32.0f, 230.0f, true, 22}})
        }, "assets/img/tileset2.png")
    };
    std::cerr << "Create Worlds" << std::endl;
    this->worlds = worlds;
    std::cerr << "Load World" << std::endl;
    // Load the first world and level
    if (!worlds.empty() && !worlds[currentWorldIndex].getLevels().empty()) {
        loadTileset(worlds[currentWorldIndex].getTileset());
        loadLevel(worlds[currentWorldIndex].getLevels()[currentLevelIndex]);
    } else {
        std::cerr << "Error: Worlds or levels are not properly initialized." << std::endl;
    }
}

void WorldController::loadTileset(const std::string& tileset) {
    // Load the tileset texture
    if (!textureManager.loadTexture("tileset", tileset)) {
        std::cerr << "Error: Failed to load tileset texture" << std::endl;
    }
}

void WorldController::loadMap(const std::string& filename) {
    std::cerr << "Loading map: " << filename << std::endl;
    mapController.reset(); // Reset the smart pointer
    mapController = std::make_unique<MapController>(fileReader.readMap(filename), textureManager, fileReader.readTeleportTiles(filename));
    collisionTypes = fileReader.readCollisionTypes(filename);
    teleportTiles = fileReader.readTeleportTiles(filename);
    std::cout << "Total collision types: " << collisionTypes.size() << std::endl;
    std::cout << "Total teleport tiles: " << teleportTiles.size() << std::endl;
}

void WorldController::loadLevel(const Level& level) {
    std::cerr << "Loading level: " << level.getMapFile() << std::endl;
    loadMap(level.getMapFile());
    playerController.setPosition(100.0f, 100.0f); // Set player position at the start of the level
    zombieController.getEnemies().clear(); // Clear the zombies
    bossController.getEnemies().clear(); // Clear the bosses
    inBossRoom = false; // Reset the boss room flag

    // Create enemies for the level
    for (const auto& enemyInfo : level.getEnemies()) {
        zombieController.createEnemy(enemyInfo.x, enemyInfo.y, enemyInfo.health, enemyInfo.attack, enemyInfo.speed, enemyInfo.maxDistance, enemyInfo.coins);
    }
}

void WorldController::loadBossRoom(const Level& level) {
    std::cerr << "Loading boss room: " << level.getBossMapFile() << std::endl;
    loadMap(level.getBossMapFile());
    playerController.setPosition(100.0f, 100.0f); // Set player position at the start of the boss room
    zombieController.getEnemies().clear(); // Clear the zombies
    bossController.getEnemies().clear(); // Clear the bosses
    inBossRoom = true; // Set the boss room flag

    // Create the boss for the boss room
    for (const auto& bossInfo : level.getBosses()) {
        bossController.createBoss(bossInfo.x, bossInfo.y, bossInfo.health, bossInfo.attack, bossInfo.speed, bossInfo.maxDistance, bossInfo.isBoss, bossInfo.coins);
    }
}

void WorldController::update(float deltaTime) {
    // Handle player input
    inputManager.handleInput(playerController);
    playerController.update(deltaTime, cameraManager.getView());

    // Update enemies
    zombieController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer());
    bossController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer());

    // Check player collisions
    const auto& playerShape = playerController.getPlayerShape();
    const auto& mapData = mapController->getMap().getData();
    bool onGround = false;

    std::vector<sf::RectangleShape> collisionTiles;
    for (size_t i = 0; i < mapData.size(); ++i) {
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            const auto& tile = mapData[i][j];
            if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                sf::RectangleShape tileShape(sf::Vector2f(32, 32));
                tileShape.setPosition(tile.getX() * 32, tile.getY() * 32);
                collisionTiles.push_back(tileShape);
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

    // Handle enemy collisions
    collisionManager.checkProjectileEnemyCollisions(playerController.getProjectiles(), zombieController);
    collisionManager.checkProjectileEnemyCollisions(playerController.getProjectiles(), bossController);

    // Check enemy projectile collisions
    collisionManager.checkEnemyProjectileCollisions(zombieController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes, cameraManager.getView());
    collisionManager.checkEnemyProjectileCollisions(bossController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes, cameraManager.getView());

    // Check teleportation
    if (checkTeleport(playerController.getPlayer().getPosition())) {
        if (zombieController.getEnemies().empty() && bossController.getEnemies().empty()) {
            std::cerr << "Player teleported to boss room!" << std::endl;
            std::cerr << "Current level index before teleportation: " << currentLevelIndex << std::endl;
            if (currentLevelIndex >= 0 && currentLevelIndex < worlds[currentWorldIndex].getLevels().size()) {
                loadBossRoom(worlds[currentWorldIndex].getLevels()[currentLevelIndex]);
            } else {
                std::cerr << "Error: Invalid level index " << currentLevelIndex << std::endl;
            }
            std::cerr << "Player teleported to boss room!2" << std::endl;
            std::cerr << "Current level index after teleportation: " << currentLevelIndex << std::endl;
        } else {
            std::cerr << "Cannot teleport: Not all enemies are defeated." << std::endl;
        }
    }

    // Check if the boss is defeated
    if (inBossRoom && bossController.getEnemies().empty()) {
        if (currentLevelIndex == worlds[currentWorldIndex].getLevels().size() - 1) {
            std::cerr << "Final boss defeated! Game completed." << std::endl;
            // Optionally, you can reset the game or load the next world here
            if (currentWorldIndex < worlds.size() - 1) {
                currentWorldIndex++;
                currentLevelIndex = 0;
                loadTileset(worlds[currentWorldIndex].getTileset());
                loadLevel(worlds[currentWorldIndex].getLevels()[currentLevelIndex]);
            } else {
                std::cerr << "All worlds completed!" << std::endl;
            }
        } else {
            std::cerr << "Boss defeated! Loading next level." << std::endl;
            currentLevelIndex = (currentLevelIndex + 1) % worlds[currentWorldIndex].getLevels().size();
            std::cerr << "Next level index: " << currentLevelIndex << std::endl;
            if (currentLevelIndex >= 0 && currentLevelIndex < worlds[currentWorldIndex].getLevels().size()) {
                loadLevel(worlds[currentWorldIndex].getLevels()[currentLevelIndex]);
            } else {
                std::cerr << "Error: Invalid level index " << currentLevelIndex << std::endl;
            }
        }
    }

    // Update camera position
    cameraManager.update(playerController, *mapController);
}

void WorldController::draw(sf::RenderWindow& window) {
    // Set the camera view
    window.setView(cameraManager.getView());

    // Draw the map, player, and enemies
    mapController->draw(window);
    playerController.draw(window);
    zombieController.draw(window);
    bossController.draw(window);
}

bool WorldController::checkTeleport(const sf::Vector2f& position) {
    const auto& mapData = mapController->getMap().getData();
    int tileX = static_cast<int>(position.x / 32);
    int tileY = static_cast<int>(position.y / 32);

    if (tileX >= 0 && tileX < mapData[0].size() && tileY >= 0 && tileY < mapData.size()) {
        int tileType = mapData[tileY][tileX].getType();
        return teleportTiles.find(tileType) != teleportTiles.end();
    }

    return false;
}