#include <vector>

#include "./client-input-handler.hpp"
#include "../states/server-state.hpp"
#include "../../input/controller-state.hpp"

void ClientInputHandler::doHandle(ServerApplication &application, Message &message) const {
    const auto &state = static_cast<ServerState&>(*application.getCurrentStep());

    std::vector<ControllerState> states;

    while (!message.packet.endOfPacket()) {
        ControllerState state;

        packetRead(message.packet, state.timestamp);

        packetRead(message.packet, state.left);
        packetRead(message.packet, state.right);
        packetRead(message.packet, state.forward);
        packetRead(message.packet, state.backward);

        states.push_back(state);
    }

    state.onInputBuffer(application, message.host, states);
}
