#include "../client-state.hpp"
#include "../../network/network.hpp"
#include "../../core/client-status.hpp"
#include "./connection-response-handler.hpp"

#include <iostream>
void ConnectionResponseHandler::handle(Communicator &communicator, Message &message, AgentState &state) const {
    ClientState &clientState = (ClientState&) state;

    bool authorized;

    packetRead(message.packet, authorized);
std::cout << "lol" << std::endl;
    if (authorized) {
        clientState.status = PINGING;
    } else {
        clientState.status = SEARCHING;
    }
}
