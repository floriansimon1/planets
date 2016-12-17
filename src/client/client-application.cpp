#include <numeric>

#include "./client-application.hpp"
#include "./states/searching-games.hpp"

ClientApplication(): communicator(ClientCommunicator()) {
    stepStack.push(SearchingGames());
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
