#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Level.h"

class World {
public:
    World(const std::vector<Level>& levels);

    const std::vector<Level>& getLevels() const;

private:
    std::vector<Level> levels;
};

#endif // WORLD_H