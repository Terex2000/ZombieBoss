#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <cmath> // Include for std::abs

class Zombie : public Enemy {
public:
    Zombie(float x, float y, float health, float attack, float speed, float maxDistance, const sf::Texture& texture);
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

    void update(float deltaTime);

    const sf::Sprite& getSprite() const;

private:
    sf::Vector2f position;
    sf::Vector2f origin;
    float health;
    float attack;
    float speed;
    float maxDistance;
    float direction;
    sf::Sprite sprite;
};

#endif // ZOMBIE_H