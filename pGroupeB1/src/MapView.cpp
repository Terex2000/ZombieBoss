#include "MapView.h"
#include <iostream>

MapView::MapView(const Map& map, TextureManager& textureManager) : map(map) {
    const auto& data = map.getData();
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            tilesViews.emplace_back(data[i][j], j * 32, i * 32, textureManager);
        }
    }

    // Initialize background sprite
    backgroundSprite.setTexture(textureManager.getTexture("background"));
}

void MapView::draw(sf::RenderWindow& window) {
    // Draw background
    window.draw(backgroundSprite);

    // Draw tiles
    for (auto& tileView : tilesViews) {
        tileView.draw(window);
    }
}