#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Player.h"
#include "PlayerView.h"
#include "ProjectileController.h"
#include "Map.h"
#include <unordered_set>

class PlayerController {
public:
    PlayerController(float startX, float startY);
    PlayerController(const PlayerController& other); // Constructeur de copie
    PlayerController& operator=(const PlayerController& other); // Opérateur d'affectation
    ~PlayerController();
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);
    void update(float deltaTime, const sf::View& cameraView);
    void setPosition(float x, float y);
    void jump();
    void shoot();
    void resetVerticalSpeed();
    void setJumping(bool jumping);
    void setOnGround(bool onGround);
    bool isOnGround() const;
    const sf::CircleShape& getPlayerShape() const;
    float getDirection() const;
    Player& getPlayer();
    std::vector<Projectile>& getProjectiles();
    void handleCollision(const sf::RectangleShape& tileShape);

private:
    Player player;
    PlayerView playerView;
    ProjectileController projectileController;
    float verticalSpeed;
    bool isJumping;
    bool onGround;
    const float gravity = 980.0f; // pixels per second squared
    const float jumpSpeed = -350.0f; // increased initial jump speed
};

#endif // PLAYERCONTROLLER_H