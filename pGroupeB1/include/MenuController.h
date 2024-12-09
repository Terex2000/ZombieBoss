#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "MainMenu.h"
#include "MainMenuView.h"
#include <SFML/Window.hpp>

class MenuController {
public:
    MenuController(MainMenu& model, MainMenuView& view);
    virtual ~MenuController();

    void handleInput(const sf::Event& event);
    void update();

private:
    MainMenu& model;
    MainMenuView& view;
};

#endif // MENUCONTROLLER_H
