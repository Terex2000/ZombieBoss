#include "HUDController.h"

// Constructor: Initializes the HUDController with references to the player and the boss
HUDController::HUDController(Player& player, Boss* boss)
    : player(player), boss(boss) {}

// Updates the HUD elements based on the current state of the player and the boss
void HUDController::update() {
    hudView.update(player, boss);
}

// Draws the HUD elements on the window
void HUDController::draw(sf::RenderWindow& window) {
    hudView.draw(window);
}

// Sets the boss reference to a new boss
void HUDController::setBoss(Boss* boss) {
    this->boss = boss;
}
