#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Tiles.h"

// The Map class represents the map model, containing a grid of tiles.
class Map {
public:
    // Constructor that initializes the map with the provided map data.
    Map(const std::vector<std::vector<int>>& mapData);

    // Returns a constant reference to the map data.
    const std::vector<std::vector<Tiles>>& getData() const;

private:
    std::vector<std::vector<Tiles>> data; // 2D vector of tiles representing the map
};

#endif // MAP_H