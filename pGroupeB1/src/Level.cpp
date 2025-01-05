#include "Level.h"

// Constructor: Initializes the Level with map file, boss map file, enemies, and bosses
Level::Level(const std::string& mapFile, const std::string& bossMapFile, const std::vector<EnemyInfo>& enemies, const std::vector<BossInfo>& bosses)
    : mapFile(mapFile), bossMapFile(bossMapFile), enemies(enemies), bosses(bosses) {}

// Returns the map file path for the level
const std::string& Level::getMapFile() const {
    return mapFile;
}

// Returns the boss map file path for the level
const std::string& Level::getBossMapFile() const {
    return bossMapFile;
}

// Returns the list of enemies in the level
const std::vector<EnemyInfo>& Level::getEnemies() const {
    return enemies;
}

// Returns the list of bosses in the level
const std::vector<BossInfo>& Level::getBosses() const {
    return bosses;
}
