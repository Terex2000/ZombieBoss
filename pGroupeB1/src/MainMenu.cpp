#include "MainMenu.h"

// Constructor: Initializes the MainMenu with default options and sets the selected index to 0
MainMenu::MainMenu() : selectedIndex(0) {
    options = {"Play", "Load Game", "Settings", "Quit"}; // Add Load Game option
}

// Destructor: Cleans up resources used by the MainMenu
MainMenu::~MainMenu() {}

// Returns the list of menu options
const std::vector<std::string>& MainMenu::getOptions() const {
    return options;
}

// Returns the currently selected menu option
MainMenu::Option MainMenu::getSelectedOption() const {
    return static_cast<Option>(selectedIndex);
}

// Adds a new option to the menu
void MainMenu::addOption(const std::string& option) {
    options.push_back(option);
}

// Selects the next menu option
void MainMenu::selectNext() {
    selectedIndex = (selectedIndex + 1) % options.size();
}

// Selects the previous menu option
void MainMenu::selectPrevious() {
    selectedIndex = (selectedIndex - 1 + options.size()) % options.size();
}
