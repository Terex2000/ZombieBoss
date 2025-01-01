#ifndef BOSSVIEW_H
#define BOSSVIEW_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>

class BossView {
public:
    BossView();
    virtual ~BossView();

    void draw(sf::RenderWindow& window, const Enemy& enemy);

private:
    sf::CircleShape shape;
};

#endif // BOSSVIEW_H