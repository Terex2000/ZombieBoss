#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Level.h"

class World {
public:
    World(const std::vector<Level>& levels, const std::string& tileset, const std::string& backgroundFile);

    const std::vector<Level>& getLevels() const;
    const std::string& getTileset() const;
    sf::Sprite& getBackground();
    sf::Texture& getBackgroundTexture();

private:
    std::vector<Level> levels;
    std::string tileset;
    std::string backgroundFile;
    sf::Texture backgroundTexture;
    sf::Sprite background;
};

#endif // WORLD_H