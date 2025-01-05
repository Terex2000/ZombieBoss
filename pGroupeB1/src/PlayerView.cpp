#include "PlayerView.h"
#include <iostream>

// Constructor for PlayerView
// Initializes the player view with a reference to the player.
PlayerView::PlayerView(Player& player, TextureManager& textureManager) : player(player), textureManager(textureManager) {
    shape.setRadius(player.getRadius());
    shape.setFillColor(player.getColor());
    shape.setPosition(player.getPosition());
    sprite.setPosition(player.getPosition());
}

// Copy constructor for PlayerView
PlayerView::PlayerView(const PlayerView& other) : player(other.player), textureManager(other.textureManager), shape(other.shape), sprite(other.sprite) {}

// Copy assignment operator for PlayerView
PlayerView& PlayerView::operator=(const PlayerView& other) {
    if (this != &other) {
        player = other.player;
        textureManager = other.textureManager;
        shape = other.shape;
        sprite = other.sprite;
    }
    return *this;
}

// Destructor for PlayerView
PlayerView::~PlayerView() {}

// Draws the player to the window.
void PlayerView::draw(sf::RenderWindow& window) {
    updateShape();
    updateSprite();
    window.draw(sprite);
    //window.draw(shape);
}

// Updates the shape's position and color based on the player's state.
void PlayerView::updateSprite() {
    sprite.setPosition(player.getPosition());
    if (player.getDirection() > 0) {
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
    } else {
        switch (player.getState()) {
            case Player::State::Idle:
                sprite.setTexture(textureManager.getTexture("Idle_Left"));
                break;
            case Player::State::Jump:
                sprite.setTexture(textureManager.getTexture("Jump_Left"));
                break;
            case Player::State::Run:
                sprite.setTexture(textureManager.getTexture("Run_Left"));
                break;
            case Player::State::Shot_2:
                sprite.setTexture(textureManager.getTexture("Shot_2_Left"));
                break;
        }
    }
        // Set the scale of the sprite to match the player's shape
    float scaleX = player.getRadius() * 2 / sprite.getTexture()->getSize().x;
    float scaleY = player.getRadius() * 2 / sprite.getTexture()->getSize().y;
    sprite.setScale(scaleX, scaleY);
}


void PlayerView::updateShape() {
    shape.setPosition(player.getPosition());
    shape.setFillColor(player.getColor());
}

const sf::CircleShape& PlayerView::getShape() const {
    return shape;
}
// Returns the shape of the player.
const sf::Sprite& PlayerView::getSprite() const {
    return sprite;
}