#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    virtual ~Enemy() {}

    virtual void setPosition(float x, float y) = 0;
    virtual const sf::Vector2f& getPosition() const = 0;

    virtual void setHealth(float health) = 0;
    virtual float getHealth() const = 0;

    virtual void setAttack(float attack) = 0;
    virtual float getAttack() const = 0;

    virtual void setSpeed(float speed) = 0;
    virtual float getSpeed() const = 0;

    virtual void takeDamage(float damage) = 0;
};

#endif // ENEMY_H