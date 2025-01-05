#include "HUDView.h"
#include <iostream>
#include <sstream> // Include this header for std::ostringstream
#include <iomanip> // Include this header for std::setprecision

// Constructor for HUDView
HUDView::HUDView() {
    // Load the font from a file
    if (!font.loadFromFile("assets/police/Arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    // Initialize player health text properties
    playerHealthText.setFont(font);
    playerHealthText.setCharacterSize(24);
    playerHealthText.setFillColor(sf::Color::White);

    // Initialize player damage text properties
    playerDamageText.setFont(font);
    playerDamageText.setCharacterSize(24);
    playerDamageText.setFillColor(sf::Color::White);

    // Initialize player lives text properties
    playerLivesText.setFont(font);
    playerLivesText.setCharacterSize(24);
    playerLivesText.setFillColor(sf::Color::White);

    // Initialize player coins text properties
    playerCoinsText.setFont(font);
    playerCoinsText.setCharacterSize(24);
    playerCoinsText.setFillColor(sf::Color::White);

    // Initialize boss health text properties
    bossHealthText.setFont(font);
    bossHealthText.setCharacterSize(24);
    bossHealthText.setFillColor(sf::Color::Red);
}

// Update the HUD with the player's and boss's current status
void HUDView::update(const Player& player, const Boss* boss) {
    // Update player health text
    std::ostringstream healthStream;
    healthStream << std::fixed << std::setprecision(1) << player.getHealth();
    playerHealthText.setString("Health: " + healthStream.str());

    // Update player damage text
    std::ostringstream damageStream;
    damageStream << std::fixed << std::setprecision(1) << player.getBulletDamage();
    playerDamageText.setString("Damage: " + damageStream.str());

    // Update player lives text
    playerLivesText.setString("Lives: " + std::to_string(player.getLives()));

    // Update player coins text
    std::ostringstream coinsStream;
    coinsStream << std::fixed << std::setprecision(1) << player.getCoins();
    playerCoinsText.setString("Coins: " + coinsStream.str());

    // Update boss health text if a boss exists
    if (boss) {
        std::ostringstream bossHealthStream;
        bossHealthStream << std::fixed << std::setprecision(1) << boss->getHealth();
        bossHealthText.setString("Boss Health: " + bossHealthStream.str());
    } else {
        bossHealthText.setString("");
    }
}

// Draw the HUD elements on the window
void HUDView::draw(sf::RenderWindow& window) {
    // Set positions for the HUD elements
    playerHealthText.setPosition(10, 10);
    playerDamageText.setPosition(10, 40);
    playerLivesText.setPosition(10, 70);
    playerCoinsText.setPosition(10, 100);
    bossHealthText.setPosition(10, 130);

    // Draw the HUD elements on the window
    window.draw(playerHealthText);
    window.draw(playerDamageText);
    window.draw(playerLivesText);
    window.draw(playerCoinsText);
    window.draw(bossHealthText);
}
