#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

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

class GameController {
public:
    GameController(TextureManager& textureManager);
    void run(sf::RenderWindow& window);

private:
    PlayerController playerController;
    ProjectileController projectileController;
    CollisionManager collisionManager;
    CameraManager cameraManager;
    InputManager inputManager;
    std::unique_ptr<MapController> mapController; // Use smart pointer
    FileReader fileReader;
    std::unordered_set<int> collisionTypes;
    std::unordered_set<int> teleportTiles;
    sf::Sprite backgroundSprite;
    TextureManager textureManager;
    EnemyController zombieController;
    EnemyController bossController;
    ZombieFactory zombieFactory;
    BossFactory bossFactory;
    World* currentWorld;
    int currentLevelIndex;

    void loadMap(const std::string& filename);
    void loadLevel(const Level& level);
};

#endif // GAMECONTROLLER_H