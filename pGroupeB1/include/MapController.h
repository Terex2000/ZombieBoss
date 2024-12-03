#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MapView.h"
#include "TextureManager.h"

class MapController {
public:
    MapController(const std::vector<std::vector<int>>& mapData, TextureManager& textureManager);
    void draw(sf::RenderWindow& window);

private:
    Map map;
    MapView mapView;
};

#endif // MAPCONTROLLER_H