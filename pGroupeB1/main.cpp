#include "StateManager.h"
#include "MainMenuState.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>

int main() {
    try {
        // Create the main window with a resolution of 800x600 and title "Game Menu"
        sf::RenderWindow window(sf::VideoMode(800, 600), "Game Menu");

        // Initialize the texture manager to handle game textures
        TextureManager textureManager;

        // Initialize the sound manager with a volume level of 50
        SoundManager soundManager(50);

        // Initialize the input manager to handle user inputs
        InputManager inputManager;

        // Initialize the state manager with the main window
        StateManager stateManager(window);

        // Set the initial state to the main menu state
        stateManager.setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, &stateManager));

        // Create a clock to manage the time between frames
        sf::Clock clock;

        // Main game loop
        while (window.isOpen()) {
            sf::Event event;
            // Process all events
            while (window.pollEvent(event)) {
                // Close the window if the close event is triggered
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                // Handle input for the current state
                stateManager.handleInput(event);
            }

            // Calculate the time elapsed since the last frame
            double deltaTime = clock.restart().asSeconds();

            // Update the current state with the elapsed time
            stateManager.update(deltaTime);

            // Draw the current state
            stateManager.draw();
        }
    } catch (const std::exception& e) {
        // Catch and display any standard exceptions
        std::cerr << "Exception: " << e.what() << std::endl;
    } catch (...) {
        // Catch and display any unknown exceptions
        std::cerr << "Unknown exception occurred!" << std::endl;
    }

    return 0;
}
