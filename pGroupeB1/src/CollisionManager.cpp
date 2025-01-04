#include "CollisionManager.h"
#include "PlayerController.h"
#include "Boss.h" // Inclure la classe Boss
#include "Zombie.h"
#include "Map.h"
#include <iostream> // Include for std::cout

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

bool CollisionManager::isColliding(const sf::Sprite& playerSprite, const sf::RectangleShape& tileShape) {
    return playerSprite.getGlobalBounds().intersects(tileShape.getGlobalBounds());
}

bool CollisionManager::isCollidingWithTile(const sf::FloatRect& hitbox, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& mapData = map.getData();
    for (size_t i = 0; i < mapData.size(); ++i) {
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            const auto& tile = mapData[i][j];
            if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                sf::RectangleShape tileShape(sf::Vector2f(32, 32));
                tileShape.setPosition(tile.getX() * 32, tile.getY() * 32);
                if (hitbox.intersects(tileShape.getGlobalBounds())) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CollisionManager::isCollidingProjectileWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes) {
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

bool CollisionManager::checkPlayerCollisions(PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& playerShape = playerController.getPlayer().getHitbox();
    return isCollidingWithTile(playerShape, map, collisionTypes);
}

bool CollisionManager::checkProjectileCollisions(const Projectile& projectile, const Map& map, const std::unordered_set<int>& collisionTypes) {
    return isCollidingProjectileWithTile(projectile.getShape(), map, collisionTypes);
}

void CollisionManager::checkProjectileEnemyCollisions(std::vector<Projectile>& projectiles, EnemyController& enemyController) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        bool hit = false;
        for (auto enemy : enemyController.getEnemies()) {
            sf::FloatRect enemyBounds;
            if (dynamic_cast<Boss*>(enemy)) {
                enemyBounds = dynamic_cast<Boss*>(enemy)->getSprite().getGlobalBounds();
            } else if (dynamic_cast<Zombie*>(enemy)) {
                enemyBounds = dynamic_cast<Zombie*>(enemy)->getSprite().getGlobalBounds();
            }
            if (it->getShape().getGlobalBounds().intersects(enemyBounds)) {
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

void CollisionManager::checkEnemyProjectileCollisions(std::vector<Projectile>& projectiles, PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes, const sf::View& cameraView) {
    const auto& playerShape = playerController.getPlayerSprite();
    sf::FloatRect cameraBounds(cameraView.getCenter() - cameraView.getSize() / 2.0f, cameraView.getSize());

    for (auto it = projectiles.begin(); it != projectiles.end();) {
        if (it->getShape().getGlobalBounds().intersects(playerShape.getGlobalBounds())) {
            std::cout << "Player hit by enemy projectile!" << std::endl;
            it = projectiles.erase(it);
        } else if (checkProjectileCollisions(*it, map, collisionTypes) || !cameraBounds.intersects(it->getShape().getGlobalBounds())) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}
