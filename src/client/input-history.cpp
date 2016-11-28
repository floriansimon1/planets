#include "./input-history.hpp"
#include "../boilerplate/drop.hpp"

void InputHistory::startBuffering(sf::Int32 timestamp) {
    lastDisplayedStates.push_back(ControllerState(timestamp, gamepad));
}

void InputHistory::bufferLocalPlayerInput(sf::Int32 timestamp)  {
    ControllerState currentState(timestamp, gamepad);

    std::vector<ControllerState> newStates;

    // Refreshes the controller state of the local player,
    newStates.push_back(currentState);

    const lastPlay
        /*
        * Until we receive the actual remote player input from the server,
        * we assume that it remains unchanged. But we do so only if there
        * any actual remote players.
        */
        if (previousControllerStates.size() > 1) {
            const auto oldRemoteControllerStatesBegin = previousControllerStates.begin() + 1;
            const auto oldRemoteControllerStatesEnd   = previousControllerStates.end();

            newStates.insert(
                newStates.end(),
                oldRemoteControllerStatesBegin,
                oldRemoteControllerStatesEnd
            );
        }
    }

    if (newStates.size() > 0) {
        history.push_back(newStates);
    }
}

size_t InputHistory::nextDisplayBufferIterator() {
    const auto lastDisplayed = lastDisplayedStates.size() + 1;

    lastDisplayedStates = *history.end();

    return lastDisplayed;
}

bool InputHistory::shouldSendPlayerInput(sf::Int32 timestamp) {
    const auto difference = timestamp - lastInputSend;

    // Advance the last send input by as many ticks as needed, and returns true.
    if (difference >= TICK_DELAY) {
        lastInputSend += ((sf::Int32) difference / TICK_DELAY) * TICK_DELAY;

        return true;
    } else {
        return false;
    }
}

void InputHistory::ackInputHistory(Id stateId) {
    drop(history, stateId - lastAckedInputState);
}
