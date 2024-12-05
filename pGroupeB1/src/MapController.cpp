#include "MapController.h"

MapController::MapController(const std::vector<std::vector<int>>& mapData, TextureManager& textureManager)
    : map(mapData), mapView(map, textureManager) {}

void MapController::draw(sf::RenderWindow& window) {
    mapView.draw(window);
}

const Map& MapController::getMap() const {
    return map;
}