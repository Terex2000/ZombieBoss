#include "MainMenuState.h"
#include <iostream>

MainMenuState::MainMenuState(sf::RenderWindow& window, SoundManager& soundManager)
    : soundManager(soundManager), selectedOption(0), changeState(false), nextState("") {
    if (!font.loadFromFile("res/ZOMBIE.TTF")) {
        std::cerr << "Error loading font!" << std::endl;
    }

    // Titre
    title.setFont(font);
    title.setString("Zombie Bros");
    title.setCharacterSize(60);
    title.setFillColor(sf::Color::White);
    title.setPosition(200.f, 100.f);

    // Options
    newGameOption.setFont(font);
    newGameOption.setString("New Game");
    newGameOption.setCharacterSize(40);
    newGameOption.setFillColor(sf::Color::Red); // Option sélectionnée
    newGameOption.setPosition(250.f, 300.f);

    quitOption.setFont(font);
    quitOption.setString("Quit");
    quitOption.setCharacterSize(40);
    quitOption.setFillColor(sf::Color::White);
    quitOption.setPosition(250.f, 400.f);

    // Charger et jouer la musique du menu
    soundManager.loadMusic("res/mainMenuMusic.wav");
    soundManager.playMusic();
}

MainMenuState::~MainMenuState() {
    soundManager.stopMusic();
}

void MainMenuState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) {
            selectedOption = (selectedOption - 1 + 2) % 2;
        } else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S) {
            selectedOption = (selectedOption + 1) % 2;
        } else if (event.key.code == sf::Keyboard::Enter) {
            if (selectedOption == 0) {
                changeState = true;
                nextState = "InGameState"; // Indique qu'on passe à l'état de jeu
            } else if (selectedOption == 1) {
                window.close();
            }
        }
    }
}

void MainMenuState::update(sf::RenderWindow& window, double deltaTime) {
    // Mettre à jour les couleurs des options en fonction de la sélection
    newGameOption.setFillColor(selectedOption == 0 ? sf::Color::Red : sf::Color::White);
    quitOption.setFillColor(selectedOption == 1 ? sf::Color::Red : sf::Color::White);
}

void MainMenuState::draw(sf::RenderWindow& window) {
    window.clear();
    window.draw(title);
    window.draw(newGameOption);
    window.draw(quitOption);
    window.display();
}

bool MainMenuState::shouldChangeState() const {
    return changeState;
}

std::string MainMenuState::getNextState() const {
    return nextState;
}
