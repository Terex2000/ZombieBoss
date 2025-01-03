#include "LoseState.h"

LoseState::LoseState(sf::RenderWindow& window) : window(window) {
    // Initialisation spécifique à l'état de défaite
}

LoseState::~LoseState() = default;

void LoseState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        // Exemple : Redémarrer le jeu ou retourner au menu principal
    }
}

void LoseState::update(sf::RenderWindow& window, double deltaTime) {
    // Mettre à jour les éléments spécifiques à l'état de défaite
}

void LoseState::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black); // Exemple : arrière-plan noir pour l'écran de défaite
    // Ajouter des éléments graphiques (texte, images, etc.) ici
    window.display();
}
