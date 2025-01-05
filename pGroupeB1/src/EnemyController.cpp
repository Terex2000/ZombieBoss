#include "EnemyController.h"
#include "Zombie.h"
#include "Boss.h"
#include <iostream>
#include <cmath> // Include for sqrt and pow

EnemyController::EnemyController(EnemyFactory& factory, TextureManager& textureManager)
    : factory(factory), textureManager(textureManager) {   
    if (!textureManager.loadTexture("zombie", "assets/img/zombie.png")) {
        std::cerr << "Error: Failed to load zombie texture" << std::endl;
    }
    if (!textureManager.loadTexture("bullet_acid", "assets/img/bullet_acid.png")) {
        std::cerr << "Error: Failed to load bullet texture" << std::endl;
    }
    if (!textureManager.loadTexture("boss", "assets/img/boss.png")) {
        std::cerr << "Error: Failed to load bullet texture" << std::endl;
    }
    }

EnemyController::~EnemyController() {
    for (auto enemy : enemies) {
        delete enemy;
    }
}

void EnemyController::createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins) {
    enemies.push_back(factory.createEnemy(x, y, health, attack, speed, maxDistance, coins, textureManager.getTexture("zombie")));
}

void EnemyController::createBoss(float x, float y, float health, float attack, float speed, int coins, bool isFinalBoss, float shield) {
    enemies.push_back(factory.createBoss(x, y, health, attack, speed, coins, textureManager.getTexture("boss"), isFinalBoss, shield));
}

void EnemyController::draw(sf::RenderWindow& window) {
    for (auto enemy : enemies) {
        if (dynamic_cast<Zombie*>(enemy)) {
            zombieView.draw(window, *enemy);
        } else if (dynamic_cast<Boss*>(enemy)) {
            bossView.draw(window, *enemy);
        }
    }
    projectileController.draw(window);
}

void EnemyController::update(float deltaTime, const sf::Vector2f& playerPosition, Player& player, const sf::View& view) {
    for (auto it = enemies.begin(); it != enemies.end();) {
        if ((*it)->getHealth() <= 0) {
            if (dynamic_cast<Zombie*>(*it)) {
                player.addCoins(dynamic_cast<Zombie*>(*it)->getCoins());
            } else if (dynamic_cast<Boss*>(*it)) {
                player.addCoins(dynamic_cast<Boss*>(*it)->getCoins());
            }
            std::cout << "Player coins: " << player.getCoins() << std::endl;
            if (dynamic_cast<Boss*>(*it) && dynamic_cast<Boss*>(*it)->isFinalBoss()) {
                std::cout << "Player WIN" << std::endl;
            }
            delete *it;
            it = enemies.erase(it);
        } else {
            // Update enemy position
            if (dynamic_cast<Zombie*>(*it)) {
                dynamic_cast<Zombie*>(*it)->update(deltaTime);
            } else if (dynamic_cast<Boss*>(*it)) {
                dynamic_cast<Boss*>(*it)->update(deltaTime);
            }

            // Check if the enemy should shoot
            sf::Vector2f enemyPosition = (*it)->getPosition();
            enemyPosition.y -= 10.0f; // Example offset
            float distance = std::sqrt(std::pow(playerPosition.x - enemyPosition.x, 2) + std::pow(playerPosition.y - enemyPosition.y, 2));
            if (distance < 150.0f && projectileController.getProjectiles().size() < 3) { // Example distance
                sf::Vector2f direction = playerPosition - enemyPosition;
                float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                direction /= length; // Normalize the direction vector

                projectileController.shoot(enemyPosition, direction, textureManager.getTexture("bullet_acid"), (*it)->getAttack()); // Example damage

                projectileController.getProjectiles().back().setScale(2.0f, 2.0f);
            }
            ++it;
        }
    }
    projectileController.update(deltaTime, view);
}

const std::vector<Enemy*>& EnemyController::getEnemies() const{
    return enemies;
}

std::vector<Enemy*>& EnemyController::getEnemies() {
    return enemies;
}

ProjectileController& EnemyController::getProjectileController() {
    return projectileController;
}