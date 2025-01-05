#include "ShopView.h"
#include <iostream>

// Constructeur
ShopView::ShopView() : selectedOption(0) {
    if (!font.loadFromFile("assets/police/Arial.ttf")) {
        std::cerr << "Erreur: Impossible de charger la police pour le ShopView." << std::endl;
    }

    background.setSize(sf::Vector2f(400.f, 300.f));
    background.setFillColor(sf::Color(128, 128, 128, 200));
    background.setPosition(200.f, 150.f);

    title.setFont(font);
    title.setString("Shop");
    title.setCharacterSize(30);
    title.setFillColor(sf::Color::White);
    title.setPosition(280.f, 160.f);

    statusMessage.setFont(font);
    statusMessage.setCharacterSize(20);
    statusMessage.setFillColor(sf::Color::Red);
    statusMessage.setPosition(220.f, 400.f);
}

// Destructeur
ShopView::~ShopView() {}

void ShopView::draw(sf::RenderWindow& window, const Player& player) {
    window.draw(background);
    window.draw(title);

    sf::Text coinsText("Coins: " + std::to_string(player.getCoins()), font, 20);
    coinsText.setPosition(220.f, 200.f);
    coinsText.setFillColor(sf::Color::White);
    window.draw(coinsText);

    sf::Text lifeButton("Acheter une vie (50 coins)", font, 20);
    sf::Text damageButton("Améliorer les dommages (50 coins)", font, 20);
    sf::Text exitButton("Retour", font, 20);

    sf::Text options[] = { lifeButton, damageButton, exitButton };
    float yPosition = 250.f;

    for (int i = 0; i < 3; ++i) {
        options[i].setPosition(220.f, yPosition);
        options[i].setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
        window.draw(options[i]);
        yPosition += 40.f;
    }

    if (!statusMessage.getString().isEmpty()) {
        window.draw(statusMessage);
    }
}


void ShopView::navigateUp() {
    selectedOption = (selectedOption - 1 + 3) % 3; // 3 options au total
}

void ShopView::navigateDown() {
    selectedOption = (selectedOption + 1) % 3;
}

std::string ShopView::getSelectedOption() const {
    switch (selectedOption) {
        case 0: return "Buy Life";
        case 1: return "Upgrade Damage";
        case 2: return "Exit";
        default: return "";
    }
}

void ShopView::setStatusMessage(const std::string& message) {
    statusMessage.setString(message);
}

// Gère les entrées utilisateur
void ShopView::handleInput(sf::Event event, int& selectedOption, bool& exitShop) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            navigateUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            navigateDown();
        } else if (event.key.code == sf::Keyboard::Enter) {
            selectedOption = this->selectedOption;
        } else if (event.key.code == sf::Keyboard::Escape) {
            exitShop = true;
        }
    }
}
