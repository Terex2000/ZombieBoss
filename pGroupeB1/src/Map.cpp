#include "Map.h"

// Constructor: Initializes the Map with map data, tileset texture, and teleport tiles
Map::Map(const std::vector<std::vector<int>>& mapData, const sf::Texture& tileset, const std::unordered_set<int>& teleportTiles)
    : teleportTiles(teleportTiles) {
    for (size_t i = 0; i < mapData.size(); ++i) {
        std::vector<Tiles> tileRow;
        for (size_t j = 0; j < mapData[i].size(); ++j) {
            tileRow.emplace_back(mapData[i][j], j, i);
        }
        data.push_back(tileRow);
    }
    createVertices(tileset);
}

// Returns the map data as a 2D vector of Tiles
const std::vector<std::vector<Tiles>>& Map::getData() const {
    return data;
}

// Returns the vertex array for rendering the map
const sf::VertexArray& Map::getVertices() const {
    return vertices;
}

// Checks if a tile type is a teleport tile
bool Map::isTeleportTile(int tileType) const {
    return teleportTiles.find(tileType) != teleportTiles.end();
}

// Creates the vertex array for rendering the map using the tileset texture
void Map::createVertices(const sf::Texture& tileset) {
    int tileSize = 32;
    vertices.setPrimitiveType(sf::Triangles);
    vertices.resize(data.size() * data[0].size() * 6);

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
