#ifndef SHOPSTATE_H
#define SHOPSTATE_H

#include "State.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "StateManager.h"
#include "ShopView.h"
#include "Shop.h"


class ShopState : public State {
public:
    ShopState(sf::RenderWindow& window, StateManager* stateManager, SoundManager& soundManager,
              TextureManager& textureManager, InputManager& inputManager, Player& player);

    void handleInput(sf::RenderWindow& window, sf::Event event) override;
    void update(sf::RenderWindow& window, double deltaTime) override;
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    StateManager* stateManager;
    SoundManager& soundManager;
    TextureManager& textureManager;
    InputManager& inputManager;

    Player& player;
    ShopView shopView;
    Shop shop;
    bool exitShop;
};

#endif // SHOPSTATE_H
