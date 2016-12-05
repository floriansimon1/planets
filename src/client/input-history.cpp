#include "./input-history.hpp"
#include "../boilerplate/drop.hpp"
#include "../boilerplate/repeat-n.hpp"

// Implementation note: we should always have at least two entries in the history.

void InputHistory::startBuffering(sf::Int32 timestamp, size_t nbRemotePlayers) {
    lastSentTime  = timestamp;
    lastDisplayed = 0;
    lastAcked     = 0;
    lastSent      = 0;

    std::vector<ControllerState> initial;

    if (!history.size()) {
        initial.push_back(ControllerState(timestamp, gamepad));

        ControllerState remotePlayersInitialState(timestamp);

        repeatN(nbRemotePlayers, [&remotePlayersInitialState, &initial] () {
            initial.push_back(remotePlayersInitialState);
        });
    } else {
        initial = history.back();
    }

    history.push_back(initial);
}

void InputHistory::bufferLocalPlayerInput(sf::Int32 timestamp)  {
    ControllerState currentState(timestamp, gamepad);

    std::vector<ControllerState> newStates;

    // Refreshes the controller state of the local player,
    newStates.push_back(currentState);

    /*
    * Until we receive the actual remote player input from the server,
    * we assume that it remains unchanged. But we do so only if there
    * any actual remote players.
    */
    if (history.back().size() > 1) {
        const auto oldRemoteControllerStatesBegin = history.back().begin() + 1;
        const auto oldRemoteControllerStatesEnd   = history.back().end();

        newStates.insert(
            newStates.end(),
            oldRemoteControllerStatesBegin,
            oldRemoteControllerStatesEnd
        );
    }

    if (newStates.size() > 0) {
        history.push_back(newStates);
    }
}

const std::vector<ControllerState>& InputHistory::operator[](Id stateId) {
    return *getStateIterator(stateId);
}

bool InputHistory::shouldSendPlayerInput(sf::Int32 timestamp) {
    const auto difference = timestamp - history[lastSent][0].timestamp;

    // Advance the last send input by as many ticks as needed, and returns true.
    if (difference >= TICK_DELAY) {
        return true;
    } else {
        return false;
    }
}

std::deque<std::vector<ControllerState>>::iterator InputHistory::getStateIterator(Id stateId) {
    return history.begin() + (stateId - lastAcked);
}

void InputHistory::historyDisplayed() {
    lastDisplayed = history.size() - 1;
}

void InputHistory::historySent(sf::Int32 timestamp) {
    lastSentTime = timestamp;
    lastSent     = history.size();
}

void InputHistory::ackInputHistory(Id ackedId) {
    drop(history, ackedId - lastAcked);

    lastAcked = ackedId;
}
