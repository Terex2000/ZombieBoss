#include "ZombieFactory.h"

ZombieFactory::ZombieFactory() {}

ZombieFactory::~ZombieFactory() {}

Enemy* ZombieFactory::createEnemy(float x, float y, float health, float attack, float speed, float maxDistance) {
    return new Zombie(x, y, health, attack, speed, maxDistance);
}