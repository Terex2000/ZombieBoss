#include "MapController.h"

MapController::MapController(const std::vector<std::vector<int>>& mapData) : map(mapData), mapView(map) {}

void MapController::draw(sf::RenderWindow& window) {
    mapView.draw(window);
}