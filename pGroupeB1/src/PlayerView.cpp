#include "PlayerView.h"
#include <iostream>

// Constructor for PlayerView
// Initializes the player view with a reference to the player.
PlayerView::PlayerView(Player& player, TextureManager& textureManager) : player(player), textureManager(textureManager) {
    sprite.setTexture(textureManager.getTexture("Idle"));
    sprite.setTextureRect(sf::IntRect(0, 0, 42, 69));
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
    }
    return *this;
}

// Destructor for PlayerView
PlayerView::~PlayerView() {}

// Draws the player to the window.
void PlayerView::draw(sf::RenderWindow& window) {
    updateSprite();
    window.draw(sprite);
}



// Updates the shape's position and color based on the player's state.
void PlayerView::updateSprite() {
    sprite.setPosition(player.getHitbox().left, player.getHitbox().top);

    switch (player.getState()) {
        case Player::State::Idle:
            sprite.setTexture(textureManager.getTexture("Idle"));
            break;
        case Player::State::Jump:
            sprite.setTexture(textureManager.getTexture("Jump"));
            break;
        case Player::State::Run:
            sprite.setTexture(textureManager.getTexture("Run"));
            break;
        case Player::State::Shot_2:
            sprite.setTexture(textureManager.getTexture("Shot_2"));
            break;
    }
}

// Returns the shape of the player.
const sf::Sprite& PlayerView::getSprite() const {
    return sprite;
}
