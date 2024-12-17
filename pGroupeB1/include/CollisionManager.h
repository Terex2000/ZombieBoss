#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "PlayerController.h"
#include "Map.h"
#include <unordered_set>//Offers amortized constant-time search, 
                        //Inserting elements into an unordered_set is also amortized constant-time, O(1) 
                        //and does not allow duplicates.

// The CollisionManager class is responsible for handling collision detection
// between the player, projectiles, and the map tiles.
class CollisionManager {
public:
    CollisionManager();
    ~CollisionManager();

    // Checks if the player shape is colliding with a tile shape.
    // This method is used to detect collisions between the player and individual tiles.
    bool isColliding(const sf::CircleShape& playerShape, const sf::RectangleShape& tileShape);

    // Checks if the player is colliding with any collision tiles in the map.
    // This method iterates through the map and checks for collisions with tiles
    // that are marked as collision types.
    bool checkPlayerCollisions(const PlayerController& playerController, const Map& map, const std::unordered_set<int>& collisionTypes);

    // Checks if a projectile is colliding with any collision tiles in the map.
    // This method iterates through the map and checks for collisions with tiles
    // that are marked as collision types.
    bool checkProjectileCollisions(const Projectile& projectile, const Map& map, const std::unordered_set<int>& collisionTypes);

private:
    // Helper function to check if a shape is colliding with any collision tiles in the map.
    // This method is used internally to avoid code duplication in the public methods.
    bool isCollidingWithTile(const sf::CircleShape& shape, const Map& map, const std::unordered_set<int>& collisionTypes);
};

#endif // COLLISIONMANAGER_H