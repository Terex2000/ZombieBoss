// GameController.h
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "FileReader.h"
#include "MapController.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "PlayerController.h"
#include <unordered_set>

class GameController {
public:
    GameController();
    void run();

private:
    FileReader fileReader;
    TextureManager textureManager;
    MapController* mapController;
    InputManager inputManager;
    CollisionManager collisionManager;
    PlayerController playerController;
    std::unordered_set<int> collisionTypes;
};

#endif // GAMECONTROLLER_H