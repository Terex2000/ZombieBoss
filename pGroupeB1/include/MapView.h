#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "TilesView.h"
#include "TextureManager.h"

class MapView {
public:
    MapView(const Map& map, TextureManager& textureManager);
    void draw(sf::RenderWindow& window);

private:
    const Map& map;
    std::vector<TilesView> tilesViews;
};

#endif // MAPVIEW_H