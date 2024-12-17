#ifndef TILES_H
#define TILES_H

// The Tiles class represents a single tile in the map.
class Tiles {
public:
    // Constructor that initializes the tile with a type and position.
    Tiles(int type, int x, int y);

    // Returns the type of the tile.
    int getType() const;

    // Returns the x-coordinate of the tile.
    int getX() const;

    // Returns the y-coordinate of the tile.
    int getY() const;

private:
    int type; // Type of the tile (used for determining texture)
    int x;    // X-coordinate of the tile
    int y;    // Y-coordinate of the tile
};

#endif // TILES_H