#include "WorldController.h"
#include <iostream>

WorldController::WorldController(TextureManager& textureManager, PlayerController& playerController)
    : textureManager(textureManager), playerController(playerController), zombieController(zombieFactory, textureManager), bossController(bossFactory, textureManager), currentWorldIndex(0), currentLevelIndex(0), cameraManager(800.0f, 600.0f), inBossRoom(false) {
    // Initialize the worlds and levels
    std::cerr << "Create Worlds" << std::endl;
    //Zombie : x, y, health, attack, speed, maxDistance, coins
    //Boss : x, y, health, attack, speed,coins, isBoss, maxDistance 
    std::vector<World> worlds = {
        World({
            Level("assets/map/mapW1L1.txt", "assets/map/bossMapW1.txt",
                  {{288.0f, 272.0f, 100.0f, 10.0f, 50.0f, 16.0f, 10},
                    {480.0f, 528.0f, 100.0f, 10.0f, 50.0f, 50.0f, 5},
                    {1184.0f, 208.0f, 100.0f, 10.0f, 50.0f, 90.0f, 10},
                    {1440.0f, 528.0f, 100.0f, 10.0f, 50.0f, 20.0f, 5},
                    {1696.0f, 528.0f, 100.0f, 10.0f, 50.0f, 100.0f, 5},
                    {2016.0f, 528.0f, 100.0f, 10.0f, 50.0f, 32.0f, 5},
                    {2464.0f, 528.0f, 100.0f, 10.0f, 50.0f, 10.0f, 5}},
                  {{544.0f, 475.0f, 500.0f, 50.0f, 30.0f, 200.0f, false, 20}}),
            Level("assets/map/mapW1L2.txt", "assets/map/bossMapW1.txt",
                  {
                    {704.0f, 560.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15},
                    {1280.0f, 304.0f, 90.0f, 8.0f, 40.0f, 50.0f, 8},
                    {1856.0f, 560.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15},
                    {2304.0f, 304.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15},
                    {2624.0f, 560.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15}
                  },
                  {{544.0f, 475.0f, 600.0f, 60.0f, 35.0f, 250.0f, false, 25}}),
            Level("assets/map/mapW1L3.txt", "assets/map/bossMapW1.txt",
                  {
                    {416.0f, 208.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15},
                    {720.0f, 208.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15},
                    {1216.0f, 368.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15},
                    {2048.0f, 208.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15},
                    {2432.0f, 304.0f, 120.0f, 15.0f, 60.0f, 50.0f, 15}
                  },
                  {{544.0f, 475.0f, 600.0f, 60.0f, 35.0f, 250.0f, false, 25}})
        }, "assets/img/tilesetW1.png", "assets/img/backgroundW1.jpg"),
        World({
            Level("assets/map/mapW2L1.txt", "assets/map/bossMapW2.txt",
                  {
                    {704.0f, 528.0f, 120.0f, 15.0f, 60.0f, 120.0f, 15},
                    {1184.0f, 400.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {1728.0f, 528.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {1984.0f, 528.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {1728.0f, 176.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {1152.0f, 176.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8}
                  },
                  {{544.0f, 475.0f, 600.0f, 60.0f, 35.0f, 250.0f, false, 25}}),
            Level("assets/map/mapW2L2.txt", "assets/map/bossMapW2.txt",
                  {
                    {1024.0f, 144.0f, 120.0f, 15.0f, 60.0f, 60.0f, 15},
                    {1152.0f, 144.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {1184.0f, 400.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {1312.0f, 528.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {1728.0f, 432.0f, 90.0f, 8.0f, 40.0f, 30.0f, 8},
                    {1952.0f, 432.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {2208.0f, 432.0f, 90.0f, 8.0f, 40.0f, 30.0f, 8},
                    {2976.0f, 208.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {3328.0f, 208.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {3328.0f, 400.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {3104.0f, 400.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {3072.0f, 560.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8},
                    {3456.0f, 560.0f, 90.0f, 8.0f, 40.0f, 60.0f, 8}
                  },
                  {{544.0f, 475.0f, 600.0f, 60.0f, 35.0f, 250.0f, true, 25}})
        }, "assets/img/tilesetW2.png", "assets/img/backgroundW2.png")
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
    instantDeathTiles = fileReader.readInstantDeathTiles(filename); // Load instant death tiles
    std::cout << "Total collision types: " << collisionTypes.size() << std::endl;
    std::cout << "Total teleport tiles: " << teleportTiles.size() << std::endl;
    std::cout << "Total instant death tiles: " << instantDeathTiles.size() << std::endl;
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
    playerController.getProjectiles().clear();
    zombieController.getProjectileController().getProjectiles().clear();
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
    zombieController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer(), cameraManager.getView());
    bossController.update(deltaTime, playerController.getPlayer().getPosition(), playerController.getPlayer(), cameraManager.getView());

    // Check player collisions
    collisionManager.checkPlayerCollisions(playerController, mapController->getMap(), collisionTypes);

    // Handle enemy collisions
    collisionManager.checkProjectileEnemyCollisions(playerController.getProjectiles(), zombieController);
    collisionManager.checkProjectileEnemyCollisions(playerController.getProjectiles(), bossController);

    // Check enemy projectile collisions
    collisionManager.checkEnemyProjectileCollisions(zombieController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes);
    collisionManager.checkEnemyProjectileCollisions(bossController.getProjectileController().getProjectiles(), playerController, mapController->getMap(), collisionTypes);

    // Check projectile collisions with the map
    for (auto& projectile : playerController.getProjectiles()) {
        if (collisionManager.checkProjectileCollisions(projectile, mapController->getMap(), collisionTypes)) {
            playerController.getProjectiles().clear();
        }
    }

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

    // Check if the player is on an instant death tile
    if (checkInstantDeath(playerController.getPlayer().getPosition())) {
        std::cerr << "Player hit an instant death tile! Respawning..." << std::endl;
        playerController.getPlayer().takeDamage(100.0f); // Instantly kill the player
        playerController.setPosition(100.0f, 100.0f); // Reset player position to the start of the level
    }

    // Check if the boss is defeated
    if (inBossRoom && bossController.getEnemies().empty()) {
        isBossDead = true;
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
    } else {
        isBossDead = false;
    }

    if (playerController.getPlayer().getLives() <= 0) {
        isPlayerDead = true;
    }

    // Update camera position
    cameraManager.update(playerController, *mapController);
}

void WorldController::draw(sf::RenderWindow& window) {
    // Set the camera view
    window.setView(window.getDefaultView());

    // Draw the background
    const sf::Sprite& background = worlds[currentWorldIndex].getBackground();
    textureManager.adjustSpriteToWindow(const_cast<sf::Sprite&>(background), window);
    window.draw(background);

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
bool WorldController::checkInstantDeath(const sf::Vector2f& position) {
    const auto& mapData = mapController->getMap().getData();
    int tileX = static_cast<int>(position.x / 32);
    int tileY = static_cast<int>(position.y / 32);

    if (tileX >= 0 && tileX < mapData[0].size() && tileY >= 0 && tileY < mapData.size()) {
        int tileType = mapData[tileY][tileX].getType();
        return instantDeathTiles.find(tileType) != instantDeathTiles.end();
    }

    return false;
}

    int WorldController::getCurrentWorldIndex() const {
        return currentWorldIndex;
    }

    int WorldController::getWorldSize() const {
        return worlds.size();
    }

    int WorldController::getCurrentLevelIndex() const {
        return currentLevelIndex;
    }

    int WorldController::getLevelSize() const {
        return worlds[currentWorldIndex].getLevels().size();
    }

    bool WorldController::isInBossRoom() const {
        return inBossRoom;
    }

    bool WorldController::isBossRoomEmpty() const {
        return isBossDead;
    }

    bool WorldController::getPlayerLives() const {
        return isPlayerDead;
    }

nlohmann::json WorldController::getGameState() const {
    nlohmann::json gameState;

    // Save player state
    gameState["player"]["position"] = { playerController.getPlayer().getPosition().x, playerController.getPlayer().getPosition().y };
    gameState["player"]["health"] = playerController.getPlayer().getHealth();
    gameState["player"]["lives"] = playerController.getPlayer().getLives();
    gameState["player"]["coins"] = playerController.getPlayer().getCoins();
    gameState["player"]["bulletDamage"] = playerController.getPlayer().getBulletDamage();
    gameState["player"]["direction"] = playerController.getPlayer().getDirection();
    gameState["player"]["state"] = playerController.getPlayer().getState();
    gameState["player"]["onGround"] = playerController.isOnGround();

    // Save world state
    gameState["world"]["currentWorldIndex"] = currentWorldIndex;
    gameState["world"]["currentLevelIndex"] = currentLevelIndex;
    gameState["world"]["inBossRoom"] = inBossRoom;

    // Save enemies state
    for (const auto& enemy : zombieController.getEnemies()) {
        gameState["enemies"]["zombies"].push_back({
            { "position", { enemy->getinitialPosition().x, enemy->getinitialPosition().y } },
            { "health", enemy->getHealth() },
            {"attack", enemy->getAttack() },
            {"speed", enemy->getSpeed() },
            {"maxDistance", enemy->getMaxDistance() },
            {"coins", enemy->getCoins() }
        });
    }

    for (const auto& boss : bossController.getEnemies()) {
        gameState["enemies"]["bosses"].push_back({
            { "position", { boss->getinitialPosition().x, boss->getinitialPosition().y } },
            { "health", boss->getHealth() },
            {"attack", boss->getAttack() },
            {"speed", boss->getSpeed() },
            {"maxDistance", boss->getMaxDistance() },
            {"isFinalBoss", boss->isFinalBoss() },
            {"coins", boss->getCoins() },
            {"shield", boss->getShield() }
        });
    }

    return gameState;
}

void WorldController::setCurrentWorldIndex(int index) {
    currentWorldIndex = index;
}

void WorldController::setCurrentLevelIndex(int index) {
    currentLevelIndex = index;
}

void WorldController::setInBossRoom(bool inBossRoom) {
    this->inBossRoom = inBossRoom;
}


EnemyController& WorldController::getZombieController() {
    return zombieController;
}

EnemyController& WorldController::getBossController() {
    return bossController;
}

Player& WorldController::getPlayer() {
    return playerController.getPlayer();
}

void WorldController::teleportPlayerToBossRoom() {
    if (inBossRoom) {
        if (currentLevelIndex >= 0 && currentLevelIndex < worlds[currentWorldIndex].getLevels().size()) {
            loadBossRoom(worlds[currentWorldIndex].getLevels()[currentLevelIndex]);
        } else {
            std::cerr << "Error: Invalid level index " << currentLevelIndex << std::endl;
        }
    }
}

 std::vector<World> WorldController::getWorlds() const {
     return worlds;
}