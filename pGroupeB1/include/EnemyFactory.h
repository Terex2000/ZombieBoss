#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"

class EnemyFactory {
public:
    virtual ~EnemyFactory() {}
    virtual Enemy* createEnemy(float x, float y, float health, float attack, float speed) = 0;
};

#endif // ENEMYFACTORY_H