// PlayerView.cpp
#include "PlayerView.h"

PlayerView::PlayerView(Player& player) : player(player) {}

PlayerView::PlayerView(const PlayerView& other) : player(other.player) {}

PlayerView& PlayerView::operator=(const PlayerView& other) {
    if (this != &other) {
        player = other.player;
    }
    return *this;
}

PlayerView::~PlayerView() {}

void PlayerView::draw(sf::RenderWindow& window) {
    window.draw(player.getShape());
}