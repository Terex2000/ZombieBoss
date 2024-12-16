#include "MapView.h"
#include <iostream>

// Constructor for MapView
// Initializes the map view with the provided map and texture manager.
MapView::MapView(const Map& map, TextureManager& textureManager) 
    : map(map), tileset(textureManager.getTexture("tileset")) {
    vertices = map.getVertices();
}

// Draws the map and its tiles to the window.
void MapView::draw(sf::RenderWindow& window) {
    // Draw the vertex array with the tileset texture
    window.draw(vertices, &tileset);
}