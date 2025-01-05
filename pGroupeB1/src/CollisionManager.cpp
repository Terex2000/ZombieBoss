#include "CollisionManager.h"
#include "PlayerController.h"
#include "Boss.h" // Include the Boss class
#include "Zombie.h"
#include "Map.h"
#include <iostream> // Include for std::cout

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

bool CollisionManager::isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape) {
    sf::FloatRect playerBounds = playerShape.getGlobalBounds();
    sf::FloatRect tileBounds = tileShape.getGlobalBounds();
    return playerBounds.intersects(tileBounds);
}

bool CollisionManager::isColliding(const sf::CircleShape& shape1, const sf::CircleShape& shape2) {
    sf::Vector2f pos1 = shape1.getPosition();
    sf::Vector2f pos2 = shape2.getPosition();
    float radius1 = shape1.getRadius();
    float radius2 = shape2.getRadius();
    float distance = std::sqrt((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));
    return distance < (radius1 + radius2);
}

std::vector<sf::Vector2i> CollisionManager::getCollisionCells(const sf::FloatRect& bounds, int cellSize) {
    std::vector<sf::Vector2i> cells;
    int startX = static_cast<int>(bounds.left) / cellSize;
    int startY = static_cast<int>(bounds.top) / cellSize;
    int endX = static_cast<int>(bounds.left + bounds.width) / cellSize;
    int endY = static_cast<int>(bounds.top + bounds.height) / cellSize;

    for (int x = startX; x <= endX; ++x) {
        for (int y = startY; y <= endY; ++y) {
            cells.emplace_back(x, y);
        }
    }

    return cells;
}

bool CollisionManager::isCollidingWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& mapData = map.getData();
    int cellSize = 32; // Assuming each tile is 32x32 pixels
    auto cells = getCollisionCells(shape.getGlobalBounds(), cellSize);

    for (const auto& cell : cells) {
        int x = cell.x;
        int y = cell.y;
        if (x >= 0 && x < mapData[0].size() && y >= 0 && y < mapData.size()) {
            const auto& tile = mapData[y][x];
            if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                sf::RectangleShape tileShape(sf::Vector2f(cellSize, cellSize));
                tileShape.setPosition(tile.getX() * cellSize, tile.getY() * cellSize);
                if (isColliding(shape, tileShape)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool CollisionManager::isCollidingProjectileWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& mapData = map.getData();
    int cellSize = 32; // Assuming each tile is 32x32 pixels
    auto cells = getCollisionCells(shape.getGlobalBounds(), cellSize);

    for (const auto& cell : cells) {
        int x = cell.x;
        int y = cell.y;
        if (x >= 0 && x < mapData[0].size() && y >= 0 && y < mapData.size()) {
            const auto& tile = mapData[y][x];
            if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                sf::RectangleShape tileShape(sf::Vector2f(cellSize, cellSize));
                tileShape.setPosition(tile.getX() * cellSize, tile.getY() * cellSize);
                if (isColliding(shape, tileShape)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void CollisionManager::checkPlayerCollisions(PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& playerShape = playerController.getPlayerShape();
    auto cells = getCollisionCells(playerShape.getGlobalBounds(), 32); // Assuming each tile is 32x32 pixels
     bool onGround = false;

    for (const auto& cell : cells) {
        int x = cell.x;
        int y = cell.y;
        if (x >= 0 && x < map.getData()[0].size() && y >= 0 && y < map.getData().size()) {
            const auto& tile = map.getData()[y][x];
            if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                sf::RectangleShape tileShape(sf::Vector2f(32, 32)); // Assuming each tile is 32x32 pixels
                tileShape.setPosition(tile.getX() * 32, tile.getY() * 32);
                if (isColliding(playerShape, tileShape)) {
                    playerController.handleCollision(tileShape);
                     if (playerController.isOnGround()) {
                        onGround = true;
                    }
                }
            }
        }
    }
        playerController.setOnGround(onGround);

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

void CollisionManager::checkEnemyProjectileCollisions(std::vector<Projectile>& projectiles, PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& playerShape = playerController.getPlayerShape();

    for (auto it = projectiles.begin(); it != projectiles.end();) {
        if (isColliding(it->getShape(), playerShape)) {
            std::cout << "Player hit by enemy projectile!" << std::endl;
            playerController.getPlayer().takeDamage(it->getDamage()); // Inflict damage to the player
            it = projectiles.erase(it);
        } else if (checkProjectileCollisions(*it, map, collisionTypes)) {
            it = projectiles.erase(it);
        } else {
            ++it;
        }
    }
}