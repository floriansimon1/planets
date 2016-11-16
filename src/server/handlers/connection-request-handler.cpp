#include "../messages/connection-authorized.hpp"
#include "./connection-request-handler.hpp"
#include "../server-state.hpp"

#include <iostream>

void ConnectionRequestHandler::handle(
    Communicator &communicator,
    Message &message,
    AgentState &statePointer
) const {
    // Copies the host - this is a direct reply.
    ConnectionAuthorized response(message.host);

    std::cout << "Connection detected" << std::endl;

    communicator.send(response);
}
