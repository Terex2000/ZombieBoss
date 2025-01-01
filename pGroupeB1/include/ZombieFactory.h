#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H

#include "EnemyFactory.h"
#include "Zombie.h"

class ZombieFactory : public EnemyFactory {
public:
    ZombieFactory();
    virtual ~ZombieFactory();
    Enemy* createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture) override;
    Enemy* createBoss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture) override;
};

#endif // ZOMBIEFACTORY_H