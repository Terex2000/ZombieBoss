#ifndef PROJECTILECONTROLLER_H
#define PROJECTILECONTROLLER_H

#include "Projectile.h"
#include <vector>

class ProjectileController {
public:
    ProjectileController();
    void shoot(const sf::Vector2f& position, float direction, const sf::Texture& texture); // Modifiez cette ligne
    void update(float deltaTime, const sf::View& cameraView);
    void draw(sf::RenderWindow& window) const;
    std::vector<Projectile>& getProjectiles();
    std::vector<Projectile>::iterator handleCollision(std::vector<Projectile>::iterator it); // Modifiez cette ligne

private:
    std::vector<Projectile> projectiles;
};

#endif // PROJECTILECONTROLLER_H