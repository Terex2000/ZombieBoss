#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class PlayerView {
public:
    PlayerView(Player& player);
    PlayerView(const PlayerView& other); // Constructeur de copie
    PlayerView& operator=(const PlayerView& other); // Opérateur d'affectation
    ~PlayerView();
    void draw(sf::RenderWindow& window);
    const sf::CircleShape& getShape() const;

private:
    Player& player;
    sf::CircleShape shape;
    void updateShape();
};

#endif // PLAYERVIEW_H