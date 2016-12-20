#ifndef INPUT_HISTORY_HPP
#define INPUT_HISTORY_HPP

#include <SFML/System.hpp>
#include <vector>
#include <deque>

#include "../input/gamepad.hpp"
#include "../network/network.hpp"
#include "../input/controller-state.hpp"

struct InputHistory {
    Id        lastDisplayed;
    sf::Int32 lastSentTime;
    Id        lastAcked;
    Id        lastSent;

    Gamepad                                  gamepad;
    std::deque<std::vector<ControllerState>> history;

    std::deque<std::vector<ControllerState>>::iterator getStateIterator(Id stateId);
    void startBuffering(sf::Int32 timestamp, size_t nbRemotePlayers);
    const std::vector<ControllerState>& operator[](Id stateId);
    void bufferLocalPlayerInput(sf::Int32 timestamp);
    bool shouldFlush(sf::Int32 timestamp);
    void historySent(sf::Int32 timestamp);
    void ackInputHistory(Id ackedId);
    void historyDisplayed();
};
#endif
