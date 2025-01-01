#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"

class EnemyFactory {
public:
    virtual ~EnemyFactory() {}
    virtual Enemy* createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture) = 0;
    virtual Enemy* createBoss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture) = 0;
};

#endif // ENEMYFACTORY_H