#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>

// Constructor for InputManager
InputManager::InputManager() {}

// Destructor for InputManager
InputManager::~InputManager() {}

// Handles input for the player controller.
void InputManager::handleInput(PlayerController& playerController) {
    // Adjust move speed based on whether the game is in full screen or windowed mode
    if (isFullScreen()) {
        moveSpeed = fullScreenSpeed;
    } else {
        moveSpeed = windowedSpeed;
    }

    // Check if the left arrow key is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        playerController.move(-moveSpeed, 0); // Move the player to the left
        playerController.getPlayer().setDirection(-1.0f); // Update the player's direction to left
    }
    // Check if the right arrow key is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        playerController.move(moveSpeed, 0); // Move the player to the right
        playerController.getPlayer().setDirection(1.0f); // Update the player's direction to right
    }
    // Check if the space bar is pressed for jumping
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        playerController.jump(); // Make the player jump
    }
    // Check if the 'Z' key is pressed for shooting
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        playerController.shoot(); // Make the player shoot
    }
}

// Checks if the game is in full screen mode
bool InputManager::isFullScreen() const {
    HWND hwnd = GetForegroundWindow();
    HMONITOR hMonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    MONITORINFO mi = { sizeof(mi) };
    GetMonitorInfo(hMonitor, &mi);

    RECT windowRect;
    GetWindowRect(hwnd, &windowRect);

    // Compare the window's position and size to the monitor's dimensions
    return (windowRect.left == mi.rcMonitor.left &&
            windowRect.top == mi.rcMonitor.top &&
            windowRect.right == mi.rcMonitor.right &&
            windowRect.bottom == mi.rcMonitor.bottom);
}
