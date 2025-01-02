#include "BossFactory.h"

BossFactory::BossFactory() {}

BossFactory::~BossFactory() {}

Enemy* BossFactory::createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins, const sf::Texture& texture) {
    // This factory does not create regular enemies, return nullptr or handle appropriately
    return nullptr;
}

Enemy* BossFactory::createBoss(float x, float y, float health, float attack, float speed, int coins, const sf::Texture& texture, bool isFinalBoss, float shield) {
    return new Boss(x, y, health, attack, speed, coins, texture, isFinalBoss, shield);
}