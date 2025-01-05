#include "LoseState.h"
#include "MainMenuState.h"
#include <iostream>

// Constructor: Initializes the LoseState with necessary managers and controllers
LoseState::LoseState(sf::RenderWindow& window, SoundManager& soundManager,
                           TextureManager& textureManager, InputManager& inputManager,  StateManager* stateManager)
    : window(window), stateManager(stateManager), soundManager(soundManager),
      textureManager(textureManager), inputManager(inputManager), selectedOption(0) {
    // Load the font
    if (!font.loadFromFile("assets/police/ZOMBIE.ttf")) {
        std::cerr << "Error loading font for LoseState!" << std::endl;
    }
    options = {"Quit to Main Menu"};
}

// Destructor: Cleans up resources used by the LoseState
LoseState::~LoseState(){
    std::cout << "LoseState destroyed" << std::endl;
}

// Handles user input for the lose state
void LoseState::handleInput(sf::RenderWindow& window, sf::Event event) {
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

// Updates the lose state (no specific update logic needed here)
void LoseState::update(sf::RenderWindow& window, double deltaTime) {
}

// Draws the lose state screen
void LoseState::draw(sf::RenderWindow& window) {
    try {
        // Save the current view
        sf::View originalView = window.getView();
        // Switch to a default view, unaffected by the player's camera
        window.setView(window.getDefaultView());
        // Rectangle for the menu background
        sf::RectangleShape rectangle(sf::Vector2f(400.f, 50.f));
        rectangle.setFillColor(sf::Color(128, 128, 128, 1));
        rectangle.setPosition(200.f, 175.f);
        window.draw(rectangle);

        // Load the font
        sf::Font font;
        if (!font.loadFromFile("assets/police/ZOMBIE.ttf")) {
            std::cerr << "Error loading font for LoseState!" << std::endl;
        } else {
            // Set up the lose text
            loseText.setFont(font);
            loseText.setString("Game Over!");
            loseText.setCharacterSize(50);
            loseText.setFillColor(sf::Color::Red);
            loseText.setPosition(285.f, 250.f);
            window.draw(loseText);
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
        std::cerr << "Exception in LoseState::draw: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception in LoseState::draw" << std::endl;
    }
}

// Navigates up through the menu options
void LoseState::navigateUp() {
    if (selectedOption > 0) {
        selectedOption--;
    } else {
        selectedOption = options.size() - 1; // Wrap around to the last option
    }
}

// Navigates down through the menu options
void LoseState::navigateDown() {
    if (selectedOption < options.size() - 1) {
        selectedOption++;
    } else {
        selectedOption = 0; // Wrap around to the first option
    }
}

// Executes the selected menu option
void LoseState::executeOption() {
    const std::string& option = options[selectedOption];

    if (option == "Quit to Main Menu") {
        stateManager->setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, stateManager));
    }
}
