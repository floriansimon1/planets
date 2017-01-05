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
}

sf::Int32 Play::getServerTimestamp() const {
    return world.worldClock.getElapsedTime().asMilliseconds() + serverClockOffset;
}

void Play::processInput(sf::Int32 timestamp) {
    inputHistory.bufferInput(timestamp, gamepad);

    auto &&toProcess = inputHistory
    .processingBookmark
    .getHistoryToProcess(timestamp);

    if (toProcess.size()) {
        // Adds a dummy controller state to the toProcess list so that the loop below works.
        toProcess.push_back(ControllerState(timestamp));

        /*
        * Each step takes the current state and the next one so that we can
        * get a duration by subtracting the two timestamps that we have.
        */
        std::accumulate(
            std::next(toProcess.begin()),
            toProcess.end(),
            *toProcess.begin(),

            [this] (auto &controllerState, auto &next) {
                std::vector<ControllerState> states { controllerState };

                sf::Int32 dt = next.timestamp - controllerState.timestamp;

                world.makeNextFrame(dt, states);

                return controllerState;
            }
        );
    }

    inputHistory.processingBookmark.mark(timestamp);
}

bool Play::isGameState() const {
    return true;
}

void Play::doProcess(ClientApplication &application) {
    const auto timestamp = getServerTimestamp();

    processInput(timestamp);

    if (inputHistory.sendBookmark.shouldSend(timestamp)) {
        const auto toSend = inputHistory.sendBookmark.getHistoryToSend();

        if (toSend.size()) {
            PlayerInput inputTransferMessage(game, toSend);

            application.communicator.send(inputTransferMessage);

            inputHistory.sendBookmark.mark(timestamp);
        }
    }
}
