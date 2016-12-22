#include <iostream>

#include "./client.hpp"

bool Client::validateTimestamp(sf::Int32 timestamp) const {
    return timestamp > inputHistory.getLastEntry().timestamp;
}

void Client::bufferControllerState(const ControllerState &state) {
    if (!validateTimestamp(state.timestamp)) {
        std::cout << ">> Discarding player input buffer" << std::endl;

        return;
    }
}
