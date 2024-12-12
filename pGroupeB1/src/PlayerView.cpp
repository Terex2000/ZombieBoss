#include "PlayerView.h"

PlayerView::PlayerView(Player& player) : player(player) {
    shape.setRadius(player.getRadius());
    shape.setFillColor(player.getColor());
    shape.setPosition(player.getPosition());
}

PlayerView::PlayerView(const PlayerView& other) : player(other.player), shape(other.shape) {}

PlayerView& PlayerView::operator=(const PlayerView& other) {
    if (this != &other) {
        player = other.player;
        shape = other.shape;
    }
    return *this;
}

PlayerView::~PlayerView() {}

void PlayerView::draw(sf::RenderWindow& window) {
    updateShape();
    window.draw(shape);
}

void PlayerView::updateShape() {
    shape.setPosition(player.getPosition());
    shape.setFillColor(player.getColor());
}

const sf::CircleShape& PlayerView::getShape() const {
    return shape;
}