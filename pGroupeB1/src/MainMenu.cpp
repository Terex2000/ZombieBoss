#include "MainMenu.h"

MainMenu::MainMenu() : selectedIndex(0) {
    options = {"Play", "Shop", "Settings", "Quit"};
}

MainMenu::~MainMenu() {}

const std::vector<std::string>& MainMenu::getOptions() const {
    return options;
}

MainMenu::Option MainMenu::getSelectedOption() const {
    return static_cast<Option>(selectedIndex);
}

void MainMenu::selectNext() {
    selectedIndex = (selectedIndex + 1) % options.size();
}

void MainMenu::selectPrevious() {
    selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
}
