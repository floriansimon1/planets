#include <numeric>
#include <iostream>

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
    ControllerState currentState(getServerTimestamp(), controllers[0]);

    if (bufferedControllerStates.size() > 0) {
        const auto &previousControllerStates = bufferedControllerStates[0];

        const auto &previousLocalControllerState = previousControllerStates[0];

        if (currentState != previousLocalControllerState) {
            std::vector<ControllerState> newStates;

            const auto &oldRemoteControllerStatesBegin = previousControllerStates.begin() + 1;
            const auto &oldRemoteControllerStatesEnd   = previousControllerStates.end();

            newStates.push_back(currentState);

            // Use the old controller states for remote players.
            newStates.insert(
                newStates.end(),
                oldRemoteControllerStatesBegin,
                oldRemoteControllerStatesEnd
            );

            bufferedControllerStates.push_back(newStates);
        }
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
    // TODO: Implement properly!
    bufferedControllerStates.clear();
}

void ClientState::refresh() {
    for (const auto &controllerStates: bufferedControllerStates) {
        for (const auto &controller: controllerStates) {

        }
    }
}
