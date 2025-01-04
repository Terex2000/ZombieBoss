#include "Level.h"

Level::Level(const std::string& mapFile, const std::string& bossMapFile, const std::vector<EnemyInfo>& enemies, const std::vector<BossInfo>& bosses)
    : mapFile(mapFile), bossMapFile(bossMapFile), enemies(enemies), bosses(bosses) {}

const std::string& Level::getMapFile() const {
    return mapFile;
}

const std::string& Level::getBossMapFile() const {
    return bossMapFile;
}

const std::vector<EnemyInfo>& Level::getEnemies() const {
    return enemies;
}

const std::vector<BossInfo>& Level::getBosses() const {
    return bosses;
}