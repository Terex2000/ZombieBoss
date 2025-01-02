#include "ZombieFactory.h"

ZombieFactory::ZombieFactory() {}

ZombieFactory::~ZombieFactory() {}

Enemy* ZombieFactory::createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture) {
    return new Zombie(x, y, health, attack, speed, maxDistance, coins, texture);
}

Enemy* ZombieFactory::createBoss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture, bool isFinalBoss) {
    // This factory does not create bosses, return nullptr or handle appropriately
    return nullptr;
}