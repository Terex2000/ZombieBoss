#include "PauseView.h"
#include <iostream>

PauseView::PauseView(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromFile("assets/fonts/ZOMBIE.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    pauseText.setFont(font);
    pauseText.setString("Game Paused");
    pauseText.setCharacterSize(50);
    pauseText.setFillColor(sf::Color::White);
    pauseText.setPosition(window.getSize().x / 2 - pauseText.getLocalBounds().width / 2,
                          window.getSize().y / 2 - pauseText.getLocalBounds().height / 2);
}

PauseView::~PauseView() = default;

void PauseView::render(int selectedOption) {
    window.clear();
    // Afficher un menu semblable au menu principal
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/menu.ttf")) {
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
    }
    sf::Text title("Pause", font, 50);
    title.setPosition(200, 100);
    title.setFillColor(sf::Color::White);
    window.draw(title);

    // Options : Continuer, Menu principal
    sf::Text continueOption("Continue", font, 30);
    continueOption.setPosition(200, 200);
    continueOption.setFillColor(selectedOption == 0 ? sf::Color::Red : sf::Color::White);
    window.draw(continueOption);

    sf::Text mainMenuOption("Main Menu", font, 30);
    mainMenuOption.setPosition(200, 300);
    mainMenuOption.setFillColor(selectedOption == 1 ? sf::Color::Red : sf::Color::White);
    window.draw(mainMenuOption);

    window.display();
}

