#include "ZombieView.h"

ZombieView::ZombieView() {
    shape.setRadius(15.0f); // Assuming enemy radius is 15.0f
    shape.setFillColor(sf::Color::Blue); // Blue color for enemies
}

ZombieView::~ZombieView() {}

void ZombieView::draw(sf::RenderWindow& window, const Enemy& enemy) {
    shape.setPosition(enemy.getPosition());
    window.draw(shape);
}