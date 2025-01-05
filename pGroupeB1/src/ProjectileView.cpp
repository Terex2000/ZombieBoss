#include "ProjectileView.h"

// Constructor for ProjectileView
ProjectileView::ProjectileView() {}

// Destructor for ProjectileView
ProjectileView::~ProjectileView() {}

// Draws the projectile to the window.
void ProjectileView::draw(sf::RenderWindow& window, const Projectile& projectile) const {
    // Draw the shape of the projectile
    window.draw(projectile.getShape());
}
