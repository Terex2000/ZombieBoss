#include "PlayerView.h"
#include <iostream>

// Constructor for PlayerView
// Initializes the player view with a reference to the player.
PlayerView::PlayerView(Player& player, TextureManager& textureManager) : player(player), textureManager(textureManager) {
    setAnimation("Idle", 8);
    sprite.setTexture(textureManager.getTexture("Idle"));
    sprite.setTextureRect(sf::IntRect(0, 0, 60, 60));
    sprite.setPosition(player.getPosition());
}

// Copy constructor for PlayerView
PlayerView::PlayerView(const PlayerView& other) : player(other.player), textureManager(other.textureManager), sprite(other.sprite) {}

// Copy assignment operator for PlayerView
PlayerView& PlayerView::operator=(const PlayerView& other) {
    if (this != &other) {
        player = other.player;
        textureManager = other.textureManager;
        sprite = other.sprite;
        frames = other.frames;
        currentFrame = other.currentFrame;
        animationTime = other.animationTime;
    }
    return *this;
}

// Destructor for PlayerView
PlayerView::~PlayerView() {}

// Draws the player to the window.
void PlayerView::draw(sf::RenderWindow& window) {
    updateSprite();
    window.draw(sprite);

    // Adapter la hitbox au sprite avec des ajustements plus précis
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sf::RectangleShape hitboxShape(sf::Vector2f(spriteBounds.width * 0.55f, spriteBounds.height * 0.75f)); // Réduction supplémentaire
    hitboxShape.setPosition(sprite.getPosition().x + 25, sprite.getPosition().y + 20); // Ajuster les décalages
    hitboxShape.setFillColor(sf::Color(0, 0, 255, 100));
    window.draw(hitboxShape);

    // Rectangle rouge autour du sprite
    sf::RectangleShape spriteBox(sf::Vector2f(spriteBounds.width, spriteBounds.height));
    spriteBox.setPosition(sprite.getPosition());
    spriteBox.setOutlineColor(sf::Color::Red);
    spriteBox.setOutlineThickness(1);
    spriteBox.setFillColor(sf::Color::Transparent);
    window.draw(spriteBox);

    std::cout << "Player sprite drawn at position: " << sprite.getPosition().x << ", " << sprite.getPosition().y << std::endl;
}




// Updates the shape's position and color based on the player's state.
void PlayerView::updateSprite() {
    sprite.setPosition(player.getHitbox().left, player.getHitbox().top);

    // Update animation frame based on time elapsed
    animationTime += clock.restart().asSeconds();
    if (animationTime >= 0.1f) { // Change frame every 0.1 seconds
        animationTime = 0.0f;
        currentFrame = (currentFrame + 1) % frames.size();
        sprite.setTextureRect(frames[currentFrame]);
    }

    switch (player.getState()) {
        case Player::State::Idle:
            setAnimation("Idle", 8);
            sprite.setTexture(textureManager.getTexture("Idle"));
            break;
        case Player::State::Jump:
            setAnimation("Jump", 7);
            sprite.setTexture(textureManager.getTexture("Jump"));
            break;
        case Player::State::Run:
            setAnimation("Run", 8);
            sprite.setTexture(textureManager.getTexture("Run"));
            break;
        case Player::State::Shot_2:
            setAnimation("Shot_2", 4);
            sprite.setTexture(textureManager.getTexture("Shot_2"));
            break;
    }
}

// Sets up the animation frames for a specific state
void PlayerView::setAnimation(const std::string& state, int frameCount) {
    frames.clear();
    for (int i = 0; i < frameCount; ++i) {
        frames.emplace_back(i * 128, 0, 128, 128); // Assuming each frame is 128x128 pixels
    }
    currentFrame = 0;
}

// Returns the shape of the player.
const sf::Sprite& PlayerView::getSprite() const {
    return sprite;
}

// Mise à jour de la position de la hitbox visuelle
void PlayerView::updateHitboxVisual() {
    hitboxShape.setPosition(player.getPosition());
}

void PlayerView::updateSpriteBounds() {
    sf::FloatRect bounds = sprite.getGlobalBounds();
    spriteRectangle.setSize(sf::Vector2f(bounds.width, bounds.height));
    spriteRectangle.setPosition(bounds.left, bounds.top);
}
