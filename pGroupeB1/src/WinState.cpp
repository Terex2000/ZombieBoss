#include "WinState.h"
#include "MainMenuState.h"
#include <iostream>

WinState::WinState(sf::RenderWindow& window, SoundManager& soundManager,
                           TextureManager& textureManager, InputManager& inputManager,  StateManager* stateManager, GameController& gameController)
    : window(window), stateManager(stateManager), soundManager(soundManager), gameController(gameController),
      textureManager(textureManager), inputManager(inputManager), selectedOption(0) {
    // Load the font
    if (!font.loadFromFile("assets/police/ZOMBIE.ttf")) {
        std::cerr << "Error loading font for WinState!" << std::endl;
    }
    options = {"Quit to Main Menu"};
}

WinState::~WinState(){
    std::cout << "WinState destroyed" << std::endl;
}

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

void WinState::update(sf::RenderWindow& window, double deltaTime) {
}

void WinState::draw(sf::RenderWindow& window) {
    try {
        // Rectangle pour le fond du menu
        sf::RectangleShape rectangle(sf::Vector2f(400.f, 50.f));
        rectangle.setFillColor(sf::Color(128, 128, 128, 1));
        rectangle.setPosition(200.f, 175.f);
        window.draw(rectangle);

        // Chargement de la police
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
        // Affichage des options
        for (size_t i = 0; i < options.size(); ++i) {
            sf::Text text(options[i], font, 30);
            text.setPosition(250.f, 180.f + i * 50.f); // Ajustez les positions
            text.setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
            window.draw(text);
        }
        window.display(); // Rafra�chir l'affichage
    } catch (const std::exception& e) {
        std::cerr << "Exception in WinState::draw: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception in WinState::draw" << std::endl;
    }
}


void WinState::navigateUp() {
    if (selectedOption > 0) {
        selectedOption--;
    } else {
        selectedOption = options.size() - 1; // Retourner � la derni�re option
    }
}

void WinState::navigateDown() {
    if (selectedOption < options.size() - 1) {
        selectedOption++;
    } else {
        selectedOption = 0; // Retourner � la premi�re option
    }
}

void WinState::executeOption() {
    const std::string& option = options[selectedOption];

    if (option == "Quit to Main Menu") {
        stateManager->setState(std::make_unique<MainMenuState>(window, soundManager, textureManager, inputManager, stateManager, gameController));
    }
}
