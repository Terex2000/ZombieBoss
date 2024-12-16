#include "Settings.h"

Settings::Settings()
    : difficulty(Medium), volume(50), fullscreen(false), selectedOption(0) {
    options = {"Difficulty", "Volume", "Fullscreen", "Back"};
}

Settings::~Settings() {}

Settings::Difficulty Settings::getDifficulty() const {
    return difficulty;
}

void Settings::setDifficulty(Difficulty difficulty) {
    this->difficulty = difficulty;
}

int Settings::getVolume() const {
    return volume;
}

void Settings::setVolume(int volume) {
    this->volume = volume;
}

bool Settings::isFullscreen() const {
    return fullscreen;
}

void Settings::setFullscreen(bool fullscreen) {
    this->fullscreen = fullscreen;
}

const std::vector<std::string>& Settings::getOptions() const {
    return options;
}

int Settings::getSelectedOption() const {
    return selectedOption;
}

void Settings::selectNext() {
    selectedOption = (selectedOption + 1) % options.size();
}

void Settings::selectPrevious() {
    selectedOption = (selectedOption - 1 + options.size()) % options.size();
}
