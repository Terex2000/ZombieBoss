#include "StateManager.h"
#include "MainMenuState.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>

int main() {
     try {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Game Menu");
        TextureManager textureManager;
        SoundManager soundManager(50);
        InputManager inputManager;

        StateManager stateManager(window);
        stateManager.setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, &stateManager));

        sf::Clock clock;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                stateManager.handleInput(event);
            }

            double deltaTime = clock.restart().asSeconds();
            stateManager.update(deltaTime);
            stateManager.draw();
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception occurred!" << std::endl;
    }

    return 0;
}
