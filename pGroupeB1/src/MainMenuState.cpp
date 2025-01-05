#include "MainMenuState.h"
#include <iostream>

// Constructor: Initializes the MainMenuState with necessary managers and controllers
MainMenuState::MainMenuState(sf::RenderWindow& window, SoundManager& soundManager,
                             TextureManager& textureManager, InputManager& inputManager, StateManager* stateManager)
    : window(window), view(window, textureManager), textureManager(textureManager), inputManager(inputManager),
      stateManager(stateManager), controller(model, inputManager), soundManager(soundManager),
      currentMenu(MenuType::MainMenu), selectedSettingOption(0), launchGame(false), loadGame(false), isFullscreen(false) {
    soundManager.loadMusic("assets/sound/mainMenuSound.ogg");
    soundManager.playMusic();

    if (!settingsBackgroundTexture.loadFromFile("assets/img/settings.jpg")) {
        std::cerr << "Error: Failed to load settings background image!" << std::endl;
    }
    settingsBackgroundSprite.setTexture(settingsBackgroundTexture);
    launchGame = false;
    loadGame = false;
}

// Handles user input for the main menu state
void MainMenuState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::F11) {
            toggleFullscreen(); // Toggle between fullscreen and windowed mode
        } else if (event.key.code == sf::Keyboard::Escape) {
            window.close(); // Close the window if Escape is pressed
        }
    }
    if (currentMenu == MenuType::MainMenu) {
        controller.handleInput();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
            if (model.getSelectedOption() == MainMenu::Settings) {
                currentMenu = MenuType::Settings;
                selectedSettingOption = 0;
            } else if (model.getSelectedOption() == MainMenu::Quit) {
                window.close();
            } else if (model.getSelectedOption() == MainMenu::Play) {
                launchGame = true;
            } else if (model.getSelectedOption() == MainMenu::LoadGame) {
                loadGame = true;
            } else if (event.key.code == sf::Keyboard::F11) {
                toggleFullscreen();
            } else if (event.key.code == sf::Keyboard::Escape) {
                window.close(); // Close the window
            }
        }
    } else if (currentMenu == MenuType::Settings) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                selectedSettingOption = (selectedSettingOption - 1 + 4) % 4;
            } else if (event.key.code == sf::Keyboard::Down) {
                selectedSettingOption = (selectedSettingOption + 1) % 4;
            } else if (event.key.code == sf::Keyboard::Enter) {
                switch (selectedSettingOption) {
                    case 0: // Change difficulty
                        settings.setDifficulty(static_cast<Settings::Difficulty>((settings.getDifficulty() + 1) % 3));
                        break;
                    case 1: // Adjust volume
                        settings.setVolume((settings.getVolume() + 10) % 110);
                        soundManager.setVolume(settings.getVolume());
                        break;
                    case 2: // Toggle fullscreen
                        toggleFullscreen();
                        break;
                    case 3: // Return to main menu
                        currentMenu = MenuType::MainMenu;
                        break;
                }
            }
        }
    }
}

// Toggles between fullscreen and windowed mode
void MainMenuState::toggleFullscreen() {
    isFullscreen = !isFullscreen;

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    window.close();

    if (isFullscreen) {
        window.create(sf::VideoMode(desktopMode.width, desktopMode.height), "Game Menu", sf::Style::Fullscreen);
    } else {
        window.create(sf::VideoMode(800, 600), "Game Menu");
    }

    // Adjust backgrounds after changing mode
    textureManager.adjustSpriteToWindow(settingsBackgroundSprite, window);
}

// Adjusts the window size to fit the screen
void MainMenuState::adjustWindowToScreen() {
    sf::Vector2u windowSize = this->window.getSize();
    sf::Vector2u textureSize = settingsBackgroundTexture.getSize();
    settingsBackgroundSprite.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );
}

// Updates the main menu state
void MainMenuState::update(sf::RenderWindow& window, double deltaTime) {
    if (launchGame) {
        // Change state to InGameState
        stateManager->setState(std::make_unique<InGameState>(window, soundManager, textureManager, inputManager, stateManager));
        launchGame = false;
    } else if (loadGame) {
        // Load game state from save.json
        stateManager->setState(std::make_unique<InGameState>(window, soundManager, textureManager, inputManager, stateManager, "save.json"));
        loadGame = false;
    }
}

// Draws the main menu state
void MainMenuState::draw(sf::RenderWindow& window) {
    // Save the current view (affected by the camera)
    sf::View originalView = window.getView();

    // Use the default view to draw the UI (menus)
    window.setView(window.getDefaultView());

    // Display the main menu
    if (currentMenu == MenuType::MainMenu) {
        view.render(model); // Continue using your usual code to display the menu
    } else if (currentMenu == MenuType::Settings) {
        window.clear();
        window.draw(settingsBackgroundSprite); // Display the settings background

        sf::Font font;
        if (!font.loadFromFile("assets/police/ZOMBIE.ttf")) {
            std::cerr << "Error loading font!" << std::endl;
        }

        sf::Text title("Settings", font, 60);
        title.setPosition(300.f, 50.f);
        title.setFillColor(sf::Color::White);
        window.draw(title);

        std::vector<std::string> options = {
            "Difficulty: " + std::vector<std::string>{"Easy", "Medium", "Hard"}[settings.getDifficulty()],
            "Volume: " + std::to_string(settings.getVolume()),
            "Fullscreen: " + std::string(settings.isFullscreen() ? "ON" : "OFF"),
            "Back"
        };

        for (size_t i = 0; i < options.size(); ++i) {
            sf::Text text(options[i], font, 40);
            text.setPosition(300.f, 150.f + i * 100.f);
            text.setFillColor(i == selectedSettingOption ? sf::Color::Red : sf::Color::White);
            window.draw(text);
        }

        window.display();
    }

    // Restore the initial view (with the active camera)
    window.setView(originalView);
}
