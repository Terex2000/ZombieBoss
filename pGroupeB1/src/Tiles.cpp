#include "Tiles.h"

Tiles::Tiles(int type, int x, int y) : type(type), x(x), y(y) {}

int Tiles::getType() const {
    return type;
}

int Tiles::getX() const {
    return x;
}

int Tiles::getY() const {
    return y;
}