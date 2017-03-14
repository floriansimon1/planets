#ifndef FRAME_HPP
#define FRAME_HPP

#include <vector>

#include "./world.hpp"
#include "./player.hpp"

struct Frame {
    const World         world;
    std::vector<Player> players;
    const sf::Int32     timestamp;

    const sf::Int32 timestep = 5;

    Frame next(sf::Int32 timestamp);
};

#endif
