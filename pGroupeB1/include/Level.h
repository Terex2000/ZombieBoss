#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

struct EnemyInfo {
    float x, y;
    float health, attack, speed, maxDistance;
    int coins;
};

struct BossInfo {
    float x, y;
    float health, attack, speed, maxDistance;
    bool isBoss;
    int coins;
};

class Level {
public:
    Level(const std::string& mapFile, const std::string& bossMapFile, const std::vector<EnemyInfo>& enemies, const std::vector<BossInfo>& bosses);
    const std::string& getMapFile() const;
    const std::string& getBossMapFile() const;
    const std::vector<EnemyInfo>& getEnemies() const;
    const std::vector<BossInfo>& getBosses() const;

private:
    std::string mapFile;
    std::string bossMapFile;
    std::vector<EnemyInfo> enemies;
    std::vector<BossInfo> bosses;
};

#endif // LEVEL_H