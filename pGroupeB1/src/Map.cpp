#include "Map.h"

// Constructor for Map
// Initializes the map with the provided map data.
Map::Map(const std::vector<std::vector<int>>& mapData) {
    // Iterate through the map data to create tiles
    for (size_t i = 0; i < mapData.size(); ++i) {
        std::vector<Tiles> tileRow;
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            // Create a tile with the type and position
            tileRow.emplace_back(mapData[i][j], j, i);
        }
        // Add the row of tiles to the map data
        data.push_back(tileRow);
    }
}

// Returns a constant reference to the map data
// This method provides access to the 2D vector of tiles representing the map.
const std::vector<std::vector<Tiles>>& Map::getData() const {
    return data;
}