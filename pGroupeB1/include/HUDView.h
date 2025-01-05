#ifndef HUDVIEW_H
#define HUDVIEW_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Boss.h"

class HUDView {
public:
    HUDView();
    void update(const Player& player, const Boss* boss);
    void draw(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text playerHealthText;
    sf::Text playerDamageText;
    sf::Text playerLivesText;
    sf::Text bossHealthText;
};

#endif // HUDVIEW_H