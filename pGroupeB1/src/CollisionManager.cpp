// CollisionManager.cpp
#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

void CollisionManager::checkCollisions(PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& playerShape = playerController.getPlayerShape();
    const auto& mapData = map.getData();

    for (size_t i = 0; i < mapData.size(); ++i) {
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            const auto& tile = mapData[i][j];
            if (collisionTypes.find(tile.getType()) != collisionTypes.end()) {
                sf::RectangleShape tileShape(sf::Vector2f(32, 32));
                tileShape.setPosition(tile.getX() * 32, tile.getY() * 32);
                if (isColliding(playerShape, tileShape)) {
                    std::cout << "Collision with tile at: " << tile.getX() << ", " << tile.getY() << std::endl; // Debug message
                    // Adjust player position to prevent passing through the tile
                    float playerX = playerShape.getPosition().x;
                    float playerY = playerShape.getPosition().y;
                    float tileX = tileShape.getPosition().x;
                    float tileY = tileShape.getPosition().y;

                    if (playerX < tileX) {
                        playerController.setPosition(tileX - playerShape.getRadius() * 2, playerY);
                    } else if (playerX > tileX) {
                        playerController.setPosition(tileX + tileShape.getSize().x, playerY);
                    } else if (playerY < tileY) {
                        playerController.setPosition(playerX, tileY - playerShape.getRadius() * 2);
                    } else if (playerY > tileY) {
                        playerController.setPosition(playerX, tileY + tileShape.getSize().y);
                    }
                }
            }
        }
    }
}

bool CollisionManager::isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape) {
    return playerShape.getGlobalBounds().intersects(tileShape.getGlobalBounds());
}