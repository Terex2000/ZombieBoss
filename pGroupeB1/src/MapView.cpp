#include "MapView.h"
#include <iostream>

// Constructor for MapView
// Initializes the map view with the provided map and texture manager.
MapView::MapView(const Map& map, TextureManager& textureManager) : map(map) {
    const auto& data = map.getData();
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            tilesViews.emplace_back(data[i][j], j * 32, i * 32, textureManager);
        }
    }
}

// Draws the map and its tiles to the window.
void MapView::draw(sf::RenderWindow& window) {
    // Draw background
    window.draw(backgroundSprite);

    // Draw tiles
    for (auto& tileView : tilesViews) {
        tileView.draw(window);
    }
}