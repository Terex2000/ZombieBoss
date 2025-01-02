#ifndef BOSSFACTORY_H
#define BOSSFACTORY_H

#include "EnemyFactory.h"
#include "Boss.h"

class BossFactory : public EnemyFactory {
public:
    BossFactory();
    virtual ~BossFactory();
    Enemy* createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture) override;
    Enemy* createBoss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture, bool isFinalBoss) override;
};

#endif // BOSSFACTORY_H