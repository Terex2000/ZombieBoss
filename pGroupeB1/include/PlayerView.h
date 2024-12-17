#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include "Player.h"

// The PlayerView class is responsible for rendering the player.
class PlayerView {
public:
    // Constructor that initializes the player view with a reference to the player.
    PlayerView(Player& player);
    PlayerView(const PlayerView& other); // Copy constructor
    PlayerView& operator=(const PlayerView& other); // Copy assignment operator
    ~PlayerView();

    // Draws the player to the window.
    void draw(sf::RenderWindow& window);

    // Returns the shape of the player.
    const sf::CircleShape& getShape() const;

private:
    Player& player; // Reference to the player object
    sf::CircleShape shape; // Shape for rendering the player

    // Updates the shape's position and color based on the player's state.
    void updateShape();
};

#endif // PLAYERVIEW_H