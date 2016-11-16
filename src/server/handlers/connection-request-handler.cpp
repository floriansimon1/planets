#include "../messages/connection-authorized.hpp"
#include "./connection-request-handler.hpp"
#include "../../network/network.hpp"
#include "../server-state.hpp"

#include <iostream>

void ConnectionRequestHandler::handle(
    Communicator &communicator,
    Message &message,
    AgentState &statePointer
) const {
    sf::Uint16 port;

    // TODO: Do something with the port.
    packetRead(message.packet, port);

    // Copies the host - this is a direct reply.
    ConnectionAuthorized response(message.host);

    std::cout << ">> Connection request from " << message.host.toString() << std::endl;

    communicator.send(response);
}
