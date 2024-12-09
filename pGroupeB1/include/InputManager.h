#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "PlayerController.h"

class InputManager {
public:
    InputManager();
    ~InputManager();
    void handleInput(PlayerController& playerController);

private:
    const float moveSpeed = 0.1f;
};

#endif // INPUTMANAGER_H