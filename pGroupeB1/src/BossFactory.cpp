#include "BossFactory.h"

// Constructor for BossFactory
BossFactory::BossFactory() {}

// Destructor for BossFactory
BossFactory::~BossFactory() {}

// This factory does not create regular enemies, return nullptr or handle appropriately
Enemy* BossFactory::createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture) {
    return nullptr;
}

// Creates a new Boss enemy with the given parameters
Enemy* BossFactory::createBoss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture, bool isFinalBoss, float shield) {
    return new Boss(x, y, health, attack, speed, coins, texture, isFinalBoss, shield);
}
