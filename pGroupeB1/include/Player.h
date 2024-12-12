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
    const sf::Vector2f& getPosition() const;
    void setPosition(float x, float y);
    void setColor(const sf::Color& color);
    const sf::Color& getColor() const;
    float getRadius() const;
    void setDirection(float direction);
    float getDirection() const;

private:
    sf::Vector2f position;
    sf::Color color;
    float radius;
    float direction;
};

#endif // PLAYER_H