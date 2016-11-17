#include "../messages/connection-authorized.hpp"
#include "./connection-request-handler.hpp"
#include "../../network/network.hpp"
#include "../server-state.hpp"
#include "../client.hpp"

#include <iostream>

void ConnectionRequestHandler::handle(
    Communicator &communicator,
    Message &message,
    AgentState &s
) const {
    ServerState &state = (ServerState&) s;

    Client newPlayer;

    newPlayer.host = message.host;

    packetRead(message.packet, newPlayer.host.port);
    packetRead(message.packet, newPlayer.name);

    // Reads successful. We add our client to the world.
    state.world.players.push_back(newPlayer);

    // Copies the host - this is a direct reply.
    ConnectionAuthorized response(newPlayer.host);

    communicator.send(response);

    std::cout
    << ">> Connection request from " << message.host.toString() << "\n"
    << ">> " << newPlayer.name << " joined the game"
    << std::endl;
}
