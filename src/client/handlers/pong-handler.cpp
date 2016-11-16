#include "./pong-handler.hpp"
#include "../client-state.hpp"
#include "../../network/network.hpp"
#include "../messages/get-current-tick-request.hpp"

bool enoughLatencySamples(ClientState &state) {
    return state.latencySamples.size() >= 4;
}

void PongHandler::handle(Communicator &communicator, Message &message, AgentState &s) const {
    ClientState &state = (ClientState&) s;

    Id pongId;

    packetRead(message.packet, pongId);

    if (state.currentlyExpectedPingRequestId && state.currentlyExpectedPingRequestId.value() == pongId) {
        sf::Int32 latency = state.pingTimer.stop().asMilliseconds() / 2;

        state.latencySamples.push_back(latency);

        if (enoughLatencySamples(state)) {
            state.averageLatency();
        } else {
            GetCurrentTickRequest request(state.game.value(), state.reserveNextPingRequestId());

            communicator.send(request);
        }
    }
};
