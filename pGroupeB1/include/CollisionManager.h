#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "PlayerController.h"
#include "Map.h"
#include "EnemyController.h"
#include <unordered_set>

class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

    bool isColliding(const sf::Sprite& playerSprite, const sf::RectangleShape& tileShape);
    bool checkPlayerCollisions(PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes);
    bool checkProjectileCollisions(const Projectile& projectile, const Map& map, const std::unordered_set<int>& collisionTypes);
    void checkProjectileEnemyCollisions(std::vector<Projectile>& projectiles, EnemyController& enemyController);
    void checkEnemyProjectileCollisions(std::vector<Projectile>& projectiles, PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes);

private:
    bool isCollidingProjectileWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes);
    bool isCollidingWithTile(const sf::FloatRect& hitbox, const Map& map, const std::unordered_set<int>& collisionTypes);
};

#endif // COLLISIONMANAGER_H
