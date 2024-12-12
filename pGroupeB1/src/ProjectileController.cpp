#include "ProjectileController.h"

ProjectileController::ProjectileController() {}

void ProjectileController::shoot(const sf::Vector2f& position, float direction) {
    if (projectiles.empty()) {
        projectiles.emplace_back(position, direction);
    }
}

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

void ProjectileController::draw(sf::RenderWindow& window) const {
    for (const auto& projectile : projectiles) {
        projectile.draw(window);
    }
}

std::vector<Projectile>& ProjectileController::getProjectiles() {
    return projectiles;
}

std::vector<Projectile>::iterator ProjectileController::handleCollision(std::vector<Projectile>::iterator it) { // Modifiez cette méthode
    return projectiles.erase(it);
}