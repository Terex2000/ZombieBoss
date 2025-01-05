#include "BossView.h"
#include "Boss.h" // Include for Boss

// Constructor for BossView
BossView::BossView() {
    // Set the fill color of the shield overlay to yellow with 40% transparency
    shieldOverlay.setFillColor(sf::Color(255, 255, 0, 100));
    // Set the radius of the shield overlay to 75 pixels
    shieldOverlay.setRadius(75.0f);
    // Center the shape by setting its origin to the center
    shieldOverlay.setOrigin(shieldOverlay.getRadius(), shieldOverlay.getRadius());
}

// Destructor for BossView
BossView::~BossView() {}

// Draw the boss and its shield overlay if the shield is active
void BossView::draw(sf::RenderWindow& window, const Enemy& enemy) {
    // Cast the enemy to a Boss type
    const Boss& boss = dynamic_cast<const Boss&>(enemy);
    // Draw the boss sprite
    window.draw(boss.getSprite());

    // If the boss has an active shield, draw the shield overlay
    if (boss.getShield() > 0) {
        // Scale the shield overlay to make it oval
        shieldOverlay.setScale(0.95f, 1.3f);
        // Position the shield overlay at the boss's position
        shieldOverlay.setPosition(boss.getSprite().getPosition());
        // Draw the shield overlay
        window.draw(shieldOverlay);
    }
}
