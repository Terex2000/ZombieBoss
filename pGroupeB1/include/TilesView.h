#ifndef TILESVIEW_H
#define TILESVIEW_H

#include <SFML/Graphics.hpp>
#include "Tiles.h"
#include "TextureManager.h"

class TilesView {
public:
    TilesView(const Tiles& tile, int x, int y, TextureManager& textureManager);
    void draw(sf::RenderWindow& window);

private:
    const Tiles& tile;
    sf::Sprite sprite;
};

#endif // TILESVIEW_H