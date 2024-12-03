#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "FileReader.h"
#include "MapController.h"
#include "TextureManager.h"

class GameController {
public:
    GameController();
    void run();

private:
    FileReader fileReader;
    TextureManager textureManager;
    MapController* mapController;
};

#endif // GAMECONTROLLER_H