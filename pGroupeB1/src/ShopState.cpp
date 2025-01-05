#include "ShopState.h"
#include "OnPauseState.h"

ShopState::ShopState(sf::RenderWindow& window, SoundManager& soundManager,
                     TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager, const std::string& tempFilePath)
    : window(window), stateManager(stateManager), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), shop(tempFilePath), exitShop(false) {}

void ShopState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            shopView.navigateUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            shopView.navigateDown();
        } else if (event.key.code == sf::Keyboard::Enter) {
            std::string selectedOption = shopView.getSelectedOption();
            if (selectedOption == "Buy Life") {
                if (!shop.buyLife(shopView)) {
                    errorMessage.setString("Not enough coins for life!"); // Afficher un message d'erreur
                }
            } else if (selectedOption == "Upgrade Damage") {
                if (!shop.upgradeDamage(shopView)) {
                    errorMessage.setString("Not enough coins for damage upgrade!"); // Afficher un message d'erreur
                }
            } else if (selectedOption == "Exit") {
                exitShop = true;
            }
        } else if (event.key.code == sf::Keyboard::Escape) {
            exitShop = true;
        }
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
    shopView.draw(window, shop);
    window.display();
}
