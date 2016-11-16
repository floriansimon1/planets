#include "../client-state.hpp"
#include "../../network/network.hpp"
#include "../../core/client-status.hpp"
#include "./connection-response-handler.hpp"

void ConnectionResponseHandler::handle(Communicator &communicator, Message &message, AgentState &state) const {
    ClientState &clientState = (ClientState&) state;

    bool authorized;

    packetRead(message.packet, authorized);

    if (authorized) {
        clientState.status = SYNC;
    } else {
        clientState.status = SEARCHING;
    }
}
