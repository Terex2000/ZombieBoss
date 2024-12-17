#include "Map.h"

// Constructor for Map
// Initializes the map with the provided map data.
Map::Map(const std::vector<std::vector<int>>& mapData, const sf::Texture& tileset) {
    // Iterate through the map data to create tiles
    for (size_t i = 0; i < mapData.size(); ++i) {
        std::vector<Tiles> tileRow;
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            // Create a tile with the type and position
            tileRow.emplace_back(mapData[i][j], j, i);
        }
        // Add the row of tiles to the map data
        data.push_back(tileRow);
    }
    createVertices(tileset); // Create the vertex array
}

// Returns a constant reference to the map data
// This method provides access to the 2D vector of tiles representing the map.
const std::vector<std::vector<Tiles>>& Map::getData() const {
    return data;
}

// Returns a vertex array representing the map
const sf::VertexArray& Map::getVertices() const {
    return vertices;
}

// Helper method to create the vertex array
void Map::createVertices(const sf::Texture& tileset) {
    int tileSize = 32; // Size of each tile in pixels
    vertices.setPrimitiveType(sf::Triangles);
    vertices.resize(data.size() * data[0].size() * 6); // 6 vertices per tile (2 triangles)

    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            int tileNumber = data[i][j].getType();

            int tu = tileNumber % (tileset.getSize().x / tileSize);
            int tv = tileNumber / (tileset.getSize().x / tileSize);

            sf::Vertex* triangle = &vertices[(i * data[i].size() + j) * 6];

            // First triangle
            triangle[0].position = sf::Vector2f(j * tileSize, i * tileSize);
            triangle[1].position = sf::Vector2f((j + 1) * tileSize, i * tileSize);
            triangle[2].position = sf::Vector2f(j * tileSize, (i + 1) * tileSize);

            triangle[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
            triangle[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
            triangle[2].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);

            // Second triangle
            triangle[3].position = sf::Vector2f((j + 1) * tileSize, i * tileSize);
            triangle[4].position = sf::Vector2f((j + 1) * tileSize, (i + 1) * tileSize);
            triangle[5].position = sf::Vector2f(j * tileSize, (i + 1) * tileSize);

            triangle[3].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
            triangle[4].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
            triangle[5].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
        }
    }
}