#include "MainMenuView.h"
#include <iostream>

// Constructor for MainMenuView
MainMenuView::MainMenuView(sf::RenderWindow& window, TextureManager& textureManager) : window(window), textureManager(textureManager) {
    // Load the background texture
    if (!textureManager.loadTexture("background", "assets/img/mainMenuBackground.gif")) {
        std::cerr << "Error: Failed to load background texture!" << std::endl;
    }
    backgroundSprite.setTexture(textureManager.getTexture("background"));

    // Load the font
    if (!font.loadFromFile("assets/police/ZOMBIE.TTF")) {
        std::cerr << "Error loading font!" << std::endl;
    }
}

// Render the main menu
void MainMenuView::render(const MainMenu& menu) {
    window.clear();

    // Dynamically adjust the background to the window size
    textureManager.adjustSpriteToWindow(backgroundSprite, window);
    window.draw(backgroundSprite);

    // Get the menu options
    const auto& options = menu.getOptions();
    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(50);
        // Highlight the selected option in red, others in white
        text.setFillColor(i == menu.getSelectedOption() ? sf::Color::Red : sf::Color::White);
        text.setPosition(300.f, 100.f + i * 100.f);
        window.draw(text);
    }

    window.display();
}
