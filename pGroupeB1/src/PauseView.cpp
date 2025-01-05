#include "PauseView.h"
#include <iostream>

// Constructor for PauseView
PauseView::PauseView(sf::RenderWindow& window) : window(window) {
    // Load the font for the pause text
    if (!font.loadFromFile("assets/fonts/ZOMBIE.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    // Set up the pause text properties
    pauseText.setFont(font);
    pauseText.setString("Game Paused");
    pauseText.setCharacterSize(50);
    pauseText.setFillColor(sf::Color::White);
    pauseText.setPosition(window.getSize().x / 2 - pauseText.getLocalBounds().width / 2,
                          window.getSize().y / 2 - pauseText.getLocalBounds().height / 2);
}

// Default destructor for PauseView
PauseView::~PauseView() = default;

// Render the pause menu with the selected option highlighted
void PauseView::render(int selectedOption) {
    window.clear();

    // Load the font for the menu options
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/menu.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    // Set up and draw the title text
    sf::Text title("Pause", font, 50);
    title.setPosition(200, 100);
    title.setFillColor(sf::Color::White);
    window.draw(title);

    // Set up and draw the "Continue" option
    sf::Text continueOption("Continue", font, 30);
    continueOption.setPosition(200, 200);
    continueOption.setFillColor(selectedOption == 0 ? sf::Color::Red : sf::Color::White);
    window.draw(continueOption);

    // Set up and draw the "Main Menu" option
    sf::Text mainMenuOption("Main Menu", font, 30);
    mainMenuOption.setPosition(200, 300);
    mainMenuOption.setFillColor(selectedOption == 1 ? sf::Color::Red : sf::Color::White);
    window.draw(mainMenuOption);

    // Display the rendered frame
    window.display();
}
