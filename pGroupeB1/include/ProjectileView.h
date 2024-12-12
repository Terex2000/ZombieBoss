#ifndef PROJECTILEVIEW_H
#define PROJECTILEVIEW_H

#include <SFML/Graphics.hpp>
#include "Projectile.h"

class ProjectileView {
public:
    ProjectileView();
    ~ProjectileView();
    void draw(sf::RenderWindow& window, const Projectile& projectile) const;

private:
};

#endif // PROJECTILEVIEW_H