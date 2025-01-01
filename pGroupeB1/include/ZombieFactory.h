#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H

#include "EnemyFactory.h"
#include "Zombie.h"

class ZombieFactory : public EnemyFactory {
public:
    ZombieFactory();
    virtual ~ZombieFactory();
    Enemy* createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, const sf::Texture& texture) override;
};

#endif // ZOMBIEFACTORY_H