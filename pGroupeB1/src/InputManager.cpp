#include "InputManager.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

// Constructor for InputManager
InputManager::InputManager() {
    // Get the screen resolution
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    screenSize = sf::Vector2u(desktop.width, desktop.height);

    // Initialize window size to screen size
    windowSize = screenSize;

    // Calculate the initial move speed
    calculateMoveSpeed();
}

// Destructor for InputManager
InputManager::~InputManager() {}

// Handles input for the player controller.
void InputManager::handleInput(PlayerController& playerController) {
    // Adjust move speed based on whether the game is in full screen or windowed mode
    calculateMoveSpeed();

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

// Sets the current window size
void InputManager::setWindowSize(const sf::Vector2u& size) {
    windowSize = size;
}

// Calculates the move speed based on the screen resolution and size.
void InputManager::calculateMoveSpeed() {
    float resolutionFactor = static_cast<float>(windowSize.x) / 1920.0f; // Assuming 1920x1080 as base resolution
    moveSpeed = baseSpeed * resolutionFactor;

    if (isFullScreen()) {
        moveSpeed *= fullScreenMultiplier;
    } else {
        moveSpeed *= windowedMultiplier;
    }
}