#include "ZombieView.h"
#include "Zombie.h" // Include for Zombie

ZombieView::ZombieView() {}

ZombieView::~ZombieView() {}

void ZombieView::draw(sf::RenderWindow& window, const Enemy& enemy) {
    const Zombie& zombie = dynamic_cast<const Zombie&>(enemy);
    window.draw(zombie.getSprite());
}