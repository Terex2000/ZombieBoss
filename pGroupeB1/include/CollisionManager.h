#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "PlayerController.h"
#include "Map.h"
#include <unordered_set>

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();
    bool isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape);
    bool checkPlayerCollisions(const PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes);
    bool checkProjectileCollisions(const Projectile& projectile, const Map& map, const std::unordered_set<int>& collisionTypes);

private:
    bool isCollidingWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes);
};

#endif // COLLISIONMANAGER_H