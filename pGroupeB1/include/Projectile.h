#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

// The Projectile class represents a projectile fired by the player.
class Projectile {
public:
    // Constructor that initializes the projectile with a position, direction, and texture.
    Projectile(const sf::Vector2f& position, float direction, const sf::Texture& texture);

    // Copy constructor for Projectile.
    Projectile(const Projectile& other);

    // Copy assignment operator for Projectile.
    Projectile& operator=(const Projectile& other);

    // Move constructor for Projectile.
    Projectile(Projectile&& other) noexcept;

    // Move assignment operator for Projectile.
    Projectile& operator=(Projectile&& other) noexcept;

    // Updates the projectile's position based on the elapsed time.
    void update(float deltaTime);

    // Draws the projectile to the window.
    void draw(sf::RenderWindow& window) const;

    // Returns the shape of the projectile.
    const sf::CircleShape& getShape() const;

    // Checks if the projectile is out of the bounds of the window.
    bool isOutOfBounds(const sf::RenderWindow& window) const;

    // Sets the scale of the projectile's shape.
    void setScale(float scaleX, float scaleY);

private:
    sf::CircleShape shape; // Shape of the projectile
    sf::Vector2f velocity; // Velocity of the projectile
    const float speed; // Speed of the projectile
};

#endif // PROJECTILE_H