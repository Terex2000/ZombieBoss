#include "MainMenuState.h"
#include <iostream>

MainMenuState::MainMenuState(sf::RenderWindow& window, SoundManager& soundManager,
                             TextureManager& textureManager, InputManager& inputManager)
    : window(window), view(window, textureManager), textureManager(textureManager), controller(model, inputManager), soundManager(soundManager),
      currentMenu(MenuType::MainMenu), selectedSettingOption(0), launchGame(false), isFullscreen(false) {
    soundManager.loadMusic("assets/sound/mainMenuSound.wav");
    soundManager.playMusic();

     if (!settingsBackgroundTexture.loadFromFile("assets/img/settings.jpg")) {
        std::cerr << "Error: Failed to load settings background image!" << std::endl;
    }
    settingsBackgroundSprite.setTexture(settingsBackgroundTexture);
}

void MainMenuState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::F11) {
            toggleFullscreen(); // Basculer entre plein �cran et fen�tr�
        } else if (event.key.code == sf::Keyboard::Escape) {
            window.close(); // Fermer la fen�tre si �chap est press�e
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
            }else if (event.key.code == sf::Keyboard::F11) {
                toggleFullscreen();
            } else if (event.key.code == sf::Keyboard::Escape) {
                window.close(); // Fermer la fen�tre
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
                    case 0: // Changer la difficult�
                        settings.setDifficulty(static_cast<Settings::Difficulty>((settings.getDifficulty() + 1) % 3));
                        break;
                    case 1: // Modifier le volume
                        settings.setVolume((settings.getVolume() + 10) % 110);
                        soundManager.setVolume(settings.getVolume());
                        break;
                    case 2: // Toggle fullscreen
                        toggleFullscreen();
                        break;
                    case 3: // Retour au menu principal
                        currentMenu = MenuType::MainMenu;
                        break;
                }
            }
        }
    }
}

void MainMenuState::toggleFullscreen() {
    isFullscreen = !isFullscreen;

    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    window.close();

    if (isFullscreen) {
        window.create(sf::VideoMode(desktopMode.width, desktopMode.height), "Game Menu", sf::Style::Fullscreen);
    } else {
        window.create(sf::VideoMode(800, 600), "Game Menu");
    }

    // Ajuster les fonds apr�s le changement de mode
    textureManager.adjustSpriteToWindow(settingsBackgroundSprite, window);
}


void MainMenuState::adjustWindowToScreen() {
    sf::Vector2u windowSize = this->window.getSize();
    sf::Vector2u textureSize = settingsBackgroundTexture.getSize();
    settingsBackgroundSprite.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );
}


void MainMenuState::update(sf::RenderWindow& window, double deltaTime) {
    if (launchGame) {
        soundManager.changeMusic("assets/sound/gameSound.wav");
        GameController gameController(textureManager);
        gameController.run(window);
        launchGame = false;
    }
}

void MainMenuState::draw(sf::RenderWindow& window) {
    if (currentMenu == MenuType::MainMenu) {
        view.render(model);
    } else if (currentMenu == MenuType::Settings) {
        window.clear();

        window.draw(settingsBackgroundSprite);

        sf::Font font;
        if (!font.loadFromFile("assets/police/ZOMBIE.ttf")) {
            std::cerr << "Error loading police!" << std::endl;
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
}
