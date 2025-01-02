#ifndef ZOMBIEVIEW_H
#define ZOMBIEVIEW_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>

class ZombieView {
public:
    ZombieView();
    virtual ~ZombieView();

    void draw(sf::RenderWindow& window, const Enemy& enemy);

private:
    sf::CircleShape shape;
};

#endif // ZOMBIEVIEW_H