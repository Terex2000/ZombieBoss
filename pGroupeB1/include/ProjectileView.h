#ifndef PROJECTILEVIEW_H
#define PROJECTILEVIEW_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"

// The ProjectileView class is responsible for rendering a projectile.
class ProjectileView {
public:
    ProjectileView();
    ~ProjectileView();

    // Draws the projectile to the window.
    void draw(sf::RenderWindow& window, const Projectile& projectile) const;

private:
};

#endif // PROJECTILEVIEW_H