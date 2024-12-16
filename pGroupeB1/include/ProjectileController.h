#ifndef PROJECTILECONTROLLER_H
#define PROJECTILECONTROLLER_H

#include "Projectile.h"
#include <vector>

// The ProjectileController class is responsible for managing projectiles fired by the player.
class ProjectileController {
public:
    ProjectileController();

    // Shoots a projectile from the specified position in the specified direction with the specified texture.
    void shoot(const sf::Vector2f& position, float direction, const sf::Texture& texture);

    // Updates the state of the projectiles based on the elapsed time and camera view.
    void update(float deltaTime, const sf::View& cameraView);

    // Draws the projectiles to the window.
    void draw(sf::RenderWindow& window) const;

    // Returns a reference to the projectiles.
    std::vector<Projectile>& getProjectiles();

    // Handles collision for a projectile and returns an iterator to the next projectile.
    std::vector<Projectile>::iterator handleCollision(std::vector<Projectile>::iterator it);

private:
    std::vector<Projectile> projectiles; // Vector of projectiles
};

#endif // PROJECTILECONTROLLER_H