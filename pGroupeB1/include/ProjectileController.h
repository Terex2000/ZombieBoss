#ifndef PROJECTILECONTROLLER_H
#define PROJECTILECONTROLLER_H

#include "Projectile.h"
#include <vector>
#include <SFML/Graphics.hpp>

class ProjectileController {
public:
    ProjectileController();
    void shoot(const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Texture& texture, float damage);
    void update(float deltaTime, const sf::View& cameraView);
    void draw(sf::RenderWindow& window);
    std::vector<Projectile>& getProjectiles();
    // Handles collision for a projectile and returns an iterator to the next projectile.
    std::vector<Projectile>::iterator handleCollision(std::vector<Projectile>::iterator it);

private:
    std::vector<Projectile> projectiles;
};

#endif // PROJECTILECONTROLLER_H