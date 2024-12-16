#include "Tiles.h"

// Constructor for Tiles
// Initializes the tile with a type and position.
Tiles::Tiles(int type, int x, int y) : type(type), x(x), y(y) {}

// Returns the type of the tile.
int Tiles::getType() const {
    return type;
}

// Returns the x-coordinate of the tile.
int Tiles::getX() const {
    return x;
}

// Returns the y-coordinate of the tile.
int Tiles::getY() const {
    return y;
}