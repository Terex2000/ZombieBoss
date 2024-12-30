#include "ZombieFactory.h"

ZombieFactory::ZombieFactory() {}

ZombieFactory::~ZombieFactory() {}

Enemy* ZombieFactory::createEnemy(float x, float y, float health, float attack, float speed) {
    return new Zombie(x, y, health, attack, speed);
}