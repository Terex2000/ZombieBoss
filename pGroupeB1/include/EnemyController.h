#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include "Enemy.h"
#include "EnemyFactory.h"
#include "ZombieView.h"
#include <vector>
#include <SFML/Graphics.hpp>

class EnemyController {
public:
    EnemyController(EnemyFactory& factory);
    virtual ~EnemyController();

    void createEnemy(float x, float y, float health, float attack, float speed);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
    std::vector<Enemy*>& getEnemies();

private:
    std::vector<Enemy*> enemies;
    EnemyFactory& factory;
    ZombieView zombieView;
};

#endif // ENEMYCONTROLLER_H