#ifndef INPUT_HISTORY_HPP
#define INPUT_HISTORY_HPP

#include <SFML/System.hpp>
#include <list>

#include "../network/network.hpp"
#include "./controller-state.hpp"

struct InputHistory {
    std::list<ControllerState> history;

    void bufferInput(sf::Int32 timestamp, const Controller &controller);
    void insertControllerState(const ControllerState &state);
    void discardHistory(sf::Int32 timestamp);
};

#endif
