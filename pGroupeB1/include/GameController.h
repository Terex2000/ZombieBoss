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
#include <SFML/Graphics.hpp>
#include <unordered_set>

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
    MapController* mapController;
    FileReader fileReader;
    std::unordered_set<int> collisionTypes;
    std::unordered_set<int> teleportTiles;
    sf::Sprite backgroundSprite;
    TextureManager textureManager;
    EnemyController zombieController;
    EnemyController bossController;
    ZombieFactory zombieFactory;
    BossFactory bossFactory;
};

#endif // GAMECONTROLLER_H