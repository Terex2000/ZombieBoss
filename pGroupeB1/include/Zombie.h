#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Enemy.h"

class Zombie : public Enemy {
public:
    Zombie(float x, float y, float health, float attack, float speed);
    virtual ~Zombie();

    void setPosition(float x, float y) override;
    const sf::Vector2f& getPosition() const override;

    void setHealth(float health) override;
    float getHealth() const override;

    void setAttack(float attack) override;
    float getAttack() const override;

    void setSpeed(float speed) override;
    float getSpeed() const override;

    void takeDamage(float damage) override;

private:
    sf::Vector2f position;
    float health;
    float attack;
    float speed;
};

#endif // ZOMBIE_H