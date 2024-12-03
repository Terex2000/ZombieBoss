#ifndef TILESVIEW_H
#define TILESVIEW_H

#include <SFML/Graphics.hpp>
#include "Tiles.h"

class TilesView {
public:
    TilesView(const Tiles& tile, int x, int y);
    void draw(sf::RenderWindow& window);

private:
    const Tiles& tile;
    sf::VertexArray vertices;
};

#endif // TILESVIEW_H