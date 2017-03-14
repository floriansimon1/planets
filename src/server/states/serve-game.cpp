#include <algorithm>
#include <iostream>

#include "./serve-game.hpp"
#include "../messages/pong.hpp"
#include "../messages/server-announcement.hpp"
#include "../../boilerplate/ids-generator.hpp"
#include "../messages/connection-authorized.hpp"

static IdsGenerator playerIdsGenerator;

ServeGame::ServeGame(): maxPlayers(5) {
}

std::vector<Client>::iterator ServeGame::findClient(Host host) {
    return std::find_if(
        clients.begin(),
        clients.end(),

        [&host] (auto &client) {
            return client.host == host;
        }
    );
}

void ServeGame::onJoin(ServerApplication &application, Client newClient) {
    clients.push_back(newClient);

    // Copies the host - this is a direct reply.
    ConnectionAuthorized response(newClient.host);

    application.communicator.send(response);

    std::cout
    << ">> Connection request from " << newClient.host.toString() << "\n"
    << ">> " << newClient.player.name << " joined the game"
    << std::endl;
}

void ServeGame::onPong(ServerApplication &application, Host host, Id requestId) {
    Pong pong(host, requestId, *this);

    std::cout << ">> Received a ping" << std::endl;

    application.communicator.send(pong);
}

void ServeGame::onInputBuffer(ServerApplication &application, Host host, std::vector<ControllerState> inputs) {
    auto clientIterator = findClient(host);

    if (clientIterator == clients.end()) {
        return;
    }

    std::for_each(inputs.begin(), inputs.end(), [&clientIterator] (auto &input) {
        clientIterator->bufferControllerState(input);
    });
}

sf::Int32 ServeGame::getGameTimestamp() const {
    return world.clock.getElapsedTime().asMilliseconds();
}

void ServeGame::doProcess(ServerApplication &application) {
    application.serverCommunicator.broadcast(ServerAnnouncement::getPacket(application));

    if (clients.empty()) {
        return;
    }

    const auto timestamp = getGameTimestamp() - processingDelay;

    
}
