#include "ZombieFactory.h"

// Constructor for ZombieFactory
ZombieFactory::ZombieFactory() {}

// Destructor for ZombieFactory
ZombieFactory::~ZombieFactory() {}

// Creates a new Zombie enemy with the given parameters
Enemy* ZombieFactory::createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture) {
    return new Zombie(x, y, health, attack, speed, maxDistance, coins, texture);
}

// This factory does not create bosses, return nullptr or handle appropriately
Enemy* ZombieFactory::createBoss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture, bool isFinalBoss, float shield) {
    return nullptr;
}
