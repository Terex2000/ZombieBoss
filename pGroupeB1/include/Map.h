#ifndef MAP_H
#define MAP_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Tiles.h"

// The Map class represents the map model, containing a grid of tiles.
class Map {
public:
    // Constructor that initializes the map with the provided map data.
    Map(const std::vector<std::vector<int>>& mapData, const sf::Texture& tileset);

    // Returns a constant reference to the map data.
    const std::vector<std::vector<Tiles>>& getData() const;

    // Returns a vertex array representing the map.
    const sf::VertexArray& getVertices() const;

private:
    std::vector<std::vector<Tiles>> data; // 2D vector of tiles representing the map
    sf::VertexArray vertices; // Vertex array for rendering the map
    void createVertices(const sf::Texture& tileset); // Helper method to create the vertex array
};

#endif // MAP_H