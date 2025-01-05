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
    GameController(StateManager* stateManager, TextureManager& textureManager, const std::string& saveFile); // Add constructor for loading game
    void run(sf::RenderWindow& window);
    void update(float deltaTime);   
    void draw(sf::RenderWindow& window);
    WorldController& getWorldController();
        void saveGame(const std::string& filename); // Add this method to save the game state
            void loadGame(const std::string& filename); // Add this method to load the game state
              void saveTemporaryState(); // Add this method to save the temporary game state
    void loadTemporaryState(); // Add this method to load the temporary game state



private:
    StateManager* stateManager;
    PlayerController playerController;
    WorldController worldController;
    TextureManager& textureManager;
    sf::Sprite backgroundSprite;
    FileWriter fileWriter; // Add this member to handle file writing

    
};

#endif // GAMECONTROLLER_H