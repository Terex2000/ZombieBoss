#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <SFML/Graphics.hpp>
#include "Map.h"
#include "TilesView.h"
#include "TextureManager.h"

// The MapView class is responsible for rendering the map and its tiles.
class MapView {
public:
    // Constructor that initializes the map view with the provided map and texture manager.
    MapView(const Map& map, TextureManager& textureManager);

    // Draws the map and its tiles to the window.
    void draw(sf::RenderWindow& window);

private:
    const Map& map; // Reference to the map model
    std::vector<TilesView> tilesViews; // Vector of tile views for rendering
    sf::Sprite backgroundSprite; // Sprite for rendering the background
};

#endif // MAPVIEW_H