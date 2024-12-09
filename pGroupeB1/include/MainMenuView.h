#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include "MainMenu.h"
#include <SFML/Graphics.hpp>

class MainMenuView {
public:
    MainMenuView(sf::RenderWindow& window);
    virtual ~MainMenuView();

    void render(const MainMenu& menu);

private:
    sf::RenderWindow& window;
    sf::Font font;
    std::vector<sf::Text> optionsText;
};

#endif // MAINMENUVIEW_H
