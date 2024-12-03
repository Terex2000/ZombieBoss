#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "FileReader.h"
#include "MapController.h"

class GameController {
public:
    GameController();
    void run();

private:
    FileReader fileReader;
    MapController mapController;
};

#endif // GAMECONTROLLER_H