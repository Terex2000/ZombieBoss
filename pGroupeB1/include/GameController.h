#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "FileReader.h"
#include "MapController.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "PlayerController.h"
#include "CameraManager.h"
#include <unordered_set>
#include <SFML/Graphics.hpp>

class GameController {
public:
    GameController(TextureManager& textureManager); // Injecter le TextureManager
    void run(sf::RenderWindow& window); // Utiliser la fenêtre existante

private:
    FileReader fileReader;
    TextureManager& textureManager;
    MapController* mapController;
    InputManager inputManager;
    CollisionManager collisionManager;
    PlayerController playerController;
    CameraManager cameraManager;
    std::unordered_set<int> collisionTypes;
    sf::Sprite backgroundSprite;
};

#endif // GAMECONTROLLER_H
