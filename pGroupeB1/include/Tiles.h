#ifndef TILES_H
#define TILES_H

class Tiles {
public:
    Tiles(int type, int x, int y);
    int getType() const;
    int getX() const;
    int getY() const;

private:
    int type;
    int x;
    int y;
};

#endif // TILES_H