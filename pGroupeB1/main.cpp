#include "StateManager.h"
#include "MainMenuState.h"
#include "SoundManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Zombie Bros");
    SoundManager soundManager(50);
    StateManager stateManager(window);

    stateManager.setState(std::make_unique<MainMenuState>(window, soundManager));

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            stateManager.handleInput(event);
        }

        double deltaTime = clock.restart().asSeconds();
        stateManager.update(deltaTime);

        stateManager.draw();
    }

    return 0;
}
