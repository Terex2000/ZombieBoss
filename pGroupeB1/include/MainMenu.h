#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include <vector>

class MainMenu {
public:
    enum class Option { NewGame, Settings, Shop, Quit };

    MainMenu();
    virtual ~MainMenu();

    const std::vector<std::string>& getOptions() const;
    Option getSelectedOption() const;
    void selectNext();
    void selectPrevious();
    void confirmSelection();

private:
    std::vector<std::string> options;
    int selectedIndex;
};

#endif // MAINMENU_H
