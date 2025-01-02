#include "Level.h"

Level::Level(const std::string& mapFile, const std::string& bossMapFile)
    : mapFile(mapFile), bossMapFile(bossMapFile) {}

const std::string& Level::getMapFile() const {
    return mapFile;
}

const std::string& Level::getBossMapFile() const {
    return bossMapFile;
}