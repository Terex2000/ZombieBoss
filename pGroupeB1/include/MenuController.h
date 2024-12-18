#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "MainMenu.h"
#include "InputManager.h"

class MenuController {
public:
    MenuController(MainMenu& model, InputManager& inputManager);
    void handleInput();

private:
    MainMenu& model;
    InputManager& inputManager;
};

#endif // MENUCONTROLLER_H
