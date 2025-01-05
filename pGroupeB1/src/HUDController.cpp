#include "HUDController.h"
#include "iostream"

HUDController::HUDController(Player& player, Boss* boss)
    : player(player), boss(boss) {}

void HUDController::update() {
    hudView.update(player, boss);
    std::cerr << "Debug: HUD updated with bullet damage = " << player.getBulletDamage() << std::endl;
}

void HUDController::draw(sf::RenderWindow& window) {
    hudView.draw(window);
}

void HUDController::setBoss(Boss* boss) {
    this->boss = boss;
}
