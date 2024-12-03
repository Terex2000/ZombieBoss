#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "TilesView.h"

class MapView {
public:
    MapView(const Map& map);
    void draw(sf::RenderWindow& window);

private:
    const Map& map;
    std::vector<TilesView> tilesViews;
};

#endif // MAPVIEW_H