#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "PlayerController.h"
#include <windows.h> // For checking full screen mode
#include <SFML/Graphics.hpp> // For getting screen resolution

// The InputManager class is responsible for handling player input.
class InputManager {
public:
    InputManager();
    ~InputManager();

    // Handles input for the player controller.
    void handleInput(PlayerController& playerController);

    bool isFullScreen() const;

    // Sets the current window size
    void setWindowSize(const sf::Vector2u& size);

private:
    float moveSpeed = 0.05f; // The speed at which the player moves.
    const float baseSpeed = 0.05f; // Base speed for calculations.
    const float fullScreenMultiplier = 1.5f; // Speed multiplier when in full screen.
    const float windowedMultiplier = 2.0f; // Speed multiplier when in windowed mode.

    // Calculates the move speed based on the screen resolution and size.
    void calculateMoveSpeed();

    // Screen resolution and size
    sf::Vector2u screenSize;
    sf::Vector2u windowSize;
};

#endif // INPUTMANAGER_H