#include "Projectile.h"

// Constructor for Projectile
// Initializes the projectile with a position, direction, and texture.
Projectile::Projectile(const sf::Vector2f& position, float direction, const sf::Texture& texture) 
    : speed(300.0f) {
    shape.setRadius(5.0f);
    shape.setTexture(&texture);
    shape.setPosition(position);
    velocity = sf::Vector2f(speed * direction, 0.0f);
}

// Copy constructor for Projectile
Projectile::Projectile(const Projectile& other) 
    : shape(other.shape), velocity(other.velocity), speed(other.speed) {}

// Copy assignment operator for Projectile
Projectile& Projectile::operator=(const Projectile& other) {
    if (this != &other) {
        shape = other.shape;
        velocity = other.velocity;
        // speed is const, no need to assign
    }
    return *this;
}

// Move constructor for Projectile
Projectile::Projectile(Projectile&& other) noexcept 
    : shape(std::move(other.shape)), velocity(std::move(other.velocity)), speed(other.speed) {}

// Move assignment operator for Projectile
Projectile& Projectile::operator=(Projectile&& other) noexcept {
    if (this != &other) {
        shape = std::move(other.shape);
        velocity = std::move(other.velocity);
        // speed is const, no need to assign
    }
    return *this;
}

// Updates the projectile's position based on the elapsed time.
void Projectile::update(float deltaTime) {
    shape.move(velocity * deltaTime);
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
    sf::Vector2f position = shape.getPosition();
    return position.x < 0 || position.x > window.getSize().x || position.y < 0 || position.y > window.getSize().y;
}

// Sets the scale of the projectile's shape.
void Projectile::setScale(float scaleX, float scaleY) {
    shape.setScale(scaleX, scaleY);
}