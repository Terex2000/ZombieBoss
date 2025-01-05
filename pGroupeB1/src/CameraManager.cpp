// CameraManager.cpp
#include "CameraManager.h"

CameraManager::CameraManager(float width, float height) {
    view.setSize(width, height);
    view.setCenter(width / 2, height / 2);
}

void CameraManager::update(const PlayerController& playerController, const MapController& mapController) {
    const sf::CircleShape& playerShape = playerController.getPlayerShape();
    sf::Vector2f center = playerShape.getPosition();

    float halfWidth = view.getSize().x / 2;
    float halfHeight = view.getSize().y / 2;

    float mapWidth = static_cast<float>(mapController.getMapWidth());
    float mapHeight = static_cast<float>(mapController.getMapHeight());

    // Clamp the view center to the map boundaries
    if (center.x < halfWidth) {
        center.x = halfWidth;
    } else if (center.x > mapWidth - halfWidth) {
        center.x = mapWidth - halfWidth;
    }

    if (center.y < halfHeight) {
        center.y = halfHeight;
    } else if (center.y > mapHeight - halfHeight) {
        center.y = mapHeight - halfHeight;
    }

    view.setCenter(center);
}

const sf::View& CameraManager::getView() const {
    return view;
}
