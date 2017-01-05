#include "./get-current-tick-handler.hpp"
#include "../states/server-state.hpp"
#include "../../network/network.hpp"

void GetCurrentTickHandler::doHandle(ServerApplication &application, Message &message) const {
    auto &state = static_cast<ServerState&>(*application.getCurrentStep());

    Id requestId;

    packetRead(message.packet, requestId);

    state.onPong(application, message.host, requestId);
}
