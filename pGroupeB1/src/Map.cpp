#include "Map.h"

Map::Map(const std::vector<std::vector<int>>& mapData) {
    for (const auto& row : mapData) {
        std::vector<Tiles> tileRow;
        for (int tile : row) {
            tileRow.emplace_back(tile);
        }
        data.push_back(tileRow);
    }
}

const std::vector<std::vector<Tiles>>& Map::getData() const {
    return data;
}