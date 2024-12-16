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
#include <unordered_set>//Offers amortized constant-time search, 
                        //Inserting elements into an unordered_set is also amortized constant-time, O(1) 
                        //and does not allow duplicates.

// The GameController class is responsible for managing the game loop and coordinating
// interactions between different components of the game.
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