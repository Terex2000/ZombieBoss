#ifndef SHOPVIEW_H
#define SHOPVIEW_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class ShopView {
public:
    ShopView();
    ~ShopView();

    void draw(sf::RenderWindow& window, const Player& player); // Affiche l'interface du shop
    void handleInput(sf::Event event, int& selectedOption, bool& exitShop); // Gère les interactions utilisateur
    void navigateUp();    // Déplace l'option sélectionnée vers le haut
    void navigateDown();  // Déplace l'option sélectionnée vers le bas
    std::string getSelectedOption() const; // Retourne l'option sélectionnée
    void setStatusMessage(const std::string& message); // Affiche un message d'état (ex. achat réussi ou erreur)

private:
    sf::Font font; // Police utilisée pour le texte
    sf::Text title; // Titre du shop
    sf::Text statusMessage; // Message d'état affiché à l'écran
    sf::RectangleShape background; // Fond pour le shop
    int selectedOption; // Option actuellement sélectionnée (0: vie, 1: dommages, 2: quitter)
};

#endif // SHOPVIEW_H
