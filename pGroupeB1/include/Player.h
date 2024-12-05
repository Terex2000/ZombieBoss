// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    Player(const Player& other); // Constructeur de copie
    Player& operator=(const Player& other); // Opérateur d'affectation
    ~Player();
    void move(float dx, float dy);
    const sf::CircleShape& getShape() const;
    void setPosition(float x, float y);
    void setColor(const sf::Color& color);

private:
    sf::CircleShape shape;
};

#endif // PLAYER_H