#include "HUDView.h"
#include <iostream>

HUDView::HUDView() {
    if (!font.loadFromFile("assets/police/Arial.ttf")) {
        std::cerr << "Error loading font for HUDView!" << std::endl;
    }

    playerHealthText.setFont(font);
    playerHealthText.setCharacterSize(20);
    playerHealthText.setFillColor(sf::Color::White);

    playerDamageText.setFont(font);
    playerDamageText.setCharacterSize(20);
    playerDamageText.setFillColor(sf::Color::White);

    playerLivesText.setFont(font);
    playerLivesText.setCharacterSize(20);
    playerLivesText.setFillColor(sf::Color::White);

    playerCoinsText.setFont(font);
    playerCoinsText.setCharacterSize(20);
    playerCoinsText.setFillColor(sf::Color::White);

    bossHealthText.setFont(font);
    bossHealthText.setCharacterSize(20);
    bossHealthText.setFillColor(sf::Color::Red);
}

void HUDView::update(const Player& player, const Boss* boss) {
    playerHealthText.setString("Health: " + std::to_string(player.getHealth()));
    playerDamageText.setString("Damage: " + std::to_string(player.getBulletDamage()));
    playerLivesText.setString("Lives: " + std::to_string(player.getLives()));
    playerCoinsText.setString("Coins: " + std::to_string(player.getCoins()));

    if (boss) {
        bossHealthText.setString("Boss Health: " + std::to_string(boss->getHealth()));
    } else {
        bossHealthText.setString("");
    }
}

void HUDView::draw(sf::RenderWindow& window) {
    playerHealthText.setPosition(10, 10);
    playerDamageText.setPosition(10, 40);
    playerLivesText.setPosition(10, 70);
    playerCoinsText.setPosition(10, 100);
    bossHealthText.setPosition(10, 130);

    window.draw(playerHealthText);
    window.draw(playerDamageText);
    window.draw(playerLivesText);
    window.draw(playerCoinsText);
    if (!bossHealthText.getString().isEmpty()) {
        window.draw(bossHealthText);
    }
}
