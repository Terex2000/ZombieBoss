#include "PlayerView.h"

PlayerView::PlayerView(Player& player) : player(player) {}

PlayerView::~PlayerView() {}

void PlayerView::draw(sf::RenderWindow& window) {
    window.draw(player.getShape());
}