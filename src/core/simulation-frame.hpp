#ifndef SIMULATION_FRAME_HPP
#define SIMULATION_FRAME_HPP

#include <deque>

#include "./entity.hpp"

struct SimulationFrame {
    std::deque<Entity> entities;
};

#endif
