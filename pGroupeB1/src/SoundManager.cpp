#include "SoundManager.h"

SoundManager::SoundManager(int volume)
:volume(volume)
{
    //ctor
}

SoundManager::~SoundManager()
{
    //dtor
}

void SoundManager::loadMusic(const std::string& filename)
{
    if(!backgroundSound.openFromFile(filename))
    {

    }
    backgroundSound.setVolume(volume);
    backgroundSound.setLoop(true);
}

void SoundManager::loadSound(const std::string& name, const std::string& filename)
{
    sf::SoundBuffer* buffer= new sf::SoundBuffer;
    if(buffer->loadFromFile(filename))
    {
        sounds[name]=buffer;
    }
}

void SoundManager::playMusic()
{
    backgroundSound.setVolume(volume);
    backgroundSound.play();
}

void SoundManager::playSound(const std::string& name)
{
    auto it = sounds.find(name);
    if(it!=sounds.end())
    {
        sf::Sound sound;
        sound.setBuffer(*(it->second));
        playingSounds[name].push_back(std::move(sound));

        playingSounds[name].back().setVolume(volume);
        playingSounds[name].back().play();
    }
}

void SoundManager::stopMusic()
{
    backgroundSound.stop();
}

void SoundManager::stopAllSounds()
{
    for(auto& pair : playingSounds)
    {
        pair.second.clear();
    }
}

int SoundManager::getVolume()
{
    return volume;
}

void SoundManager::setVolume(int newVolume)
{
    volume=newVolume;
}
