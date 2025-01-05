#include "World.h"
#include <iostream>

// Constructor: Initializes the World with levels, tileset, and background file
World::World(const std::vector<Level>& levels, const std::string& tileset, const std::string& backgroundFile)
    : levels(levels), tileset(tileset), backgroundFile(backgroundFile) {
    if (!backgroundTexture.loadFromFile(backgroundFile)) {
        std::cerr << "Error: Failed to load background texture from " << backgroundFile << std::endl;
    }
}

// Returns the list of levels in the world
const std::vector<Level>& World::getLevels() const {
    return levels;
}

// Returns the tileset file path for the world
const std::string& World::getTileset() const {
    return tileset;
}

// Returns the background sprite for the world
sf::Sprite& World::getBackground() {
    background.setTexture(World::getBackgroundTexture());
    return background;
}

// Returns the background texture for the world
sf::Texture& World::getBackgroundTexture() {
    return backgroundTexture;
}
