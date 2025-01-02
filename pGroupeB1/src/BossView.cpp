#include "BossView.h"
#include "Boss.h" // Include for Boss

BossView::BossView() {
    shieldOverlay.setFillColor(sf::Color(255, 255, 0, 100)); // Yellow with 40% transparency
    shieldOverlay.setRadius(75.0f); // Set the radius to 75 pixels
    shieldOverlay.setOrigin(shieldOverlay.getRadius(), shieldOverlay.getRadius()); // Center the shape
}

BossView::~BossView() {}

void BossView::draw(sf::RenderWindow& window, const Enemy& enemy) {
    const Boss& boss = dynamic_cast<const Boss&>(enemy);
    window.draw(boss.getSprite());

    if (boss.getShield() > 0) {
        shieldOverlay.setScale(0.95f, 1.3f); // Scale to make it oval
        shieldOverlay.setPosition(boss.getSprite().getPosition());
        window.draw(shieldOverlay);
    }
}