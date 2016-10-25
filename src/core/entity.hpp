#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System.hpp>

// An object in the game "world".
struct Entity {
    sf::Vector2f position;

    Entity(float x, float y): position(x, y) {}
};

#endif
