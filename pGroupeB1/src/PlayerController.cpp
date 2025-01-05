#include "PlayerController.h"

// Constructor for PlayerController
// Initializes the player controller with a starting position and texture manager.
PlayerController::PlayerController(float startX, float startY, TextureManager& textureManager)
    : player(), playerView(player, textureManager), projectileController(), textureManager(textureManager), verticalSpeed(0.0f), isJumping(false), onGround(false) {
    player.setPosition(startX, startY);
    player.setColor(sf::Color::Red);

    // Load textures for player animations and projectiles
    if (!textureManager.loadTexture("bullet", "assets/img/bullet.png")) {
        std::cerr << "Error: Failed to load bullet texture" << std::endl;
    }
    if (!textureManager.loadTexture("Idle", "assets/player/idle.png")) {
        std::cerr << "Error: Failed to load Idle texture" << std::endl;
    }
    if (!textureManager.loadTexture("Jump", "assets/player/jump.png")) {
        std::cerr << "Error: Failed to load Jump texture" << std::endl;
    }
    if (!textureManager.loadTexture("Run", "assets/player/run.png")) {
        std::cerr << "Error: Failed to load Run texture" << std::endl;
    }
    if (!textureManager.loadTexture("Shot_2", "assets/player/Shot_2.png")) {
        std::cerr << "Error: Failed to load Shot_2 texture" << std::endl;
    }
    if (!textureManager.loadTexture("Idle_Left", "assets/player/idle_left.png")) {
        std::cerr << "Error: Failed to load Idle_Left texture" << std::endl;
    }
    if (!textureManager.loadTexture("Jump_Left", "assets/player/jump_left.png")) {
        std::cerr << "Error: Failed to load Jump_Left texture" << std::endl;
    }
    if (!textureManager.loadTexture("Run_Left", "assets/player/run_left.png")) {
        std::cerr << "Error: Failed to load Run_Left texture" << std::endl;
    }
    if (!textureManager.loadTexture("Shot_2_Left", "assets/player/Shot_2_left.png")) {
        std::cerr << "Error: Failed to load Shot_2_Left texture" << std::endl;
    }
}

// Copy constructor for PlayerController
PlayerController::PlayerController(const PlayerController& other)
    : player(other.player), playerView(player, other.textureManager), projectileController(other.projectileController), textureManager(other.textureManager), verticalSpeed(other.verticalSpeed), isJumping(other.isJumping), onGround(other.onGround) {}

// Copy assignment operator for PlayerController
PlayerController& PlayerController::operator=(const PlayerController& other) {
    if (this != &other) {
        player = other.player;
        playerView = PlayerView(player, other.textureManager);
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
    if(dx != 0){
        player.setState(Player::State::Run);
    }
}

// Updates the player's state based on the elapsed time and camera view.
void PlayerController::update(float deltaTime, const sf::View& cameraView) {
    if (!onGround) {
        verticalSpeed += gravity * deltaTime;
        move(0, verticalSpeed * deltaTime);
    }
    handleState();
    projectileController.update(deltaTime, cameraView);

    // Check if the player has no lives left
    if (player.getLives() <= 0) {
        std::cout << "Game Over! The player has no lives left." << std::endl;
        // Handle game over logic here (e.g., transition to a game over screen)
    }
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
        player.setState(Player::State::Jump);
    }
}

// Makes the player shoot a projectile.
void PlayerController::shoot() {
    sf::Vector2f position = player.getPosition();
    sf::Vector2f direction = sf::Vector2f(player.getDirection(), 0.0f); // Use a Vector2f for the direction
    projectileController.shoot(position, direction, textureManager.getTexture("bullet"), player.getBulletDamage()); // Example damage
    projectileController.getProjectiles().back().setScale(4.0f, 3.0f); // Adjust the scale here
    player.setState(Player::State::Shot_2);
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
const sf::Sprite& PlayerController::getPlayerSprite() const {
    return playerView.getSprite();
}

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

// Handles collision between the player and a tile.
void PlayerController::handleCollision(const sf::RectangleShape& tileShape) {
    const auto& playerShape = getPlayerShape();
    float playerX = playerShape.getPosition().x;
    float playerY = playerShape.getPosition().y;
    float tileX = tileShape.getPosition().x;
    float tileY = tileShape.getPosition().y;
    float playerRadius = playerShape.getRadius();
    float tileSize = tileShape.getSize().x;

    // Calculate overlaps
    float overlapLeft = (playerX + playerRadius * 2) - tileX;
    float overlapRight = (tileX + tileSize) - playerX;
    float overlapTop = (playerY + playerRadius * 2) - tileY;
    float overlapBottom = (tileY + tileSize) - playerY;

    enum CollisionType { NONE, LEFT, RIGHT, TOP, BOTTOM };
    CollisionType collision = NONE;

    // Determine the collision with the smallest overlap
    if (overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight) {
        collision = TOP;
    } else if (overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight) {
        collision = BOTTOM;
    } else if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
        collision = LEFT;
    } else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
        collision = RIGHT;
    }

    // Adjust the player's position based on the detected collision
    const float marginH = 4.5f; // Horizontal distance between the player and the tile
    const float marginV = 0.0f; // Vertical distance between the player and the tile

    switch (collision) {
        case TOP:
            setPosition(playerX, tileY - playerRadius*2 - marginV);
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
            setPosition(tileX - playerRadius*2 - marginH, playerY);
            break;
        case RIGHT:
            setPosition(tileX + playerRadius*2  + marginH, playerY);
            break;
        default:
            break;
    }
}

// Handles the player's state based on input and conditions.
void PlayerController::handleState() {
    if (onGround) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.setState(Player::State::Run);
        } else if (isJumping) {
            player.setState(Player::State::Jump);
        } else {
            player.setState(Player::State::Idle);
        }
    } else {
        if (isJumping) {
            player.setState(Player::State::Jump);
        }
    }
}
