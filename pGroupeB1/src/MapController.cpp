#include "MapController.h"

MapController::MapController(const std::vector<std::vector<int>>& mapData, TextureManager& textureManager, const std::unordered_set<int>& teleportTiles)
    : map(mapData, textureManager.getTexture("tileset"), teleportTiles), mapView(map, textureManager) {}

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

bool MapController::checkTeleport(const sf::Vector2f& playerPosition) {
    int tileX = static_cast<int>(playerPosition.x) / 32;
    int tileY = static_cast<int>(playerPosition.y) / 32;
    int tileType = map.getData()[tileY][tileX].getType();
    return map.isTeleportTile(tileType);
}
