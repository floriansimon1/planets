#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System.hpp>
#include <iostream>
#include <cmath>

struct Player {
    sf::Vector2<int> direction;
    sf::Vector2<int> position;
    float            angle;

    Player(): direction(0, 0), position(500, 500), angle(M_PI) {}
};

#endif
