#include "MainMenuView.h"
#include <iostream>

MainMenuView::MainMenuView(sf::RenderWindow& window, TextureManager& textureManager) : window(window),textureManager(textureManager) {
    // Charger la texture globale pour le fond
    if (!textureManager.loadTexture("background", "assets/img/mainMenuBackground.gif")) {
        std::cerr << "Error: Failed to load background texture!" << std::endl;
    }
    backgroundSprite.setTexture(textureManager.getTexture("background"));

    // Charger la police
    if (!font.loadFromFile("assets/police/ZOMBIE.TTF")) {
        std::cerr << "Error loading police!" << std::endl;
    }
}

void MainMenuView::render(const MainMenu& menu) {
    window.clear();

     // Ajuster dynamiquement le fond à la taille de la fenêtre
    textureManager.adjustSpriteToWindow(backgroundSprite, window);
    window.draw(backgroundSprite);

    const auto& options = menu.getOptions();
    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(50);
        text.setFillColor(i == menu.getSelectedOption() ? sf::Color::Red : sf::Color::White);
        text.setPosition(300.f, 200.f + i * 100.f);
        window.draw(text);
    }

    window.display();
}
