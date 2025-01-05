#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "TextureManager.h"


// The PlayerView class is responsible for rendering the player.
class PlayerView {
public:
    // Constructor that initializes the player view with a reference to the player.
    PlayerView(Player& player, TextureManager& textureManager);
    PlayerView(const PlayerView& other); // Copy constructor
    PlayerView& operator=(const PlayerView& other); // Copy assignment operator
    ~PlayerView();

    // Draws the player to the window.
    void draw(sf::RenderWindow& window);

    // Returns the shape of the player.
    const sf::CircleShape& getShape() const;
    const sf::Sprite& getSprite() const;

private:
    Player& player; // Reference to the player object
    TextureManager& textureManager; // Shape for rendering the player
    sf::CircleShape shape;
    sf::Sprite sprite;

    // Updates the shape's position and color based on the player's state.
    void updateSprite();

    void updateShape();
};

#endif // PLAYERVIEW_H