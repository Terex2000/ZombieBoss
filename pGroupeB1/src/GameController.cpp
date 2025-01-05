#include "GameController.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

// Constructor: Initializes the GameController with a state manager and texture manager
GameController::GameController(StateManager* stateManager, TextureManager& textureManager)
    : stateManager(stateManager), playerController(100.0f, 100.0f, textureManager), worldController(textureManager, playerController), textureManager(textureManager) {}

// Constructor: Initializes the GameController and loads a saved game state from a file
GameController::GameController(StateManager* stateManager, TextureManager& textureManager, const std::string& saveFile)
    : stateManager(stateManager), playerController(100.0f, 100.0f, textureManager), worldController(textureManager, playerController), textureManager(textureManager) {
    loadGame(saveFile);
}

// Main game loop: Runs the game, handling events, updating the world, and rendering
void GameController::run(sf::RenderWindow& window) {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        // Update world
        worldController.update(deltaTime);

        window.clear();

        // Draw world
        worldController.draw(window);

        window.display();
    }
}

// Updates the game state
void GameController::update(float deltaTime) {
    // Update world
    worldController.update(deltaTime);
}

// Renders the game state
void GameController::draw(sf::RenderWindow& window) {
    worldController.draw(window);
}

// Returns a reference to the world controller
WorldController& GameController::getWorldController() {
    return worldController;
}

// Saves the current game state to a file
void GameController::saveGame(const std::string& filename) {
    nlohmann::json gameState = worldController.getGameState();
    fileWriter.saveGameState(filename, gameState);
}

// Loads a game state from a file
void GameController::loadGame(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        nlohmann::json gameState;
        file >> gameState;

        // Load player state
        playerController.getPlayer().setPosition(gameState["player"]["position"][0], gameState["player"]["position"][1]);
        playerController.getPlayer().setHealth(gameState["player"]["health"]);
        playerController.getPlayer().setLives(gameState["player"]["lives"]);
        playerController.getPlayer().setCoins(gameState["player"]["coins"]);
        playerController.getPlayer().setBulletDamage(gameState["player"]["bulletDamage"]);
        playerController.getPlayer().setDirection(gameState["player"]["direction"]);
        playerController.getPlayer().setState(static_cast<Player::State>(gameState["player"]["state"]));
        playerController.setOnGround(gameState["player"]["onGround"]);

        // Load world state
        worldController.setCurrentWorldIndex(gameState["world"]["currentWorldIndex"]);
        worldController.setCurrentLevelIndex(gameState["world"]["currentLevelIndex"]);
        worldController.setInBossRoom(gameState["world"]["inBossRoom"]);

        // Teleport player to boss room if necessary
        if (worldController.isInBossRoom()) {
            worldController.teleportPlayerToBossRoom();
            playerController.getPlayer().setPosition(gameState["player"]["position"][0], gameState["player"]["position"][1]);
        } else {
            // Load the regular level map
            worldController.loadLevel(worldController.getWorlds()[worldController.getCurrentWorldIndex()].getLevels()[worldController.getCurrentLevelIndex()]);
            playerController.getPlayer().setPosition(gameState["player"]["position"][0], gameState["player"]["position"][1]);
        }

        // Load enemies state
        worldController.getZombieController().getEnemies().clear();
        for (const auto& enemyState : gameState["enemies"]["zombies"]) {
            worldController.getZombieController().createEnemy(enemyState["position"][0], enemyState["position"][1], enemyState["health"], enemyState["attack"], enemyState["speed"], enemyState["maxDistance"], enemyState["coins"]);
        }

        worldController.getBossController().getEnemies().clear();
        for (const auto& bossState : gameState["enemies"]["bosses"]) {
            worldController.getBossController().createBoss(bossState["position"][0], bossState["position"][1], bossState["health"], bossState["attack"], bossState["speed"], bossState["coins"], bossState["isFinalBoss"], bossState["shield"]);
        }
    } else {
        std::cerr << "Error: Unable to open save file: " << filename << std::endl;
    }
}

// Saves the current game state to a temporary file
void GameController::saveTemporaryState() {
    saveGame("temp_save.json");
}

// Loads the game state from a temporary file
void GameController::loadTemporaryState() {
    loadGame("temp_save.json");
}
