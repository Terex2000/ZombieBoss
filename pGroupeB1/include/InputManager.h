#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "PlayerController.h"

// The InputManager class is responsible for handling player input.
class InputManager {
public:
    InputManager();
    ~InputManager();

    // Handles input for the player controller.
    void handleInput(PlayerController& playerController);

private:
    const float moveSpeed = 0.1f; // The speed at which the player moves.
};

#endif // INPUTMANAGER_H