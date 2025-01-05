#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "PlayerController.h"
#include "Map.h"
#include "EnemyController.h"
#include <unordered_set>
#include <vector>

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

    bool isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape);
    bool isColliding(const sf::CircleShape& shape1, const sf::CircleShape& shape2); // Add this function
    void checkPlayerCollisions(PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes);
    bool checkProjectileCollisions(const Projectile& projectile, const Map& map, const std::unordered_set<int>& collisionTypes);
    void checkProjectileEnemyCollisions(std::vector<Projectile>& projectiles, EnemyController& enemyController);
    void checkEnemyProjectileCollisions(std::vector<Projectile>& projectiles, PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes);

private:
    bool isCollidingProjectileWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes);
    bool isCollidingWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes);
    std::vector<sf::Vector2i> getCollisionCells(const sf::FloatRect& bounds, int cellSize);
};

#endif // COLLISIONMANAGER_H