#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "TextureManager.h"
#include "PlayerController.h"
#include "WorldController.h"
#include <SFML/Graphics.hpp>

class GameController {
public:
    GameController(TextureManager& textureManager);
    void run(sf::RenderWindow& window);

private:
    PlayerController playerController;
    WorldController worldController;
    TextureManager& textureManager;
    sf::Sprite backgroundSprite; // Add this member to manage the background

    void handleInput(sf::Event event); // Add this method to handle input
};

#endif // GAMECONTROLLER_H