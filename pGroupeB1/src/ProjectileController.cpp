#include "ProjectileController.h"

// Constructor for ProjectileController
ProjectileController::ProjectileController() {}

// Shoots a projectile from the specified position in the specified direction with the specified texture.
void ProjectileController::shoot(const sf::Vector2f& position, float direction, const sf::Texture& texture) {
    if (projectiles.empty()) {
        projectiles.emplace_back(position, direction, texture);
    }
}

// Updates the state of the projectiles based on the elapsed time and camera view.
void ProjectileController::update(float deltaTime, const sf::View& cameraView) {
    sf::FloatRect cameraBounds(cameraView.getCenter() - cameraView.getSize() / 2.0f, cameraView.getSize());

    for (auto it = projectiles.begin(); it != projectiles.end();) {
        it->update(deltaTime);
        if (!cameraBounds.intersects(it->getShape().getGlobalBounds())) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}

// Draws the projectiles to the window.
void ProjectileController::draw(sf::RenderWindow& window) const {
    for (const auto& projectile : projectiles) {
        projectile.draw(window);
    }
}

// Returns a reference to the projectiles.
std::vector<Projectile>& ProjectileController::getProjectiles() {
    return projectiles;
}

// Handles collisions between projectiles and other objects.
std::vector<Projectile>::iterator ProjectileController::handleCollision(std::vector<Projectile>::iterator it) {
    return projectiles.erase(it);
}