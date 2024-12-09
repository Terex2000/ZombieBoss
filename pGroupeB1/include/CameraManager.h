// CameraManager.h
#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <SFML/Graphics.hpp>
#include "PlayerController.h"
#include "MapController.h"

class CameraManager {
public:
    CameraManager(float width, float height);
    void update(const PlayerController& playerController, const MapController& mapController);
    const sf::View& getView() const;

private:
    sf::View view;
};

#endif // CAMERAMANAGER_H
