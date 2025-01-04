#include "LoseState.h"

LoseState::LoseState(sf::RenderWindow& window) : window(window) {
    // Initialisation sp�cifique � l'�tat de d�faite
}

LoseState::~LoseState() = default;

void LoseState::handleInput(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        // Exemple : Red�marrer le jeu ou retourner au menu principal
    }
}

void LoseState::update(sf::RenderWindow& window, double deltaTime) {
    // Mettre � jour les �l�ments sp�cifiques � l'�tat de d�faite
}

void LoseState::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black); // Exemple : arri�re-plan noir pour l'�cran de d�faite
    // Ajouter des �l�ments graphiques (texte, images, etc.) ici
    window.display();
}
