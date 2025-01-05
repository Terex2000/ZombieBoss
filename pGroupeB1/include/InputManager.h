#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "PlayerController.h"
#include <windows.h> // For checking full screen mode


// The InputManager class is responsible for handling player input.
class InputManager {
public:
    InputManager();
    ~InputManager();

    // Handles input for the player controller.
    void handleInput(PlayerController& playerController);

    bool isFullScreen() const;


private:
    float moveSpeed = 0.02f; // The speed at which the player moves.
    const float fullScreenSpeed = 0.06f; // Speed when in full screen.
    const float windowedSpeed = 0.02f; // Speed when not in full screen.
};

#endif // INPUTMANAGER_H