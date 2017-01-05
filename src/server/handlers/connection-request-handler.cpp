#include "./connection-request-handler.hpp"
#include "../states/server-state.hpp"
#include "../../network/network.hpp"
#include "../client.hpp"

#include <iostream>

void ConnectionRequestHandler::doHandle(ServerApplication &application, Message &message) const {
    auto &state = static_cast<ServerState&>(*application.getCurrentStep());

    Client newClient;

    newClient.host = message.host;

    packetRead(message.packet, newClient.host.port);
    packetRead(message.packet, newClient.player.name);

    state.onJoin(application, newClient);
}
