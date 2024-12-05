// CollisionManager.cpp
#include "CollisionManager.h"
#include <iostream>

CollisionManager::CollisionManager() {}

CollisionManager::~CollisionManager() {}

bool CollisionManager::isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape) {
    return playerShape.getGlobalBounds().intersects(tileShape.getGlobalBounds());
}

void CollisionManager::checkCollisions(PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes) {
    const auto& playerShape = playerController.getPlayerShape();
    const auto& mapData = map.getData();
    bool onGround = false;

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

                    float playerRadius = playerShape.getRadius();
                    float tileSize = tileShape.getSize().x;

                    float overlapLeft = (playerX + playerRadius * 2) - tileX;
                    float overlapRight = (tileX + tileSize) - playerX;
                    float overlapTop = (playerY + playerRadius * 2) - tileY;
                    float overlapBottom = (tileY + tileSize) - playerY;

                    bool fromLeft = overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom;
                    bool fromRight = overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom;
                    bool fromTop = overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight;
                    bool fromBottom = overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight;

                    if (fromLeft) {
                        playerController.setPosition(tileX - playerRadius * 2, playerY);
                    } else if (fromRight) {
                        playerController.setPosition(tileX + tileSize, playerY);
                    } else if (fromTop) {
                        playerController.setPosition(playerX, tileY - playerRadius * 2);
                        playerController.resetVerticalSpeed();
                        playerController.setJumping(false);
                        onGround = true;
                    } else if (fromBottom) {
                        playerController.setPosition(playerX, tileY + tileSize);
                        playerController.resetVerticalSpeed();
                    }
                }
            }
        }
    }

    playerController.setJumping(!onGround);
    playerController.setOnGround(onGround);
}