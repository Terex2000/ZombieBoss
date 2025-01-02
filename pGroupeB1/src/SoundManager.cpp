#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager(float volume) : volume(volume) {
    std::cout << "SoundManager initialized with volume: " << volume << std::endl;
}

SoundManager::~SoundManager() {
    if (backgroundSound.getStatus() == sf::SoundSource::Playing) {
        backgroundSound.stop(); // Arr�ter la musique si elle est encore en cours
    }
    std::cout << "SoundManager destroyed, music stopped." << std::endl;
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
        std::cout << "Music is already playing." << std::endl;
    }
}

void SoundManager::stopMusic() {
    if (backgroundSound.getStatus() == sf::SoundSource::Playing) {
        backgroundSound.stop();
        std::cout << "Music stopped." << std::endl;
    }
}

void SoundManager::changeMusic(const std::string& filename) {
    stopMusic(); // Arr�ter la musique actuelle proprement
    if (loadMusic(filename)) {
        playMusic();
    }
}

int SoundManager::getVolume() {
    return static_cast<int>(volume);
}

void SoundManager::setVolume(int newVolume) {
    volume = static_cast<float>(newVolume);
    backgroundSound.setVolume(volume); // Appliquer imm�diatement le nouveau volume
    std::cout << "Volume set to: " << volume << std::endl;
}
