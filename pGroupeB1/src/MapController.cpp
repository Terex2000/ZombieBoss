#include "MapController.h"

// Constructor: Initializes the MapController with map data, texture manager, and teleport tiles
MapController::MapController(const std::vector<std::vector<int>>& mapData, TextureManager& textureManager, const std::unordered_set<int>& teleportTiles)
    : map(mapData, textureManager.getTexture("tileset"), teleportTiles), mapView(map, textureManager) {}

// Draws the map on the window
void MapController::draw(sf::RenderWindow& window) {
    mapView.draw(window);
}

// Returns a constant reference to the map
const Map& MapController::getMap() const {
    return map;
}

// Returns the width of the map in pixels
int MapController::getMapWidth() const {
    return map.getData()[0].size() * 32; // Assuming each tile is 32x32 pixels
}

// Returns the height of the map in pixels
int MapController::getMapHeight() const {
    return map.getData().size() * 32; // Assuming each tile is 32x32 pixels
}

// Checks if the player's position is on a teleport tile
bool MapController::checkTeleport(const sf::Vector2f& playerPosition) {
    int tileX = static_cast<int>(playerPosition.x) / 32;
    int tileY = static_cast<int>(playerPosition.y) / 32;
    int tileType = map.getData()[tileY][tileX].getType();
    return map.isTeleportTile(tileType);
}
