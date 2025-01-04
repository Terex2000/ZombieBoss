#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "MapView.h"
#include "TextureManager.h"
#include <iostream>

class MapController {
public:
    MapController(const std::vector<std::vector<int>>& mapData, TextureManager& textureManager, const std::unordered_set<int>& teleportTiles);
    void draw(sf::RenderWindow& window);
    const Map& getMap() const;
    int getMapWidth() const;
    int getMapHeight() const;
    bool checkTeleport(const sf::Vector2f& playerPosition); // New method to check for teleportation
    void debugPlayerTile(const sf::Vector2f& playerPosition);

private:
    Map map;
    MapView mapView;
};

#endif // MAPCONTROLLER_H
