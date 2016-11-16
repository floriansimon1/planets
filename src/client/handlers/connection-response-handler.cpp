#include <iostream>

#include "../client-state.hpp"
#include "../../network/network.hpp"
#include "../../core/client-status.hpp"
#include "./connection-response-handler.hpp"

void ConnectionResponseHandler::handle(Communicator &communicator, Message &message, AgentState &state) const {
    ClientState &clientState = (ClientState&) state;

    bool authorized;

    packetRead(message.packet, authorized);

    if (authorized) {
        std::cout << ">> Request to join game granted" << std::endl;

        clientState.status = SYNC;
    } else {
        std::cout << ">> Request to join game denied" << std::endl;

        clientState.status = SEARCHING;
    }
}
