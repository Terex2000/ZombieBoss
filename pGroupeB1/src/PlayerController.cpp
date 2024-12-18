#include "PlayerController.h"

// Constructor for PlayerController
// Initializes the player controller with a starting position and texture manager.
PlayerController::PlayerController(float startX, float startY, TextureManager& textureManager)
    : player(), playerView(player), projectileController(), textureManager(textureManager), verticalSpeed(0.0f), isJumping(false), onGround(false) {
    player.setPosition(startX, startY);
    player.setColor(sf::Color::Red);
}

// Copy constructor for PlayerController
PlayerController::PlayerController(const PlayerController& other)
    : player(other.player), playerView(player), projectileController(), textureManager(other.textureManager), verticalSpeed(other.verticalSpeed), isJumping(other.isJumping), onGround(other.onGround) {}

// Copy assignment operator for PlayerController
PlayerController& PlayerController::operator=(const PlayerController& other) {
    if (this != &other) {
        player = other.player;
        playerView = PlayerView(player);
        projectileController = other.projectileController;
        textureManager = other.textureManager;
        verticalSpeed = other.verticalSpeed;
        isJumping = other.isJumping;
        onGround = other.onGround;
    }
    return *this;
}

// Destructor for PlayerController
PlayerController::~PlayerController() {}

// Draws the player and projectiles to the window.
void PlayerController::draw(sf::RenderWindow& window) {
    playerView.draw(window);
    projectileController.draw(window);
}

// Moves the player by the specified amounts.
void PlayerController::move(float dx, float dy) {
    player.move(dx, dy);
}

// Updates the player's state based on the elapsed time and camera view.
void PlayerController::update(float deltaTime, const sf::View& cameraView) {
    if (!onGround) {
        verticalSpeed += gravity * deltaTime;
        move(0, verticalSpeed * deltaTime);
    }
    projectileController.update(deltaTime, cameraView);
}

// Sets the player's position.
void PlayerController::setPosition(float x, float y) {
    player.setPosition(x, y);
}

// Makes the player jump.
void PlayerController::jump() {
    if (onGround) {
        isJumping = true;
        onGround = false;
        verticalSpeed = jumpSpeed;
    }
}

// Makes the player shoot a projectile.
void PlayerController::shoot() {
    sf::Vector2f position = player.getPosition();
    float direction = player.getDirection();
    const sf::Texture& texture = textureManager.getTexture("bullet");
    projectileController.shoot(position, direction, texture);
    projectileController.getProjectiles().back().setScale(4.0f, 3.0f); // Adjust the scale here
}

// Resets the player's vertical speed.
void PlayerController::resetVerticalSpeed() {
    verticalSpeed = 0.0f;
}

// Sets whether the player is jumping.
void PlayerController::setJumping(bool jumping) {
    isJumping = jumping;
}

// Sets whether the player is on the ground.
void PlayerController::setOnGround(bool onGround) {
    this->onGround = onGround;
}

// Returns whether the player is on the ground.
bool PlayerController::isOnGround() const {
    return onGround;
}

// Returns the shape of the player.
const sf::CircleShape& PlayerController::getPlayerShape() const {
    return playerView.getShape();
}

// Returns the direction the player is facing.
float PlayerController::getDirection() const {
    return player.getDirection();
}

// Returns a reference to the player object.
Player& PlayerController::getPlayer() {
    return player;
}

// Returns a reference to the player's projectiles.
std::vector<Projectile>& PlayerController::getProjectiles() {
    return projectileController.getProjectiles();
}

// Handles collisions between the player and a tile.
void PlayerController::handleCollision(const sf::RectangleShape& tileShape) {
    const auto& playerShape = getPlayerShape();
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

    enum CollisionType { NONE, LEFT, RIGHT, TOP, BOTTOM };
    CollisionType collision = NONE;

    if (overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight) {
        collision = TOP;
    } else if (overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight) {
        collision = BOTTOM;
    } else if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
        collision = LEFT;
    } else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
        collision = RIGHT;
    }

    const float marginH = 2.0f; // Adjust this value to increase the distance between the player and the tile
    const float marginV = 0.0f; // Adjust this value to increase the distance between the player and the tile

    switch (collision) {
        case TOP:
            setPosition(playerX, tileY - playerRadius * 2 - marginV);
            resetVerticalSpeed();
            setJumping(false);
            setOnGround(true);
            break;
        case BOTTOM:
            setPosition(playerX, tileY + tileSize + marginV);
            resetVerticalSpeed();
            setOnGround(false);
            break;
        case LEFT:
            setPosition(tileX - playerRadius * 2 - marginH, playerY);
            break;
        case RIGHT:
            setPosition(tileX + tileSize + marginH, playerY);
            break;
        default:
            break;
    }
}
