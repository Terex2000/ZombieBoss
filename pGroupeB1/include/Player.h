#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

// The Player class represents the player character.
class Player {
public:
    Player();
    Player(const Player& other); // Copy constructor
    Player& operator=(const Player& other); // Copy assignment operator
    ~Player();

    // Moves the player by the specified amounts.
    void move(float dx, float dy);

    // Returns the position of the player.
    const sf::Vector2f& getPosition() const;

    // Sets the position of the player.
    void setPosition(float x, float y);

    // Sets the color of the player.
    void setColor(const sf::Color& color);

    // Returns the color of the player.
    const sf::Color& getColor() const;

    // Returns the radius of the player.
    float getRadius() const;

    // Sets the direction the player is facing.
    void setDirection(float direction);

    // Returns the direction the player is facing.
    float getDirection() const;

private:
    sf::Vector2f position; // Position of the player
    sf::Color color; // Color of the player
    float radius; // Radius of the player
    float direction; // Direction the player is facing
};

#endif // PLAYER_H