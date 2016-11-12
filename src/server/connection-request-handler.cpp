#include "../network/responses/connection-authorized.hpp"
#include "./connection-request-handler.hpp"
#include "./server-state.hpp"

#include <iostream>

void ConnectionRequestHandler::handle(
    Communicator *communicator,
    Message &message,
    AgentState *statePointer
) {
    ConnectionAuthorized response;
    sf::Packet           responsePacket;

    // auto &state = *((ServerState*) statePointer);

    std::cout << "Connection detected" << std::endl;

    responsePacket = response.prepare();

    communicator->socket.send(responsePacket, message.host.address, message.host.port);
}
