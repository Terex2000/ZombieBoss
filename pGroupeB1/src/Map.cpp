#include "Map.h"

Map::Map(const std::vector<std::vector<int>>& mapData) {
    for (size_t i = 0; i < mapData.size(); ++i) {
        std::vector<Tiles> tileRow;
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            tileRow.emplace_back(mapData[i][j], j, i);
        }
        data.push_back(tileRow);
    }
}

const std::vector<std::vector<Tiles>>& Map::getData() const {
    return data;
}