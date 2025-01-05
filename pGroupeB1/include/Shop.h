#ifndef SHOP_H
#define SHOP_H

#include "Player.h"
#include <nlohmann/json.hpp>

class Shop {
public:
    explicit Shop(Player& player);

    bool buyLife(const std::string& jsonFilePath); // Acheter une vie
    bool upgradeDamage(const std::string& jsonFilePath); // Améliorer les dommages

private:
    Player& player; // Référence au joueur pour modifier ses statistiques

    void updateJson(const std::string& jsonFilePath); // Met à jour le fichier JSON
};

#endif // SHOP_H
