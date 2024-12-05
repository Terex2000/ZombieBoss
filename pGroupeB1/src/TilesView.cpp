#include "TilesView.h"
#include <iostream>

TilesView::TilesView(const Tiles& tile, int x, int y, TextureManager& textureManager) : tile(tile) {
    int tileSize = 32;
    sf::Texture& tileset = textureManager.getTexture("tileset");

    if (tileset.getSize().x == 0 || tileset.getSize().y == 0) {
        std::cerr << "Error: Tileset texture is not loaded correctly" << std::endl;
        return;
    }

    int tilesetWidth = tileset.getSize().x / tileSize;

    int tu = tile.getType() % tilesetWidth;
    int tv = tile.getType() / tilesetWidth;

    sprite.setTexture(tileset);
    sprite.setPosition(x, y);
    sprite.setTextureRect(sf::IntRect(tu * tileSize, tv * tileSize, tileSize, tileSize));
}

void TilesView::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}