// CollisionManager.h
#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "PlayerController.h"
#include "Map.h"
#include <vector>
#include <unordered_set>

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();
    void checkCollisions(PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes);

private:
    bool isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape);
};

#endif // COLLISIONMANAGER_H