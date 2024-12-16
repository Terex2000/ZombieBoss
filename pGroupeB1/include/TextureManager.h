#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

// The TextureManager class is responsible for loading and managing textures.
class TextureManager {
public:
    TextureManager();
    ~TextureManager();

    // Loads a texture from a file and stores it with the given name.
    bool loadTexture(const std::string& name, const std::string& filename);

    // Retrieves a texture by name.
    sf::Texture& getTexture(const std::string& name);

private:
    std::map<std::string, sf::Texture> textures; // A map of texture names to textures.
};

#endif // TEXTUREMANAGER_H