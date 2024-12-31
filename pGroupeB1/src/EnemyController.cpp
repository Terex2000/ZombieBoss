#include "EnemyController.h"
#include <cmath> // Include for sqrt and pow

EnemyController::EnemyController(EnemyFactory& factory, TextureManager& textureManager)
    : factory(factory), textureManager(textureManager) {}

EnemyController::~EnemyController() {
    for (auto enemy : enemies) {
        delete enemy;
    }
}

void EnemyController::createEnemy(float x, float y, float health, float attack, float speed) {
    enemies.push_back(factory.createEnemy(x, y, health, attack, speed));
}

void EnemyController::draw(sf::RenderWindow& window) {
    for (auto enemy : enemies) {
        zombieView.draw(window, *enemy);
    }
    projectileController.draw(window);
}

void EnemyController::update(float deltaTime, const sf::Vector2f& playerPosition) {
    for (auto it = enemies.begin(); it != enemies.end();) {
        if ((*it)->getHealth() <= 0) {
            delete *it;
            it = enemies.erase(it);
        } else {
            // Check if the enemy should shoot
            sf::Vector2f enemyPosition = (*it)->getPosition();
            float distance = std::sqrt(std::pow(playerPosition.x - enemyPosition.x, 2) + std::pow(playerPosition.y - enemyPosition.y, 2));
            if (distance < 350.0f && projectileController.getProjectiles().size() < 3) { // Example distance
                float direction = (playerPosition.x - enemyPosition.x) / distance;
                projectileController.shoot(enemyPosition, direction, textureManager.getTexture("bullet"), 20.0f); // Example damage
                projectileController.getProjectiles().back().setScale(4.0f, 3.0f); // Adjust the scale here
            }
            ++it;
        }
    }
    projectileController.update(deltaTime, sf::View());
}

std::vector<Enemy*>& EnemyController::getEnemies() {
    return enemies;
}

ProjectileController& EnemyController::getProjectileController() {
    return projectileController;
}
