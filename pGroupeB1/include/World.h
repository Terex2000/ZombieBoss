#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include "Level.h"

class World {
public:
    World(const std::vector<Level>& levels, const std::string& tileset);

    const std::vector<Level>& getLevels() const;
    const std::string& getTileset() const;

private:
    std::vector<Level> levels;
    std::string tileset;
};

#endif // WORLD_H