#include "TextureManager.h"
#include <iostream>

TextureManager::TextureManager() {
    // Constructor
}

TextureManager::~TextureManager() {
    // Destructor
}

// Loads a texture from a file and stores it with the given name.
bool TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        std::cerr << "Error: Failed to load texture from file " << filename << std::endl;
        return false;
    }
    textures[name] = texture;
    std::cout << "Loaded texture: " << name << " from " << filename << std::endl;
    return true;
}

// Retrieves a texture by name.
sf::Texture& TextureManager::getTexture(const std::string& name) {
    return textures.at(name);
}