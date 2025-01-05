#include "ShopView.h"
#include <iostream>

// Constructeur
ShopView::ShopView() : selectedOption(0) {
    // Chargement de la police
    if (!font.loadFromFile("assets/police/Arial.ttf")) {
        std::cerr << "Erreur: Impossible de charger la police pour le ShopView." << std::endl;
    }

    // Initialisation du fond
    background.setSize(sf::Vector2f(400.f, 300.f));
    background.setFillColor(sf::Color(128, 128, 128, 200));
    background.setPosition(200.f, 150.f);

    // Initialisation du titre
    title.setFont(font);
    title.setString("Shop");
    title.setCharacterSize(30);
    title.setFillColor(sf::Color::White);
    title.setPosition(280.f, 160.f);

    // Initialisation du message d'erreur
    errorMessage.setFont(font);
    errorMessage.setCharacterSize(20);
    errorMessage.setFillColor(sf::Color::Red);
    errorMessage.setPosition(220.f, 400.f);
}

// Destructeur
ShopView::~ShopView() {}

// Dessine le shop � l'�cran
void ShopView::draw(sf::RenderWindow& window, Shop& shop) {
    // Dessiner le fond
    window.draw(background);

    // Dessiner le titre
    window.draw(title);

    // Afficher le solde du joueur
    sf::Text coinsText("Coins: "  + std::to_string(shop.getCoins()), font, 20);
    coinsText.setPosition(220.f, 200.f);
    coinsText.setFillColor(sf::Color::White);
    window.draw(coinsText);

    // Afficher les options
    sf::Text lifeButton("Acheter une vie (50 coins)", font, 20);
    sf::Text damageButton("Ameliorer les dommages (50 coins)", font, 20);
    sf::Text exitButton("Retour", font, 20);

    // Options de menu
    sf::Text options[] = { lifeButton, damageButton, exitButton };
    float yPosition = 250.f;

    for (int i = 0; i < 3; ++i) {
        options[i].setPosition(220.f, yPosition);
        options[i].setFillColor(i == selectedOption ? sf::Color::Red : sf::Color::White);
        window.draw(options[i]);
        yPosition += 40.f;
    }

    // Dessiner le message d'erreur si pr�sent
    if (!errorMessage.getString().isEmpty()) {
        window.draw(errorMessage);
    }
}

void ShopView::update(int coins) {
    // Mettre � jour l'affichage des coins
    errorMessage.setString(""); // Efface tout ancien message d'erreur

    // Met � jour l'affichage des coins
    sf::Text coinsText("Coins: " + std::to_string(coins), font, 20);
    coinsText.setPosition(220.f, 200.f);
}

void ShopView::navigateUp() {
    selectedOption = (selectedOption - 1 + 3) % 3; // 3 options au total
}

void ShopView::navigateDown() {
    selectedOption = (selectedOption + 1) % 3;
}

std::string ShopView::getSelectedOption() const {
    switch (selectedOption) {
        case 0: return "Buy Life";
        case 1: return "Upgrade Damage";
        case 2: return "Exit";
        default: return "";
    }
}


// G�re les entr�es utilisateur pour le shop
void ShopView::handleInput(sf::Event event, Shop& shop, bool& exitShop) {

}
