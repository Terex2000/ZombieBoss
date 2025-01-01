#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include <SFML/Graphics.hpp>

class Boss : public Enemy {
public:
    Boss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture);
    virtual ~Boss();

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

    int getCoins() const;

private:
    sf::Vector2f position;
    float health;
    float attack;
    float speed;
    int coins;
    sf::Sprite sprite;
};

#endif // BOSS_H