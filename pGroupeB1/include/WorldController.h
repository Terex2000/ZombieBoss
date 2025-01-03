#ifndef WORLDCONTROLLER_H
#define WORLDCONTROLLER_H

#include "FileReader.h"
#include "PlayerController.h"
#include "ProjectileController.h"
#include "CollisionManager.h"
#include "CameraManager.h"
#include "InputManager.h"
#include "MapController.h"
#include "EnemyController.h"
#include "ZombieFactory.h"
#include "BossFactory.h"
#include "World.h"
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include <memory> // Include for smart pointers

class WorldController {
public:
    WorldController(TextureManager& textureManager, PlayerController& playerController);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void loadLevel(const Level& level);
    void loadBossRoom(const Level& level);
    bool checkTeleport(const sf::Vector2f& position);
    void loadNextWorld(); // Add this method to load the next world

private:
    PlayerController& playerController;
    CollisionManager collisionManager;
    CameraManager cameraManager;
    InputManager inputManager;
    std::unique_ptr<MapController> mapController; // Use smart pointer
    FileReader fileReader;
    std::unordered_set<int> collisionTypes;
    std::unordered_set<int> teleportTiles;
    TextureManager& textureManager;
    EnemyController zombieController;
    EnemyController bossController;
    ZombieFactory zombieFactory;
    BossFactory bossFactory;
    std::vector<World> worlds; // Add this member to store multiple worlds
    int currentWorldIndex; // Add this member to track the current world
    int currentLevelIndex;
    bool inBossRoom; // Add this flag to track if the player is in the boss room

    void loadMap(const std::string& filename);
    void loadTileset(const std::string& tileset); // Add this method to load the tileset
};

#endif // WORLDCONTROLLER_H