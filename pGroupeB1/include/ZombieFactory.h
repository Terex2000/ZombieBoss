#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H

#include "EnemyFactory.h"
#include "Zombie.h"

class ZombieFactory : public EnemyFactory {
public:
    ZombieFactory();
    virtual ~ZombieFactory();
    Enemy* createEnemy(float x, float y, float health, float attack, float speed) override;
};

#endif // ZOMBIEFACTORY_H