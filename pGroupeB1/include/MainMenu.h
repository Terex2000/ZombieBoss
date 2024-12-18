#ifndef MAINMENU_H
#define MAINMENU_H

#include <vector>
#include <string>

class MainMenu {
public:
    enum Option { Play, Shop, Settings, Quit };

    MainMenu();
    ~MainMenu();

    const std::vector<std::string>& getOptions() const;
    Option getSelectedOption() const;
    void selectNext();
    void selectPrevious();

private:
    std::vector<std::string> options;
    int selectedIndex;
};

#endif // MAINMENU_H
