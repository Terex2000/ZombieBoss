#ifndef SHOPSTATE_H
#define SHOPSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "StateManager.h"
#include "Shop.h"
#include "ShopView.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "Player.h"
#include "GameController.h"
#include "StateManager.h"
#include "HUDController.h"


class ShopState : public State{
public:
    ShopState(sf::RenderWindow& window, StateManager* stateManager, SoundManager& soundManager,
              TextureManager& textureManager, InputManager& inputManager, Player& player, HUDController& hudController);

    void handleInput(sf::RenderWindow& window, sf::Event event) override; // Gère les entrées utilisateur
    void update(sf::RenderWindow& window, double deltaTime) override;    // Met à jour l'état
    void draw(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    StateManager* stateManager;
    SoundManager& soundManager;
    TextureManager& textureManager;
    InputManager& inputManager;
    GameController gameController;
    HUDController& hudController;
    Shop shop;
    ShopView shopView;
    Player& player;
    sf::Text errorMessage; // Message d'erreur affiché à l'écran
    bool exitShop;
};

#endif // SHOPSTATE_H
