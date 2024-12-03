#include "GameController.h"

GameController::GameController() : mapController(fileReader.readMap("assets/map.txt")) {}

void GameController::run() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Map");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mapController.draw(window);
        window.display();
    }
}