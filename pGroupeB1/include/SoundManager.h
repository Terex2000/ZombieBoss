#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>
#include <memory>

class SoundManager
{
    private:
        sf::Music backgroundSound;
        std::unordered_map<std::string, sf::SoundBuffer*> sounds;
        std::unordered_map<std::string, std::vector<sf::Sound>> playingSounds;

        int volume;

    public:
        SoundManager(int volume);
        virtual ~SoundManager();

        void loadMusic(const std::string& filename);
        void loadSound(const std::string& name, const std::string& filename);

        void playMusic();
        void playSound(const std::string& name);

        void stopMusic();
        void stopAllSounds();

        int getVolume();
        void setVolume(int newVolume);

        void update();
};

#endif // SOUNDMANAGER_H
