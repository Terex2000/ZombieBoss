#ifndef SHOPVIEW_H
#define SHOPVIEW_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Shop.h"

class ShopView {
public:
    ShopView();
    ~ShopView();

    void draw(sf::RenderWindow& window, Shop& shop); // Affiche l'interface du shop
    void handleInput(sf::Event event, Shop& shop, bool& exitShop); // G�re les interactions utilisateur
    void navigateUp();    // D�place l'option s�lectionn�e vers le haut
    void navigateDown();  // D�place l'option s�lectionn�e vers le bas
    void update(int coins);
    std::string getSelectedOption() const; // Retourne l'option s�lectionn�e

private:
    sf::Font font; // Police utilis�e pour le texte
    sf::Text title; // Titre du shop
    sf::Text errorMessage; // Message d'erreur affich� � l'�cran
    sf::RectangleShape background; // Fond pour le shop
    int selectedOption; // Option actuellement s�lectionn�e (0: vie, 1: dommages, 2: quitter)
};

#endif // SHOPVIEW_H
