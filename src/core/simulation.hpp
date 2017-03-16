#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <chrono>
#include <deque>

#include "./world.hpp"
#include "./player.hpp"
#include "./simulation-frame.hpp"

// Only way to appease the linter...
using namespace std::chrono_literals;

struct Simulation {
    static constexpr auto step = 30ms;

    // Once added, a player cannot be deleted for the rest of the game.
    std::deque<Player>          players;
    std::deque<SimulationFrame> frames;

    World world;
};

#endif
