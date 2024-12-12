#include "PlayerController.h"

PlayerController::PlayerController(float startX, float startY) 
    : player(), playerView(player), projectileController(), verticalSpeed(0.0f), isJumping(false), onGround(false) {
    player.setPosition(startX, startY);
    player.setColor(sf::Color::Red);
}

PlayerController::PlayerController(const PlayerController& other)
    : player(other.player), playerView(player), projectileController(), verticalSpeed(other.verticalSpeed), isJumping(other.isJumping), onGround(other.onGround) {}

PlayerController& PlayerController::operator=(const PlayerController& other) {
    if (this != &other) {
        player = other.player;
        playerView = PlayerView(player);
        projectileController = other.projectileController;
        verticalSpeed = other.verticalSpeed;
        isJumping = other.isJumping;
        onGround = other.onGround;
    }
    return *this;
}

PlayerController::~PlayerController() {}

void PlayerController::draw(sf::RenderWindow& window) {
    playerView.draw(window);
    projectileController.draw(window);
}

void PlayerController::move(float dx, float dy) {
    player.move(dx, dy);
}

void PlayerController::update(float deltaTime, const sf::View& cameraView) {
    if (!onGround) {
        verticalSpeed += gravity * deltaTime;
        move(0, verticalSpeed * deltaTime);
    }
    projectileController.update(deltaTime, cameraView);
}

void PlayerController::setPosition(float x, float y) {
    player.setPosition(x, y);
}

void PlayerController::jump() {
    if (onGround) {
        isJumping = true;
        onGround = false;
        verticalSpeed = jumpSpeed;
    }
}

void PlayerController::shoot() {
    sf::Vector2f position = player.getPosition();
    float direction = player.getDirection();
    projectileController.shoot(position, direction);
}

void PlayerController::resetVerticalSpeed() {
    verticalSpeed = 0.0f;
}

void PlayerController::setJumping(bool jumping) {
    isJumping = jumping;
}

void PlayerController::setOnGround(bool onGround) {
    this->onGround = onGround;
}

bool PlayerController::isOnGround() const {
    return onGround;
}

const sf::CircleShape& PlayerController::getPlayerShape() const {
    return playerView.getShape();
}

float PlayerController::getDirection() const {
    return player.getDirection();
}

Player& PlayerController::getPlayer() {
    return player;
}

std::vector<Projectile>& PlayerController::getProjectiles() {
    return projectileController.getProjectiles();
}

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

    bool fromLeft = overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom;
    bool fromRight = overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom;
    bool fromTop = overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight;
    bool fromBottom = overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight;

    if (fromLeft) {
        setPosition(tileX - playerRadius * 2, playerY);
    } else if (fromRight) {
        setPosition(tileX + tileSize, playerY);
    } else if (fromTop) {
        setPosition(playerX, tileY - playerRadius * 2);
        resetVerticalSpeed();
        setJumping(false);
        setOnGround(true);
    } else if (fromBottom) {
        setPosition(playerX, tileY + tileSize);
        resetVerticalSpeed();
    }
}