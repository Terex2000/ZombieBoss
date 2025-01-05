#include "ShopState.h"
#include "OnPauseState.h"
#include <fstream>


ShopState::ShopState(sf::RenderWindow& window, StateManager* stateManager, SoundManager& soundManager,
                     TextureManager& textureManager, InputManager& inputManager, Player& player)
    : window(window), stateManager(stateManager), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), player(player), shop(player), exitShop(false) {

      // Synchroniser les données du joueur avec celles du fichier JSON
    std::ifstream inputFile("save.json");
    if (inputFile.is_open()) {
        nlohmann::json gameState;
        inputFile >> gameState;
        inputFile.close();

        player.setCoins(gameState["player"]["coins"]);
        player.setLives(gameState["player"]["lives"]);
        player.setBulletDamage(gameState["player"]["bulletDamage"]);
    }
}

void ShopState::handleInput(sf::RenderWindow& window, sf::Event event) {
    int selectedOption = -1; // Initialise à -1 (aucune option sélectionnée)
    shopView.handleInput(event, selectedOption, exitShop);

    if (selectedOption == -1) return; // Aucune action si aucune option sélectionnée

    if (selectedOption == 0) { // Acheter une vie
        if (shop.buyLife("save.json")) {
            shopView.setStatusMessage("Life purchased successfully!");
        } else {
            shopView.setStatusMessage("Not enough coins for life!");
        }
    } else if (selectedOption == 1) { // Améliorer les dommages
        if (shop.upgradeDamage("save.json")) {
            shopView.setStatusMessage("Damage upgraded successfully!");
        } else {
            shopView.setStatusMessage("Not enough coins for damage upgrade!");
        }
    } else if (selectedOption == 2) { // Quitter le shop
        exitShop = true;
    }



    if (exitShop) {
        stateManager->setState(std::make_unique<OnPauseState>(
            window, soundManager, textureManager, inputManager, stateManager));
    }
}

void ShopState::update(sf::RenderWindow& window, double deltaTime) {
    if (exitShop) {
        stateManager->setState(std::make_unique<OnPauseState>(
            window, soundManager, textureManager, inputManager, stateManager));
    }
}

void ShopState::draw(sf::RenderWindow& window) {
    window.clear();
    shopView.draw(window, player);
    window.display();
}
