#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "TextureManager.h"

class MainMenuView {
public:
    MainMenuView(sf::RenderWindow& window, TextureManager& textureManager);
    void render(const MainMenu& menu);

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Sprite backgroundSprite;
    TextureManager& textureManager;
};

#endif // MAINMENUVIEW_H
