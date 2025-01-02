#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include "Enemy.h"
#include "EnemyFactory.h"
#include "ZombieView.h"
#include "BossView.h"
#include "ProjectileController.h"
#include "TextureManager.h"
#include "Player.h"
#include <vector>
#include <SFML/Graphics.hpp>

class EnemyController {
public:
    EnemyController(EnemyFactory& factory, TextureManager& textureManager);
    virtual ~EnemyController();

    void createEnemy(float x, float y, float health, float attack, float speed, float maxDistance, int coins);
    void createBoss(float x, float y, float health, float attack, float speed, int coins, bool isFinalBoss = false, float shield = 0.0f);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime, const sf::Vector2f& playerPosition, Player& player);
    std::vector<Enemy*>& getEnemies();
    ProjectileController& getProjectileController();

private:
    std::vector<Enemy*> enemies;
    EnemyFactory& factory;
    ZombieView zombieView;
    BossView bossView;
    ProjectileController projectileController;
    TextureManager& textureManager;
};

#endif // ENEMYCONTROLLER_H