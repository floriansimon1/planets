#ifndef INPUT_HISTORY_HPP
#define INPUT_HISTORY_HPP

#include <SFML/System.hpp>
#include <vector>
#include <deque>

#include "../input/gamepad.hpp"
#include "../network/network.hpp"
#include "../input/controller-state.hpp"

struct InputHistory {
    std::vector<ControllerState> lastDisplayedStates;
    Id        lastAckedInputState     = 0;
    sf::Int32 lastInputSend           = 0;

    Gamepad                                  gamepad;
    std::deque<std::vector<ControllerState>> history;

    void bufferLocalPlayerInput(sf::Int32 timestamp);
    bool shouldSendPlayerInput(sf::Int32 timestamp);
    void startBuffering(sf::Int32 timestamp);
    size_t nextDisplayBufferIterator();
    void ackInputHistory(Id stateId);
};

#endif
