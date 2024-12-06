// PlayerController.h
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayerView.h"

class PlayerController {
public:
    PlayerController(float startX, float startY);
    PlayerController(const PlayerController& other); // Constructeur de copie
    PlayerController& operator=(const PlayerController& other); // Opérateur d'affectation
    ~PlayerController();
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);
    void update(float deltaTime);
    const sf::CircleShape& getPlayerShape() const;
    void setPosition(float x, float y);
    void jump();
    void resetVerticalSpeed();
    void setJumping(bool jumping);
    void setOnGround(bool onGround);
    bool isOnGround() const;

private:
    Player player;
    PlayerView playerView;
    float verticalSpeed;
    bool isJumping;
    bool onGround;
    const float gravity = 980.0f; // pixels per second squared
    const float jumpSpeed = -350.0f; // increased initial jump speed
};

#endif // PLAYERCONTROLLER_H