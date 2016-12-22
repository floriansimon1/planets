#include "../messages/connection-authorized.hpp"
#include "./connection-request-handler.hpp"
#include "../../network/network.hpp"
#include "../states/serve-game.hpp"
#include "../client.hpp"

#include <iostream>

void ConnectionRequestHandler::doHandle(ServerApplication &application, Message &message) const {
    auto &step = static_cast<ServeGame&>(*application.getCurrentStep());

    Client newPlayer;

    newPlayer.inputHistory.startBuffering(0, Controller::inertPlayerControllerState());

    newPlayer.host = message.host;

    packetRead(message.packet, newPlayer.host.port);
    packetRead(message.packet, newPlayer.name);

    // Reads successful. We add our client to the world.
    step.world.players.push_back(newPlayer);

    // Copies the host - this is a direct reply.
    ConnectionAuthorized response(newPlayer.host);

    application.communicator.send(response);

    std::cout
    << ">> Connection request from " << message.host.toString() << "\n"
    << ">> " << newPlayer.name << " joined the game"
    << std::endl;
}
