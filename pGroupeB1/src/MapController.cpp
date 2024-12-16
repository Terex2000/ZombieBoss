#include "MapController.h"

// Constructor for MapController
// Initializes the map and map view with the provided map data and texture manager.
MapController::MapController(const std::vector<std::vector<int>>& mapData, TextureManager& textureManager)
    : map(mapData), mapView(map, textureManager) {}

// Draws the map using the map view.
void MapController::draw(sf::RenderWindow& window) {
    mapView.draw(window);
}

// Returns a constant reference to the map.
const Map& MapController::getMap() const {
    return map;
}

// Returns the width of the map in pixels.
int MapController::getMapWidth() const {
    return map.getData()[0].size() * 32; // Assuming each tile is 32x32 pixels
}

// Returns the height of the map in pixels.
int MapController::getMapHeight() const {
    return map.getData().size() * 32; // Assuming each tile is 32x32 pixels
}