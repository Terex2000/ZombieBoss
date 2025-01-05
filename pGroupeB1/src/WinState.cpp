#include "WinState.h"
#include "MainMenuState.h"
#include <iostream>

// Constructor: Initializes the WinState with necessary managers and controllers
WinState::WinState(sf::RenderWindow& window, SoundManager& soundManager,
                           TextureManager& textureManager, InputManager& inputManager,  StateManager* stateManager)
    : window(window), stateManager(stateManager), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), selectedOption(0) {
    // Load the font
    if (!font.loadFromFile("assets/police/ZOMBIE.ttf")) {
        std::cerr << "Error loading font for WinState!" << std::endl;
    }
    options = {"Quit to Main Menu"};
}

// Destructor: Cleans up resources used by the WinState
WinState::~WinState(){
    std::cout << "WinState destroyed" << std::endl;
}

// Handles user input for the win state
void WinState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            navigateUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            navigateDown();
        } else if (event.key.code == sf::Keyboard::Enter) {
            executeOption();
        }
    }
}

// Updates the win state (no specific update logic needed here)
void WinState::update(sf::RenderWindow& window, double deltaTime) {
}

// Draws the win state screen
void WinState::draw(sf::RenderWindow& window) {
    try {
        // Rectangle for the menu background
        sf::RectangleShape rectangle(sf::Vector2f(400.f, 50.f));
        rectangle.setFillColor(sf::Color(128, 128, 128, 1));
        rectangle.setPosition(200.f, 175.f);
        window.draw(rectangle);

        // Load the font
        sf::Font font;
        if (!font.loadFromFile("assets/police/ZOMBIE.ttf")) {
            std::cerr << "Error loading font for WinState!" << std::endl;
        } else {
            // Set up the win text
            winText.setFont(font);
            winText.setString("You Win!");
            winText.setCharacterSize(50);
            winText.setFillColor(sf::Color::Red);
            winText.setPosition(285.f, 250.f);
            window.draw(winText);
        }
        // Display the options
        for (size_t i = 0; i < options.size(); ++i) {
            sf::Text text(options[i], font, 30);
            text.setPosition(250.f, 180.f + i * 50.f); // Adjust positions
            text.setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
            window.draw(text);
        }
        window.display(); // Refresh the display
    } catch (const std::exception& e) {
        std::cerr << "Exception in WinState::draw: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception in WinState::draw" << std::endl;
    }
}

// Navigates up through the menu options
void WinState::navigateUp() {
    if (selectedOption > 0) {
        selectedOption--;
    } else {
        selectedOption = options.size() - 1; // Wrap around to the last option
    }
}

// Navigates down through the menu options
void WinState::navigateDown() {
    if (selectedOption < options.size() - 1) {
        selectedOption++;
    } else {
        selectedOption = 0; // Wrap around to the first option
    }
}

// Executes the selected menu option
void WinState::executeOption() {
    const std::string& option = options[selectedOption];

    if (option == "Quit to Main Menu") {
        stateManager->setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, stateManager));
    }
}
