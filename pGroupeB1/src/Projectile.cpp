#include "Projectile.h"
#include <cmath> // Include for atan2 and M_PI

// Constructor for Projectile
// Initializes the projectile with a position, direction, texture, and damage.
Projectile::Projectile(const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Texture& texture, float damage)
    : velocity(direction), speed(300.0f), damage(damage) {
    shape.setTexture(&texture);
    shape.setRadius(5.0f);
    shape.setPosition(position);
}

// Copy constructor for Projectile.
Projectile::Projectile(const Projectile& other)
    : shape(other.shape), velocity(other.velocity), speed(other.speed), damage(other.damage) {}

// Copy assignment operator for Projectile.
Projectile& Projectile::operator=(const Projectile& other) {
    if (this != &other) {
        shape = other.shape;
        velocity = other.velocity;
        damage = other.damage;
    }
    return *this;
}

// Move constructor for Projectile.
Projectile::Projectile(Projectile&& other) noexcept
    : shape(std::move(other.shape)), velocity(std::move(other.velocity)), speed(other.speed), damage(other.damage) {}

// Move assignment operator for Projectile.
Projectile& Projectile::operator=(Projectile&& other) noexcept {
    if (this != &other) {
        shape = std::move(other.shape);
        velocity = std::move(other.velocity);
        damage = other.damage;
    }
    return *this;
}

// Updates the projectile's position based on the elapsed time.
void Projectile::update(float deltaTime) {
    shape.move(velocity * speed * deltaTime);
    float scaleX = (velocity.x < 0) ? -1.0f : 1.0f;
    shape.setScale(scaleX, 2.5f);
}

// Draws the projectile to the window.
void Projectile::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

// Returns the shape of the projectile.
const sf::CircleShape& Projectile::getShape() const {
    return shape;
}

// Checks if the projectile is out of the bounds of the window.
bool Projectile::isOutOfBounds(const sf::RenderWindow& window) const {
    sf::FloatRect bounds = shape.getGlobalBounds();
    return bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
           bounds.left > window.getSize().x || bounds.top > window.getSize().y;
}

// Checks if the projectile is out of the bounds of the view.
bool Projectile::isOutOfBounds(const sf::View& view) const {
    sf::FloatRect bounds = shape.getGlobalBounds();
    sf::FloatRect viewBounds(view.getCenter() - view.getSize() / 2.0f, view.getSize());
    return !viewBounds.intersects(bounds);
}

// Sets the scale of the projectile's shape.
void Projectile::setScale(float scaleX, float scaleY) {
    shape.setScale(scaleX, scaleY);
}

// Returns the damage of the projectile.
float Projectile::getDamage() const {
    return damage;
}
