#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile {
public:
    Projectile(const sf::Vector2f& position, float direction, const sf::Texture& texture);
    Projectile(const Projectile& other); // Constructeur de copie
    Projectile& operator=(const Projectile& other); // Opérateur d'affectation
    Projectile(Projectile&& other) noexcept; // Constructeur de déplacement
    Projectile& operator=(Projectile&& other) noexcept; // Opérateur d'affectation par déplacement
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    const sf::CircleShape& getShape() const;
    bool isOutOfBounds(const sf::RenderWindow& window) const;
    void setScale(float scaleX, float scaleY); // Ajoutez cette méthode

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    const float speed = 150.0f; // pixels per second
};

#endif // PROJECTILE_H