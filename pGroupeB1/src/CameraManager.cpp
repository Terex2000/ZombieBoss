// CameraManager.cpp
#include "CameraManager.h"

// Constructor to initialize the camera view with the given width and height
CameraManager::CameraManager(float width, float height) {
    // Set the size of the view
    view.setSize(width, height);
    // Center the view at the middle of the given dimensions
    view.setCenter(width / 2, height / 2);
}

// Update the camera view based on the player's position and the map boundaries
void CameraManager::update(const PlayerController& playerController, const MapController& mapController) {
    // Get the player's shape to determine its position
    const sf::CircleShape& playerShape = playerController.getPlayerShape();
    sf::Vector2f center = playerShape.getPosition();

    // Calculate half the width and height of the view for boundary clamping
    float halfWidth = view.getSize().x / 2;
    float halfHeight = view.getSize().y / 2;

    // Get the map dimensions
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

    // Set the clamped center position to the view
    view.setCenter(center);
}

// Return the current view
const sf::View& CameraManager::getView() const {
    return view;
}
