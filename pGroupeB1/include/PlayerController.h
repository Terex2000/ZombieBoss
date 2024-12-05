// PlayerController.h
#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "PlayerView.h"

class PlayerController {
public:
    PlayerController(float startX, float startY);
    ~PlayerController();
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);
    const sf::CircleShape& getPlayerShape() const;
    void setPosition(float x, float y);

private:
    Player player;
    PlayerView playerView;
};

#endif // PLAYERCONTROLLER_H