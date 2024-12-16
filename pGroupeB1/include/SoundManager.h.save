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
        float volume;

    public:
        SoundManager(float volume=50.0f);
        virtual ~SoundManager();

        bool loadMusic(const std::string& filename);
        void playMusic();
        void stopMusic();
        void changeMusic(const std::string& filename);
        int getVolume();
        void setVolume(int newVolume);

};

#endif // SOUNDMANAGER_H
