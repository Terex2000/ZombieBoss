#include "Settings.h"

// Constructor: Initializes the Settings with default values for difficulty, volume, fullscreen, and selected option
Settings::Settings()
    : difficulty(Medium), volume(50), fullscreen(false), selectedOption(0) {
    options = {"Difficulty", "Volume", "Fullscreen", "Back"};
}

// Destructor: Cleans up resources used by the Settings
Settings::~Settings() {}

// Returns the current difficulty setting
Settings::Difficulty Settings::getDifficulty() const {
    return difficulty;
}

// Sets the difficulty setting
void Settings::setDifficulty(Difficulty difficulty) {
    this->difficulty = difficulty;
}

// Returns the current volume setting
int Settings::getVolume() const {
    return volume;
}

// Sets the volume setting
void Settings::setVolume(int volume) {
    this->volume = volume;
}

// Returns whether the game is in fullscreen mode
bool Settings::isFullscreen() const {
    return fullscreen;
}

// Sets the fullscreen mode
void Settings::setFullscreen(bool fullscreen) {
    this->fullscreen = fullscreen;
}

// Returns the list of settings options
const std::vector<std::string>& Settings::getOptions() const {
    return options;
}

// Returns the currently selected option index
int Settings::getSelectedOption() const {
    return selectedOption;
}

// Selects the next option in the settings menu
void Settings::selectNext() {
    selectedOption = (selectedOption + 1) % options.size();
}

// Selects the previous option in the settings menu
void Settings::selectPrevious() {
    selectedOption = (selectedOption - 1 + options.size()) % options.size();
}
