#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Tiles.h"

class Map {
public:
    Map(const std::vector<std::vector<int>>& mapData);
    const std::vector<std::vector<Tiles>>& getData() const;

private:
    std::vector<std::vector<Tiles>> data;
};

#endif // MAP_H