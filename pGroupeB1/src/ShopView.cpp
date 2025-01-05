#include "ShopView.h"
#include <iostream>

// Constructor
ShopView::ShopView() : selectedOption(0) {
    // Load the font
    if (!font.loadFromFile("assets/police/Arial.ttf")) {
        std::cerr << "Error: Unable to load font for ShopView." << std::endl;
    }

    // Initialize the background
    background.setSize(sf::Vector2f(400.f, 300.f));
    background.setFillColor(sf::Color(128, 128, 128, 200));
    background.setPosition(200.f, 150.f);

    // Initialize the title
    title.setFont(font);
    title.setString("Shop");
    title.setCharacterSize(30);
    title.setFillColor(sf::Color::White);
    title.setPosition(280.f, 160.f);

    // Initialize the error message
    errorMessage.setFont(font);
    errorMessage.setCharacterSize(20);
    errorMessage.setFillColor(sf::Color::Red);
    errorMessage.setPosition(220.f, 400.f);
}

// Destructor
ShopView::~ShopView() {}

// Draws the shop on the screen
void ShopView::draw(sf::RenderWindow& window, Shop& shop) {
    // Draw the background
    window.draw(background);

    // Draw the title
    window.draw(title);

    // Display the player's coin balance
    sf::Text coinsText("Coins: " + std::to_string(shop.getCoins()), font, 20);
    coinsText.setPosition(220.f, 200.f);
    coinsText.setFillColor(sf::Color::White);
    window.draw(coinsText);

    // Display the options
    sf::Text lifeButton("Buy Life (50 coins)", font, 20);
    sf::Text damageButton("Upgrade Damage (50 coins)", font, 20);
    sf::Text exitButton("Exit", font, 20);

    // Menu options
    sf::Text options[] = { lifeButton, damageButton, exitButton };
    float yPosition = 250.f;

    for (int i = 0; i < 3; ++i) {
        options[i].setPosition(220.f, yPosition);
        options[i].setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
        window.draw(options[i]);
        yPosition += 40.f;
    }

    // Draw the error message if present
    if (!errorMessage.getString().isEmpty()) {
        window.draw(errorMessage);
    }
}

// Updates the display of coins
void ShopView::update(int coins) {
    // Update the coin display
    errorMessage.setString(""); // Clear any previous error message

    // Update the coin display
    sf::Text coinsText("Coins: " + std::to_string(coins), font, 20);
    coinsText.setPosition(220.f, 200.f);
}

// Navigate up through the menu options
void ShopView::navigateUp() {
    selectedOption = (selectedOption - 1 + 3) % 3; // 3 options in total
}

// Navigate down through the menu options
void ShopView::navigateDown() {
    selectedOption = (selectedOption + 1) % 3;
}

// Get the currently selected option
std::string ShopView::getSelectedOption() const {
    switch (selectedOption) {
        case 0: return "Buy Life";
        case 1: return "Upgrade Damage";
        case 2: return "Exit";
        default: return "";
    }
}

// Handles user input for the shop
void ShopView::handleInput(sf::Event event, Shop& shop, bool& exitShop) {
    // Implementation for handling user input
}
