#include "TilesView.h"

TilesView::TilesView(const Tiles& tile, int x, int y) : tile(tile) {
    vertices.setPrimitiveType(sf::Triangles);
    vertices.resize(6); // 2 triangles per tile

    int tileSize = 32;

    sf::Color color = (tile.getType() == 1) ? sf::Color::Red : sf::Color::Green;

    vertices[0].position = sf::Vector2f(x, y);
    vertices[1].position = sf::Vector2f(x + tileSize, y);
    vertices[2].position = sf::Vector2f(x, y + tileSize);

    vertices[3].position = sf::Vector2f(x + tileSize, y);
    vertices[4].position = sf::Vector2f(x + tileSize, y + tileSize);
    vertices[5].position = sf::Vector2f(x, y + tileSize);

    for (int i = 0; i < 6; ++i) {
        vertices[i].color = color;
    }
}

void TilesView::draw(sf::RenderWindow& window) {
    window.draw(vertices);
}