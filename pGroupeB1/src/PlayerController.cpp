#include "PlayerController.h"

// Constructor for PlayerController
// Initializes the player controller with a starting position and texture manager.
PlayerController::PlayerController(float startX, float startY, TextureManager& textureManager)
    : player(), playerView(player), projectileController(), textureManager(textureManager), verticalSpeed(0.0f), isJumping(false), onGround(false) {
    player.setPosition(startX, startY);
    player.setColor(sf::Color::Red);
    if (!textureManager.loadTexture("bullet", "assets/img/bullet.png")) {
        std::cerr << "Error: Failed to load bullet texture" << std::endl;
    }
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
        player.move(0, verticalSpeed * deltaTime);
        if (player.getPosition().y >= 544.0f) { // Exemple de sol à 544 pixels
            player.setPosition(player.getPosition().x, 544.0f);
            onGround = true;
            verticalSpeed = 0.0f;
        }
    } else {
        verticalSpeed = 0.0f;
    }

    // Mise à jour des projectiles
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
        std::cout << "Jumping: verticalSpeed = " << verticalSpeed << std::endl;
    }
}

// Makes the player shoot a projectile.
void PlayerController::shoot() {
    sf::Vector2f position = player.getPosition();
    sf::Vector2f direction = sf::Vector2f(player.getDirection(), 0.0f); // Use a Vector2f for the direction
    projectileController.shoot(position, direction, textureManager.getTexture("bullet"), 10.0f); // Example damage
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
    float playerBottom = playerShape.getPosition().y + playerShape.getRadius() * 2;
    float tileTop = tileShape.getPosition().y;

    if (playerBottom > tileTop && playerBottom - tileTop < 5.0f) {
        setPosition(playerShape.getPosition().x, tileTop - playerShape.getRadius() * 2);
        setOnGround(true);
        resetVerticalSpeed();
        std::cout << "Collision detected: Player landed on tile.\n";
    } else {
        std::cout << "No collision: Player not on tile.\n";
        setOnGround(false);
    }
}


