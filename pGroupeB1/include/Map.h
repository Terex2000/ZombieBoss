#ifndef MAP_H
#define MAP_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Tiles.h"
#include <unordered_set>

class Map {
public:
    Map(const std::vector<std::vector<int>>& mapData, const sf::Texture& tileset, const std::unordered_set<int>& teleportTiles);
    const std::vector<std::vector<Tiles>>& getData() const;
    const sf::VertexArray& getVertices() const;
    bool isTeleportTile(int tileType) const; // New method to check if a tile is a teleport tile

private:
    std::vector<std::vector<Tiles>> data;
    sf::VertexArray vertices;
    std::unordered_set<int> teleportTiles; // New attribute to store teleport tiles
    void createVertices(const sf::Texture& tileset);
};

#endif // MAP_H