#include "WinState.h"

WinState::WinState(sf::RenderWindow& window) : window(window) {
    // Initialisation sp�cifique � l'�tat de victoire
}

WinState::~WinState() = default;

void WinState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        // Exemple : Retour au menu principal ou chargement d'un nouveau niveau
    }
}

void WinState::update(sf::RenderWindow& window, double deltaTime) {
    // Mettre � jour les �l�ments sp�cifiques � l'�tat de victoire
}

void WinState::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::White); // Exemple : �cran blanc pour l'�tat de victoire
    // Ajouter des �l�ments graphiques (texte, images, etc.) ici
    window.display();
}
