#include "WinState.h"

WinState::WinState(sf::RenderWindow& window) : window(window) {
    // Initialisation spécifique à l'état de victoire
}

WinState::~WinState() = default;

void WinState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        // Exemple : Retour au menu principal ou chargement d'un nouveau niveau
    }
}

void WinState::update(sf::RenderWindow& window, double deltaTime) {
    // Mettre à jour les éléments spécifiques à l'état de victoire
}

void WinState::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::White); // Exemple : écran blanc pour l'état de victoire
    // Ajouter des éléments graphiques (texte, images, etc.) ici
    window.display();
}
