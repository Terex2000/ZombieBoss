#include "MapController.h"

MapController::MapController(const std::vector<std::vector<int>>& mapData, TextureManager& textureManager)
    : map(mapData), mapView(map, textureManager) {}

void MapController::draw(sf::RenderWindow& window) {
    mapView.draw(window);
}

const Map& MapController::getMap() const {
    return map;
}

int MapController::getMapWidth() const {
    return map.getData()[0].size() * 32; // Assuming each tile is 32x32 pixels
}

int MapController::getMapHeight() const {
    return map.getData().size() * 32; // Assuming each tile is 32x32 pixels
}
