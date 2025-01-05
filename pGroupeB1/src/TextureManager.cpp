#include "TextureManager.h"
#include <iostream>

// Constructor for TextureManager
TextureManager::TextureManager() {
    // Constructor body (currently empty)
}

// Destructor for TextureManager
TextureManager::~TextureManager() {
    // Destructor body (currently empty)
}

// Loads a texture from a file and stores it with the given name.
bool TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    sf::Texture texture;
    // Attempt to load the texture from the specified file
    if (!texture.loadFromFile(filename)) {
        std::cerr << "Error: Failed to load texture from file " << filename << std::endl;
        return false;
    }
    // Store the loaded texture in the map with the given name
    textures[name] = texture;
    std::cout << "Loaded texture: " << name << " from " << filename << std::endl;
    return true;
}

// Adjusts the sprite's scale to fit the window size
void TextureManager::adjustSpriteToWindow(sf::Sprite& sprite, sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = sprite.getTexture()->getSize();

    // Scale the sprite to match the window size
    sprite.setScale(
        static_cast<float>(windowSize.x) / textureSize.x,
        static_cast<float>(windowSize.y) / textureSize.y
    );
}

// Retrieves a texture by name.
sf::Texture& TextureManager::getTexture(const std::string& name) {
    auto it = textures.find(name);
    if (it != textures.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Error: Texture '" + name + "' not found in TextureManager.");
    }
}
