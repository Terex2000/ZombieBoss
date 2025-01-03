#include "World.h"

World::World(const std::vector<Level>& levels, const std::string& tileset)
    : levels(levels), tileset(tileset) {}

const std::vector<Level>& World::getLevels() const {
    return levels;
}

const std::string& World::getTileset() const {
    return tileset;
}