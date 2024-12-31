#include "ProjectileController.h"

// Constructor for ProjectileController
ProjectileController::ProjectileController() {}

// Shoots a projectile from the given position in the given direction with the given texture and damage.
void ProjectileController::shoot(const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Texture& texture, float damage) {
   if(projectiles.empty()) {
       projectiles.emplace_back(position, direction, texture, damage);
   }
}

// Updates the projectiles' positions based on the elapsed time.
void ProjectileController::update(float deltaTime, const sf::View& cameraView) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->update(deltaTime);
        if (it->isOutOfBounds(cameraView)) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

// Draws the projectiles to the window.
void ProjectileController::draw(sf::RenderWindow& window) {
    for (const auto& projectile : projectiles) {
        projectile.draw(window);
    }
}

// Returns the list of projectiles.
std::vector<Projectile>& ProjectileController::getProjectiles() {
    return projectiles;
}
// Handles collisions between projectiles and other objects.
std::vector<Projectile>::iterator ProjectileController::handleCollision(std::vector<Projectile>::iterator it) {
    return projectiles.erase(it);
}