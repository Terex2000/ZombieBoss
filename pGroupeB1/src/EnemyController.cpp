#include "EnemyController.h"
#include "Zombie.h"
#include <cmath> // Include for sqrt and pow

EnemyController::EnemyController(EnemyFactory& factory, TextureManager& textureManager)
    : factory(factory), textureManager(textureManager) {}

EnemyController::~EnemyController() {
    for (auto enemy : enemies) {
        delete enemy;
    }
}

void EnemyController::createEnemy(float x, float y, float health, float attack, float speed, float maxDistance) {
    enemies.push_back(factory.createEnemy(x, y, health, attack, speed, maxDistance, textureManager.getTexture("zombie")));
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
            // Update enemy position
            dynamic_cast<Zombie*>(*it)->update(deltaTime);

            // Check if the enemy should shoot
            sf::Vector2f enemyPosition = (*it)->getPosition();
            float distance = std::sqrt(std::pow(playerPosition.x - enemyPosition.x, 2) + std::pow(playerPosition.y - enemyPosition.y, 2));
            if (distance < 350.0f && projectileController.getProjectiles().size() < 3) { // Example distance
                sf::Vector2f direction = playerPosition - enemyPosition;
                float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                direction /= length; // Normalize the direction vector
                projectileController.shoot(enemyPosition, direction, textureManager.getTexture("bullet"), 20.0f); // Example damage
                projectileController.getProjectiles().back().setScale(4.0f, 3.0f);
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