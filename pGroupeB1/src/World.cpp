#include "World.h"

World::World(const std::vector<Level>& levels)
    : levels(levels) {}

const std::vector<Level>& World::getLevels() const {
    return levels;
}