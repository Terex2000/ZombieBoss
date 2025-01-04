#include "PlayerController.h"

// Constructor for PlayerController
// Initializes the player controller with a starting position and texture manager.
PlayerController::PlayerController(float startX, float startY, TextureManager& textureManager)
    : player(), playerView(player, textureManager), projectileController(), textureManager(textureManager), verticalSpeed(0.0f), isJumping(false), onGround(false) {
    player.setPosition(startX, startY);
    player.setColor(sf::Color::Red);
    if (!textureManager.loadTexture("bullet", "assets/img/bullet.png")) {
        std::cerr << "Error: Failed to load bullet texture" << std::endl;
    }
}

// Copy constructor for PlayerController
PlayerController::PlayerController(const PlayerController& other)
    : player(other.player), playerView(player, textureManager), projectileController(), textureManager(other.textureManager), verticalSpeed(other.verticalSpeed), isJumping(other.isJumping), onGround(other.onGround) {}

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
    projectileController.shoot(position, direction, textureManager.getTexture("bullet"), 10.0f); // Example damage
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
    const auto& playerSprite = getPlayerSprite();
    sf::FloatRect playerBounds = playerSprite.getGlobalBounds();
    sf::FloatRect tileBounds = tileShape.getGlobalBounds();

    // Calculer les chevauchements
    float overlapLeft = (playerBounds.left + playerBounds.width) - tileBounds.left;
    float overlapRight = (tileBounds.left + tileBounds.width) - playerBounds.left;
    float overlapTop = (playerBounds.top + playerBounds.height) - tileBounds.top;
    float overlapBottom = (tileBounds.top + tileBounds.height) - playerBounds.top;

    enum CollisionType { NONE, LEFT, RIGHT, TOP, BOTTOM };
    CollisionType collision = NONE;

    // D�terminer la collision avec le chevauchement le plus petit
    if (overlapTop < overlapBottom && overlapTop < overlapLeft && overlapTop < overlapRight) {
        collision = TOP;
    } else if (overlapBottom < overlapTop && overlapBottom < overlapLeft && overlapBottom < overlapRight) {
        collision = BOTTOM;
    } else if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
        collision = LEFT;
    } else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
        collision = RIGHT;
    }

    // Ajuster la position du joueur en fonction de la collision d�tect�e
    const float marginH = 2.0f; // Distance horizontale entre le joueur et la tuile
    const float marginV = 0.0f; // Distance verticale entre le joueur et la tuile

    switch (collision) {
        case TOP:
            setPosition(playerBounds.left, tileBounds.top - playerBounds.height - marginV);
            resetVerticalSpeed();
            setJumping(false);
            setOnGround(true);
            break;
        case BOTTOM:
            setPosition(playerBounds.left, tileBounds.top + tileBounds.height + marginV);
            resetVerticalSpeed();
            setOnGround(false);
            break;
        case LEFT:
            setPosition(tileBounds.left - playerBounds.width - marginH, playerBounds.top);
            break;
        case RIGHT:
            setPosition(tileBounds.left + tileBounds.width + marginH, playerBounds.top);
            break;
        default:
            break;
    }
}

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