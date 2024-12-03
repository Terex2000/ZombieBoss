#include "MapView.h"

MapView::MapView(const Map& map) : map(map) {
    const auto& data = map.getData();
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            tilesViews.emplace_back(data[i][j], j * 32, i * 32);
        }
    }
}

void MapView::draw(sf::RenderWindow& window) {
    for (auto& tileView : tilesViews) {
        tileView.draw(window);
    }
}