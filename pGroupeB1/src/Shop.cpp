#include "Shop.h"
#include <fstream>
#include <iostream>

Shop::Shop(Player& player) : player(player) {}

bool Shop::buyLife(const std::string& jsonFilePath) {
    const int lifeCost = 50;
    if (player.getCoins() >= lifeCost) {
        player.addCoins(-lifeCost);
        player.gainLife();
        updateJson(jsonFilePath);
        return true;
    }
    return false;
}

bool Shop::upgradeDamage(const std::string& jsonFilePath) {
    const int upgradeCost = 50;
    if (player.getCoins() >= upgradeCost) {
        player.addCoins(-upgradeCost);
        player.setBulletDamage(player.getBulletDamage() + 10);
        updateJson(jsonFilePath);
        return true;
    }
    return false;
}

void Shop::updateJson(const std::string& jsonFilePath) {
    std::ifstream inputFile(jsonFilePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open JSON file for reading: " << jsonFilePath << std::endl;
        return;
    }

    nlohmann::json gameState;
    inputFile >> gameState;
    inputFile.close();

    gameState["player"]["coins"] = player.getCoins();
    gameState["player"]["lives"] = player.getLives();
    gameState["player"]["bulletDamage"] = player.getBulletDamage();

    std::ofstream outputFile(jsonFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open JSON file for writing: " << jsonFilePath << std::endl;
        return;
    }

    outputFile << gameState.dump(4); // Sauvegarde le fichier avec une indentation
    outputFile.close();
}
