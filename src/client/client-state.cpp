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

void ClientState::processInputHistory(Id from) {
    const auto &lastDisplayedIterator = inputHistory.getStateIterator(inputHistory.lastDisplayed);

    const auto &lastDisplayed = *lastDisplayedIterator;

    std::accumulate(
        lastDisplayedIterator + 1,
        inputHistory.history.end(),
        lastDisplayed[0].timestamp,

        [this] (auto start, auto &states) {
            sf::Int32 timestamp = states[0].timestamp;

            // Calculates the elapsed time to advance the simulation.
            sf::Int32 dt = timestamp - start;

            // Does advance the simulation.
            world.makeNextFrame(dt, states);

            // The next start point is the timestamp we've just used to compute Δt.
            return states[0].timestamp;
        }
    );
}

void ClientState::process() {
    if (status != PLAYING) {
        return;
    }

    const auto timestamp = getServerTimestamp();

    inputHistory.bufferLocalPlayerInput(timestamp);

    processInputHistory(inputHistory.lastDisplayed);

    inputHistory.historyDisplayed();
}
