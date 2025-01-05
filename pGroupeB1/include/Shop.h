#ifndef SHOP_H
#define SHOP_H

#include <nlohmann/json.hpp>
#include <string>

class ShopView; // Forward declaration

class Shop {
public:
    Shop(const std::string& tempFilePath);

    bool buyLife(ShopView& shopView); // Acheter une vie
    bool upgradeDamage(ShopView& shopView); // Améliorer les dommages
    int getCoins(); // Retourne le nombre de pièces

private:
    std::string tempFilePath; // Path to the temporary file

    nlohmann::json loadGameState();
    void saveGameState(const nlohmann::json& gameState);
};

#endif // SHOP_H
