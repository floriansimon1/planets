#ifndef AGENT_STATE_HPP
#define AGENT_STATE_HPP

#include <SFML/System.hpp>

#include "./world.hpp"

struct AgentState {
    // In ms.
    const sf::Int32 computationDelay = 100;
};

#endif
