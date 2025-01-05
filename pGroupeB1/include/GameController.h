#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "TextureManager.h"
#include "PlayerController.h"
#include "WorldController.h"
#include "StateManager.h"
#include "FileWriter.h"
#include <SFML/Graphics.hpp>

class GameController {
public:
    GameController(StateManager* stateManager, TextureManager& textureManager);
    void run(sf::RenderWindow& window);
    void update(float deltaTime);   
    void draw(sf::RenderWindow& window);
    WorldController& getWorldController();
        void saveGame(const std::string& filename); // Add this method to save the game state


private:
    StateManager* stateManager;
    PlayerController playerController;
    WorldController worldController;
    TextureManager& textureManager;
    sf::Sprite backgroundSprite;
    FileWriter fileWriter; // Add this member to handle file writing

    
};

#endif // GAMECONTROLLER_H