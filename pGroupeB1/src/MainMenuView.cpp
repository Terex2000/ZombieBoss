#include "MainMenuView.h"
#include <iostream>

MainMenuView::MainMenuView(sf::RenderWindow& window) : window(window) {
    if (!font.loadFromFile("res/ZOMBIE.TTF")) {
        std::cerr << "Error loading font" << std::endl;
    }
}

MainMenuView::~MainMenuView() {}

void MainMenuView::render(const MainMenu& menu) {
    window.clear();

    const auto& options = menu.getOptions();
    float y = 200.f;

    for (size_t i = 0; i < options.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(options[i]);
        text.setCharacterSize(50);
        text.setFillColor(i == static_cast<size_t>(menu.getSelectedOption()) ? sf::Color::Red : sf::Color::White);
        text.setPosition(300.f, y);
        y += 100.f;

        window.draw(text);
    }

    window.display();
}
