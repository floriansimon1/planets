#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <memory>
#include <cmath>

#include "entity.hpp"

struct Player: Entity {
    sf::Vector2<float> direction;

    // In degrees.
    float yaw;

    Player(): Entity(500.f, 500.f), direction(0.f, 0.f), yaw(0.f) { }
};

#endif
