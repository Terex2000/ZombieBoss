#include "CollisionManager.h"
#include "PlayerController.h"
#include "Map.h"

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

bool CollisionManager::isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape) {
    return playerShape.getGlobalBounds().intersects(tileShape.getGlobalBounds());
}

bool CollisionManager::isCollidingWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& mapData = map.getData();
    for (size_t i = 0; i < mapData.size(); ++i) {
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            const auto& tile = mapData[i][j];
            if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                sf::RectangleShape tileShape(sf::Vector2f(32, 32));
                tileShape.setPosition(tile.getX() * 32, tile.getY() * 32);
                if (shape.getGlobalBounds().intersects(tileShape.getGlobalBounds())) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CollisionManager::checkPlayerCollisions(const PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& playerShape = playerController.getPlayerShape();
    return isCollidingWithTile(playerShape, map, collisionTypes);
}

bool CollisionManager::checkProjectileCollisions(const Projectile& projectile, const Map& map, const std::unordered_set<int>& collisionTypes) {
    return isCollidingWithTile(projectile.getShape(), map, collisionTypes);
}

bool CollisionManager::checkEnemyCollisions(EnemyController& enemyController, const Map& map, const std::unordered_set<int>& collisionTypes) {
    for (auto enemy : enemyController.getEnemies()) {
        sf::CircleShape enemyShape(15.0f); // Assuming enemy radius is 15.0f
        enemyShape.setPosition(enemy->getPosition());
        if (isCollidingWithTile(enemyShape, map, collisionTypes)) {
            // Handle enemy collision logic here
            enemy->takeDamage(10.0f); // Example damage value
        }
    }
    return false;
}

void CollisionManager::checkProjectileEnemyCollisions(std::vector<Projectile>& projectiles, EnemyController& enemyController) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        bool hit = false;
        for (auto enemy : enemyController.getEnemies()) {
            sf::CircleShape enemyShape(15.0f); // Assuming enemy radius is 15.0f
            enemyShape.setPosition(enemy->getPosition());
            if (it->getShape().getGlobalBounds().intersects(enemyShape.getGlobalBounds())) {
                enemy->takeDamage(it->getDamage()); // Use the damage value from the projectile
                hit = true;
                break;
            }
        }
        if (hit) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}