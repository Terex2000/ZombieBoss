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
#include <nlohmann/json.hpp> // Include the JSON library

class WorldController {
public:
    WorldController(TextureManager& textureManager, PlayerController& playerController);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void loadLevel(const Level& level);
    void loadBossRoom(const Level& level);
    bool checkTeleport(const sf::Vector2f& position);
    bool checkInstantDeath(const sf::Vector2f& position);
    void loadNextWorld(); // Add this method to load the next world
    int getCurrentWorldIndex() const; // Add this method to get the current world index
    int getWorldSize() const; // Add this method to get the size of the worlds vector
    int getCurrentLevelIndex() const; // Add this method to get the current level index
    int getLevelSize() const; // Add this method to get the size of the levels vector
    bool isInBossRoom() const; // Add this method to check if the player is in the boss room
    bool isBossRoomEmpty() const; // Add this method to check if the boss room is empty
    bool getPlayerLives() const; // Add this method to get the player's lives

    nlohmann::json getGameState() const; // Add this method to get the game state as JSON

    void setCurrentWorldIndex(int index); // Add this method to set the current world index
    void setCurrentLevelIndex(int index); // Add this method to set the current level index
    void setInBossRoom(bool inBossRoom); // Add this method to set the inBossRoom flag

    EnemyController& getZombieController(); // Add this method to get the zombie controller
    EnemyController& getBossController(); // Add this method to get the boss controller
        Player& getPlayer(); // Add this method to get the player object

    void teleportPlayerToBossRoom();
     std::vector<World> getWorlds() const;

private:
    PlayerController& playerController;
    CollisionManager collisionManager;
    CameraManager cameraManager;
    InputManager inputManager;
    std::unique_ptr<MapController> mapController; // Use smart pointer
    FileReader fileReader;
    std::unordered_set<int> collisionTypes;
    std::unordered_set<int> teleportTiles;
    std::unordered_set<int> instantDeathTiles; // Add this member to store instant death tiles
    TextureManager& textureManager;
    EnemyController zombieController;
    EnemyController bossController;
    ZombieFactory zombieFactory;
    BossFactory bossFactory;
    std::vector<World> worlds; // Add this member to store multiple worlds
    int currentWorldIndex; // Add this member to track the current world
    int currentLevelIndex;
    bool inBossRoom; // Add this flag to track if the player is in the boss room
    bool isBossDead;
    bool isPlayerDead;

    void loadMap(const std::string& filename);
    void loadTileset(const std::string& tileset); // Add this method to load the tileset
    void handleCollisions(); // Add this method to handle collisions
};

#endif // WORLDCONTROLLER_H