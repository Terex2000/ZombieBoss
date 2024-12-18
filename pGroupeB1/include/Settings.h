#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>

class Settings {
public:
    enum Difficulty { Easy, Medium, Hard };

    Settings();
    ~Settings();

    // Getters et setters
    Difficulty getDifficulty() const;
    void setDifficulty(Difficulty difficulty);

    int getVolume() const;
    void setVolume(int volume);

    bool isFullscreen() const;
    void setFullscreen(bool fullscreen);

    const std::vector<std::string>& getOptions() const;
    int getSelectedOption() const;
    void selectNext();
    void selectPrevious();

private:
    Difficulty difficulty;
    int volume;
    bool fullscreen;

    std::vector<std::string> options; // "Difficulty", "Volume", "Fullscreen", "Back"
    int selectedOption; // Option actuellement s�lectionn�e
};

#endif // SETTINGS_H
