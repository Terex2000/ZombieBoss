#ifndef PAUSEVIEW_H
#define PAUSEVIEW_H

#include <SFML/Graphics.hpp>

class PauseView {
public:
    PauseView(sf::RenderWindow& window);
    ~PauseView();

    void render(int selectedOption);


private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text pauseText;
};

#endif // PAUSEVIEW_H
