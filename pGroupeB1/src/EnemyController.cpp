#include "EnemyController.h"

EnemyController::EnemyController(EnemyFactory& factory)
    : factory(factory) {}

EnemyController::~EnemyController() {
    for (auto enemy : enemies) {
        delete enemy;
    }
}

void EnemyController::createEnemy(float x, float y, float health, float attack, float speed) {
    enemies.push_back(factory.createEnemy(x, y, health, attack, speed));
}

void EnemyController::draw(sf::RenderWindow& window) {
    for (auto enemy : enemies) {
        zombieView.draw(window, *enemy);
    }
}

void EnemyController::update(float deltaTime) {
    for (auto it = enemies.begin(); it != enemies.end();) {
        if ((*it)->getHealth() <= 0) {
            delete *it;
            it = enemies.erase(it);
        } else {
            ++it;
        }
    }
}

std::vector<Enemy*>& EnemyController::getEnemies() {
    return enemies;
}