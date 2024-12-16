#include "TilesView.h"
#include <iostream>

// Constructor for TilesView
// Initializes the sprite for a tile using the provided texture manager.
TilesView::TilesView(const Tiles& tile, int x, int y, TextureManager& textureManager) : tile(tile) {
    int tileSize = 32; // Size of each tile in pixels
    sf::Texture& tileset = textureManager.getTexture("tileset");

    // Check if the tileset texture is loaded correctly
    if (tileset.getSize().x == 0 || tileset.getSize().y == 0) {
        std::cerr << "Error: Tileset texture is not loaded correctly" << std::endl;
        return;
    }

    int tilesetWidth = tileset.getSize().x / tileSize;

    // Calculate the texture coordinates for the tile
    int tu = tile.getType() % tilesetWidth;
    int tv = tile.getType() / tilesetWidth;

    // Set the texture and position for the sprite
    sprite.setTexture(tileset);
    sprite.setPosition(x, y);
    sprite.setTextureRect(sf::IntRect(tu * tileSize, tv * tileSize, tileSize, tileSize));
}

// Draws the tile sprite to the window
void TilesView::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}