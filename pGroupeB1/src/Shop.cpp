#include "Shop.h"
#include "ShopView.h"
#include <iostream>
#include <fstream>

Shop::Shop(const std::string& tempFilePath) : tempFilePath(tempFilePath) {}

nlohmann::json Shop::loadGameState() {
    nlohmann::json gameState;
    std::ifstream file(tempFilePath);
    if (file.is_open()) {
        file >> gameState;
        file.close();
    } else {
        std::cerr << "Error: Unable to open temporary save file." << std::endl;
    }
    return gameState;
}

void Shop::saveGameState(const nlohmann::json& gameState) {
    std::ofstream outFile(tempFilePath);
    if (outFile.is_open()) {
        outFile << gameState.dump(4); // Pretty print with 4 spaces
        outFile.close();
    } else {
        std::cerr << "Error: Unable to open temporary save file for writing." << std::endl;
    }
}

bool Shop::buyLife(ShopView& shopView) {
    const int lifeCost = 50; // Exemple : 50 pièces
    nlohmann::json gameState = loadGameState();

    int coins = gameState["player"]["coins"];
    if (coins >= lifeCost) {
        coins -= lifeCost;
        int lives = gameState["player"]["lives"];
        lives += 1;

        // Update the game state
        gameState["player"]["coins"] = coins;
        gameState["player"]["lives"] = lives;

        // Save the updated game state
        saveGameState(gameState);

        // Update the shop view
        shopView.update(coins);
        std::cerr << "Buy Life" << std::endl;
        return true;
    }
    std::cerr << "Not enough coins!" << std::endl;
    return false;
}

bool Shop::upgradeDamage(ShopView& shopView) {
    const int upgradeCost = 50; // Exemple : 50 pièces
    nlohmann::json gameState = loadGameState();

    int coins = gameState["player"]["coins"];
    if (coins >= upgradeCost) {
        coins -= upgradeCost;
        int bulletDamage = gameState["player"]["bulletDamage"];
        bulletDamage += 10;

        // Update the game state
        gameState["player"]["coins"] = coins;
        gameState["player"]["bulletDamage"] = bulletDamage;

        // Save the updated game state
        saveGameState(gameState);

        // Update the shop view
        shopView.update(coins);
                std::cerr << "Buy damage" << std::endl;

        return true;
    }
    std::cerr << "Not enough coins!" << std::endl;
    return false;
}

int Shop::getCoins() {
    nlohmann::json gameState = loadGameState();
    return gameState["player"]["coins"];
}
