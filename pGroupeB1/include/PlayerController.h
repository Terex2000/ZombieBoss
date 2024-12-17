#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Player.h"
#include "PlayerView.h"
#include "ProjectileController.h"
#include "Map.h"
#include "TextureManager.h"
#include <unordered_set>

// The PlayerController class is responsible for managing the player's state and behavior.
class PlayerController {
public:
    // Constructor that initializes the player controller with a starting position and texture manager.
    PlayerController(float startX, float startY, TextureManager& textureManager);
    PlayerController(const PlayerController& other); // Copy constructor
    PlayerController& operator=(const PlayerController& other); // Copy assignment operator
    ~PlayerController();

    // Draws the player and projectiles to the window.
    void draw(sf::RenderWindow& window);

    // Moves the player by the specified amounts.
    void move(float dx, float dy);

    // Updates the player's state based on the elapsed time and camera view.
    void update(float deltaTime, const sf::View& cameraView);

    // Sets the player's position.
    void setPosition(float x, float y);

    // Makes the player jump.
    void jump();

    // Makes the player shoot a projectile.
    void shoot();

    // Resets the player's vertical speed.
    void resetVerticalSpeed();

    // Sets whether the player is jumping.
    void setJumping(bool jumping);

    // Sets whether the player is on the ground.
    void setOnGround(bool onGround);

    // Returns whether the player is on the ground.
    bool isOnGround() const;

    // Returns the shape of the player.
    const sf::CircleShape& getPlayerShape() const;

    // Returns the direction the player is facing.
    float getDirection() const;

    // Returns a reference to the player object.
    Player& getPlayer();

    // Returns a reference to the player's projectiles.
    std::vector<Projectile>& getProjectiles();

    // Handles collisions between the player and a tile.
    void handleCollision(const sf::RectangleShape& tileShape);

private:
    Player player; // The player object
    PlayerView playerView; // The view for rendering the player
    ProjectileController projectileController; // The controller for managing projectiles
    TextureManager& textureManager; // Reference to the texture manager
    float verticalSpeed; // The player's vertical speed
    bool isJumping; // Whether the player is jumping
    bool onGround; // Whether the player is on the ground
    const float gravity = 980.0f; // Gravity constant (pixels per second squared)
    const float jumpSpeed = -350.0f; // Initial jump speed (pixels per second)
};

#endif // PLAYERCONTROLLER_H