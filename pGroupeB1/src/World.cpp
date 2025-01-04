#include "World.h"
#include <iostream>

World::World(const std::vector<Level>& levels, const std::string& tileset, const std::string& backgroundFile)
    : levels(levels), tileset(tileset), backgroundFile(backgroundFile) {
             if (!backgroundTexture.loadFromFile(backgroundFile)) {
        std::cerr << "Error: Failed to load background texture from " << backgroundFile << std::endl;
    }
}

const std::vector<Level>& World::getLevels() const {
    return levels;
}

const std::string& World::getTileset() const {
    return tileset;
}

sf::Sprite& World::getBackground() {
    background.setTexture(World::getBackgroundTexture());
    return background;
}

sf::Texture& World::getBackgroundTexture() {
    return backgroundTexture;
}