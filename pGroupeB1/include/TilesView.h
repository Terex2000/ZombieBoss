#ifndef TILESVIEW_H
#define TILESVIEW_H

#include <SFML/Graphics.hpp>
#include "Tiles.h"
#include "TextureManager.h"

// The TilesView class is responsible for rendering a single tile.
class TilesView {
public:
    // Constructor that initializes the tile view with a tile, position, and texture manager.
    TilesView(const Tiles& tile, int x, int y, TextureManager& textureManager);

    // Draws the tile sprite to the window.
    void draw(sf::RenderWindow& window);

private:
    const Tiles& tile; // Reference to the tile model
    sf::Sprite sprite; // Sprite for rendering the tile
};

#endif // TILESVIEW_H