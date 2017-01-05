#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/System.hpp>

struct World {
    sf::Clock    clock;
    sf::Vector2f dimensions;

    World();
};

#endif
