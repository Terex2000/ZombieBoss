#include "ProjectileView.h"

ProjectileView::ProjectileView() {}

ProjectileView::~ProjectileView() {}

void ProjectileView::draw(sf::RenderWindow& window, const Projectile& projectile) const {
    window.draw(projectile.getShape());
}