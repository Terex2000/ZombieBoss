#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "TextureManager.h"
#include "PlayerController.h"
#include "WorldController.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>

class GameController {
public:
    GameController(StateManager* stateManager, TextureManager& textureManager);
    void run(sf::RenderWindow& window);
    void update(float deltaTime);   
    void draw(sf::RenderWindow& window);

private:
    StateManager* stateManager;
    PlayerController playerController;
    WorldController worldController;
    TextureManager& textureManager;
    sf::Sprite backgroundSprite;

    
};

#endif // GAMECONTROLLER_H