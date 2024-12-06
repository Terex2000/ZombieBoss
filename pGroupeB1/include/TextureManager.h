#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
public:
    TextureManager();
    ~TextureManager();

    bool loadTexture(const std::string& name, const std::string& filename);
    sf::Texture& getTexture(const std::string& name);

private:
    std::map<std::string, sf::Texture> textures;
};

#endif // TEXTUREMANAGER_H