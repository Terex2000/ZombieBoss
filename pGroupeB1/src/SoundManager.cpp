#include "SoundManager.h"
#include <iostream>

// Constructor for SoundManager, initializes the volume and prints a message
SoundManager::SoundManager(float volume) : volume(volume) {
    std::cout << "SoundManager initialized with volume: " << volume << std::endl;
}

// Destructor for SoundManager, stops the music if it is still playing and prints a message
SoundManager::~SoundManager() {
    if (backgroundSound.getStatus() == sf::SoundSource::Playing) {
        backgroundSound.stop(); // Stop the music if it is still playing
    }
    std::cout << "SoundManager destroyed, music stopped." << std::endl;
}

// Load music from a file and set it up for playback
bool SoundManager::loadMusic(const std::string& filename) {
    if (!backgroundSound.openFromFile(filename)) {
        std::cerr << "Failed to load music: " << filename << std::endl;
        return false;
    }
    backgroundSound.setVolume(volume);
    backgroundSound.setLoop(true); // Set the music to loop
    std::cout << "Music loaded successfully: " << filename << std::endl;
    return true;
}

// Play the loaded music if it is not already playing
void SoundManager::playMusic() {
    if (backgroundSound.getStatus() != sf::SoundSource::Playing) {
        backgroundSound.play();
        std::cout << "Playing music." << std::endl;
    } else {
        std::cout << "Music is already playing." << std::endl;
    }
}

// Stop the music if it is currently playing
void SoundManager::stopMusic() {
    if (backgroundSound.getStatus() == sf::SoundSource::Playing) {
        backgroundSound.stop();
        std::cout << "Music stopped." << std::endl;
    }
}

// Change the currently playing music to a new file
void SoundManager::changeMusic(const std::string& filename) {
    stopMusic(); // Stop the current music properly
    if (loadMusic(filename)) {
        playMusic();
    }
}

// Get the current volume level
int SoundManager::getVolume() {
    return static_cast<int>(volume);
}

// Set a new volume level and apply it immediately
void SoundManager::setVolume(int newVolume) {
    volume = static_cast<float>(newVolume);
    backgroundSound.setVolume(volume); // Apply the new volume immediately
    std::cout << "Volume set to: " << volume << std::endl;
}
