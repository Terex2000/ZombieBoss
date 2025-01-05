#include "HUDController.h"

HUDController::HUDController(Player& player, Boss* boss)
    : player(player), boss(boss) {}

void HUDController::update() {
    hudView.update(player, boss);
}

void HUDController::draw(sf::RenderWindow& window) {
    hudView.draw(window);
}

void HUDController::setBoss(Boss* boss) {
    this->boss = boss;
}