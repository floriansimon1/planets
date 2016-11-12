#include "./connection-request-handler.hpp"
#include "./server-state.hpp"

#include <iostream>

void ConnectionRequestHandler::handle(Message &message, AgentState *statePointer) {
    auto &state = *((ServerState*) statePointer);

    std::cout << "Connection detected" << std::endl;
}
