#include "Projectile.h"

Projectile::Projectile(const sf::Vector2f& position, float direction, const sf::Texture& texture) 
    : speed(300.0f) {
    shape.setRadius(5.0f);
    shape.setTexture(&texture);
    shape.setPosition(position);
    velocity = sf::Vector2f(speed * direction, 0.0f);
}

Projectile::Projectile(const Projectile& other) 
    : shape(other.shape), velocity(other.velocity), speed(other.speed) {}

Projectile& Projectile::operator=(const Projectile& other) {
    if (this != &other) {
        shape = other.shape;
        velocity = other.velocity;
        // speed is const, no need to assign
    }
    return *this;
}

Projectile::Projectile(Projectile&& other) noexcept 
    : shape(std::move(other.shape)), velocity(std::move(other.velocity)), speed(other.speed) {}

Projectile& Projectile::operator=(Projectile&& other) noexcept {
    if (this != &other) {
        shape = std::move(other.shape);
        velocity = std::move(other.velocity);
        // speed is const, no need to assign
    }
    return *this;
}

void Projectile::update(float deltaTime) {
    shape.move(velocity * deltaTime);
}

void Projectile::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

const sf::CircleShape& Projectile::getShape() const {
    return shape;
}

bool Projectile::isOutOfBounds(const sf::RenderWindow& window) const {
    sf::Vector2f position = shape.getPosition();
    return position.x < 0 || position.x > window.getSize().x || position.y < 0 || position.y > window.getSize().y;
}

void Projectile::setScale(float scaleX, float scaleY) {
    shape.setScale(scaleX, scaleY);
}