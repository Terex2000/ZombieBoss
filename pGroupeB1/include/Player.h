// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    ~Player();
    void move(float dx, float dy);
    const sf::CircleShape& getShape() const;
    void setPosition(float x, float y); // Ajout de la méthode setPosition

private:
    sf::CircleShape shape;
};

#endif // PLAYER_H