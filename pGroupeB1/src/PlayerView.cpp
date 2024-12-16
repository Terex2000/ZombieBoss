#include "PlayerView.h"

// Constructor for PlayerView
// Initializes the player view with a reference to the player.
PlayerView::PlayerView(Player& player) : player(player) {
    shape.setRadius(player.getRadius());
    shape.setFillColor(player.getColor());
    shape.setPosition(player.getPosition());
}

// Copy constructor for PlayerView
PlayerView::PlayerView(const PlayerView& other) : player(other.player), shape(other.shape) {}

// Copy assignment operator for PlayerView
PlayerView& PlayerView::operator=(const PlayerView& other) {
    if (this != &other) {
        player = other.player;
        shape = other.shape;
    }
    return *this;
}

// Destructor for PlayerView
PlayerView::~PlayerView() {}

// Draws the player to the window.
void PlayerView::draw(sf::RenderWindow& window) {
    updateShape();
    window.draw(shape);
}

// Updates the shape's position and color based on the player's state.
void PlayerView::updateShape() {
    shape.setPosition(player.getPosition());
    shape.setFillColor(player.getColor());
}

// Returns the shape of the player.
const sf::CircleShape& PlayerView::getShape() const {
    return shape;
}