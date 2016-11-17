#include "./pong-handler.hpp"
#include "../client-state.hpp"
#include "../../network/network.hpp"
#include "../messages/get-current-tick-request.hpp"

bool enoughLatencySamples(ClientState &state) {
    return state.latencySamples.size() >= 4;
}

void PongHandler::handle(Communicator &communicator, Message &message, AgentState &s) const {
    ClientState &state = (ClientState&) s;

    Id        pongId;
    sf::Int32 serverClockOffset;

    packetRead(message.packet, pongId);
    packetRead(message.packet, serverClockOffset);

    if (state.currentlyExpectedPingRequestId && state.currentlyExpectedPingRequestId.value() == pongId) {
        sf::Int32 latency = state.pingTimer.stop().asMilliseconds() / 2;

        state.latencySamples.push_back(latency);

        if (enoughLatencySamples(state)) {
            state.currentlyExpectedPingRequestId = std::experimental::optional<Id>();

            state.averageLatency();

            state.world.worldClock.restart();

            state.serverClockOffset = serverClockOffset;
            state.status            = PLAYING;

            std::cout
            << ">> Average latency: " << state.latency.value() << " ms\n"
            << ">> Clock offset: " << serverClockOffset << " ms"
            << std::endl;

        } else {
            GetCurrentTickRequest request(state.game.value(), state.reserveNextPingRequestId());

            std::cout
            << ">> Sending ping request #"
            << state.currentlyExpectedPingRequestId.value()
            << "..."
            << std::endl;

            communicator.send(request);
        }
    }
};
