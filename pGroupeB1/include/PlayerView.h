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
    const sf::Sprite& getSprite() const;

    void updateHitboxVisual();
    void updateSpriteBounds();

private:
    Player& player; // Reference to the player object
    TextureManager& textureManager; // Shape for rendering the player
    sf::Sprite sprite;

    std::vector<sf::IntRect> frames;  // Frames for the current animation
    std::size_t currentFrame;         // Current frame index
    sf::Clock clock;                  // Clock to control animation timing
    float animationTime;              // Time accumulator for animation
    sf::RectangleShape hitboxShape;
    sf::RectangleShape spriteRectangle;

    // Updates the shape's position and color based on the player's state.
    void updateSprite();

    // Sets up the animation frames for a specific state
    void setAnimation(const std::string& state, int frameCount);


};

#endif // PLAYERVIEW_H
