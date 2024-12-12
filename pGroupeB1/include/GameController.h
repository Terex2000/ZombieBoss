#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "FileReader.h"
#include "PlayerController.h"
#include "ProjectileController.h"
#include "CollisionManager.h"
#include "CameraManager.h"
#include "InputManager.h"
#include "MapController.h"
#include <SFML/Graphics.hpp>
#include <unordered_set>

class GameController {
public:
    GameController();
    void run();

private:
    PlayerController playerController;
    ProjectileController projectileController;
    CollisionManager collisionManager;
    CameraManager cameraManager;
    InputManager inputManager;
    MapController* mapController;
    FileReader fileReader;
    std::unordered_set<int> collisionTypes;
    sf::Sprite backgroundSprite;
    TextureManager textureManager;
};

#endif // GAMECONTROLLER_H