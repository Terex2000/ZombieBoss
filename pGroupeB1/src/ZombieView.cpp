#include "ZombieView.h"
#include "Zombie.h" // Include for Zombie

// Constructor for ZombieView
ZombieView::ZombieView() {}

// Destructor for ZombieView
ZombieView::~ZombieView() {}

// Draws the zombie to the window.
void ZombieView::draw(sf::RenderWindow& window, const Enemy& enemy) {
    // Cast the enemy to a Zombie type
    const Zombie& zombie = dynamic_cast<const Zombie&>(enemy);
    // Draw the zombie sprite
    window.draw(zombie.getSprite());
}
