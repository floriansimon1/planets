#include "./server-communicator.hpp"
#include "./message-handlers-list.hpp"

#include <unistd.h>
#include <iostream>

ServerCommunicator::ServerCommunicator(): Communicator(serverHandlers()) {
    if (socket.bind(SERVER_PORT) != sf::Socket::Done) {
        throw "NetworkError";
    }

    socket.setBlocking(false);
}

void ServerCommunicator::serve(ServerState &state) {
    publish(state);
    process(&state);
    sleep(1);
}

void ServerCommunicator::publish(ServerState &state) {
    sf::Packet announcement;

    announcement
    << "PLANETS"
    << (sf::Uint16) SERVER_PORT
    << (sf::Uint8) state.world.players.size()
    << (sf::Uint8) state.maxPlayers;

    socket.send(announcement, sf::IpAddress::Broadcast, BROADCAST_PORT);
}