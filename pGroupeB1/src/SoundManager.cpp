#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager(float volume) : volume(volume)
{
    //ctor
}

SoundManager::~SoundManager()
{
    //dtor
}

bool SoundManager::loadMusic(const std::string& filename) {
    if (!backgroundSound.openFromFile(filename)) {
        std::cerr << "Failed to load music: " << filename << std::endl;
        return false;
    }
    backgroundSound.setVolume(volume);
    backgroundSound.setLoop(true);
    std::cout << "Music loaded successfully: " << filename << std::endl;
    return true;
}

void SoundManager::playMusic() {
    if (backgroundSound.getStatus() != sf::SoundSource::Playing) {
        backgroundSound.play();
        std::cout << "Playing music." << std::endl;
    } else {
        std::cerr << "Failed to play music: audio not initialized." << std::endl;
    }
}

void SoundManager::stopMusic()
{
    backgroundSound.stop();
}

void SoundManager::changeMusic(const std::string& filename) {
    stopMusic();
    if (loadMusic(filename)) {
        playMusic();
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
