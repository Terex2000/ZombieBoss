#ifndef TILES_H
#define TILES_H

class Tiles {
public:
    Tiles(int type);
    int getType() const;

private:
    int type;
};

#endif // TILES_H