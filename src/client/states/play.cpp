#include <numeric>
#include <algorithm>

#include "../../boilerplate/remove-in.hpp"
#include "../messages/player-input.hpp"
#include "./play.hpp"

Play::Play(const Host &g, sf::Int32 l, sf::Int32 o):
    serverClockOffset(o),
    latency(l),
    game(g)
{
    world.worldClock.restart();

    inputHistory.startBuffering(getServerTimestamp(), 0);
}

sf::Int32 Play::getServerTimestamp() const {
    return world.worldClock.getElapsedTime().asMilliseconds() + serverClockOffset;
}

void Play::processInputHistory(Id from) {
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

bool Play::isGameState() const {
    return true;
}

void Play::doProcess(ClientApplication &application) {
    const auto timestamp = getServerTimestamp();

    inputHistory.bufferLocalPlayerInput(timestamp);

    processInputHistory(inputHistory.lastDisplayed);

    inputHistory.historyDisplayed();

    if (inputHistory.shouldFlush(timestamp)) {
        const auto firstStatesIterator = inputHistory.getStateIterator(inputHistory.lastSent + 1);

        std::vector<ControllerState> toSend;

        for (auto it = firstStatesIterator; it < inputHistory.history.end(); it++) {
            const auto &newState = (*it)[0];

            if (it == inputHistory.history.begin()) {
                toSend.push_back(newState);

                continue;
            }

            const auto &oldState = (*(it - 1))[0];

            if (newState != oldState) {
                toSend.push_back(newState);
            }
        }

        if (toSend.size()) {
            PlayerInput inputTransferMessage(game, toSend);

            application.communicator.send(inputTransferMessage);

            inputHistory.historySent(timestamp);
        }
    }
}