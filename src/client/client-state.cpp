#include <numeric>

#include "./client-state.hpp"

Id ClientState::reserveNextPingRequestId() {
    const Id value = 1 + currentlyExpectedPingRequestId.value_or(0);

    currentlyExpectedPingRequestId.emplace(value);

    pingTimer.start();

    return value;
}

void ClientState::averageLatency() {
    sf::Int32 sum = std::accumulate(
        latencySamples.begin(),
        latencySamples.end(),
        0,

        [] (auto a, auto b) {
            return a + b;
        }
    );

    sf::Int32 average = sum / latencySamples.size();

    // Erase all samples but the first.
    latencySamples.erase(latencySamples.begin() + 1);

    // Set the first sample to the averaged value calculated above.
    latencySamples[0] = average;

    latency.emplace(average);
}

sf::Int32 ClientState::getServerTimestamp() const {
    return world.worldClock.getElapsedTime().asMilliseconds() + serverClockOffset;
}

ControllerState ClientState::bufferLocalPlayerInput() {
    std::vector<ControllerState> newStates;
    ControllerState              currentState;

    sf::Int32 timestamp = getServerTimestamp();

    if (bufferedControllerStates.empty()) {
        currentState = ControllerState(timestamp);

        // This buffer will be ignored, so we don't care what it contains.
        std::for_each(
            world.players.begin(),
            world.players.end(),

            [&newStates, &currentState] (const auto &_) {
                newStates.push_back(currentState);
            }
        );
    } else {
        currentState = ControllerState(timestamp, gamepad);

        const auto &previousControllerStates = bufferedControllerStates[0];

        const auto &previousLocalControllerState = previousControllerStates[0];

        /*
        * Refreshes the controller state of the local player,
        * duplicates remote player controller states.
        */
        if (currentState != previousLocalControllerState) {
            std::vector<ControllerState> newStates;

            newStates.push_back(currentState);

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
    }

    // If we have a new buffer to append, we do it now.
    if (newStates.size() > 0) {
        bufferedControllerStates.push_back(newStates);
    }

    return currentState;
}

bool ClientState::shouldSendPlayerInput() {
    const auto timestamp = getServerTimestamp();

    const auto difference = timestamp - lastInputSend;

    // Advance the last send input by as many ticks as needed, and returns true.
    if (difference >= tickDelay) {
        lastInputSend += ((sf::Int32) difference / tickDelay) * tickDelay;

        return true;
    } else {
        return false;
    }
}

void ClientState::clearBufferedInputs() {
    // Nothing to clear.
    if (bufferedControllerStates.empty()) {
        return;
    }

    // Keeps the last controller states in memory.
    bufferedControllerStates = std::deque<std::vector<ControllerState>>(
        bufferedControllerStates.end() - 1,
        bufferedControllerStates.end()
    );
}

void ClientState::refresh() {
    if (bufferedControllerStates.size() > 1) {
        return;
    }

    const auto &firstStatesIterator = bufferedControllerStates.begin();

    const auto &firstStates = *firstStatesIterator;

    sf::Int32 start = firstStates[0].timestamp;

    // We drop one input buffer and start iterating from it.
    std::for_each(
        firstStatesIterator + 1,
        bufferedControllerStates.end(),

        [&start, this] (auto &controllerStates) {
            sf::Int32 timestamp = controllerStates[0].timestamp;

            // Calculates the elapsed time to advance the simulation.
            sf::Int32 dt = timestamp - start;

            // Does advance the simulation.
            world.makeNextFrame(dt, controllerStates);

            // The reference point becomes the timestamp we've just used to compute Δt.
            start = timestamp;
        }
    );
}
