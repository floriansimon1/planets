#include <algorithm>
#include <unistd.h>

#include <SFML/Network.hpp>

#include "../network/ports.hpp"
#include "./client-communicator.hpp"
#include "../boilerplate/remove-in.hpp"
#include "../network/message-types.hpp"
#include "./client-message-handlers-list.hpp"
#include "./messages/get-current-tick-request.hpp"
#include "../boilerplate/find-value-in-shared-pointer-collection.hpp"

ClientCommunicator::ClientCommunicator(): Communicator(clientHandlers()) {
    if (socket.bind(BROADCAST_PORT) != sf::Socket::Done) {
        throw "NetworkError";
    }

    socket.setBlocking(false);
}

void ClientCommunicator::updateAvailableGamesList(std::vector<std::shared_ptr<Host>> &list) {
    std::string    header;
    sf::Packet     packet;
    Host           game;
    unsigned short _;

    while (socket.receive(packet, game.address, _) == sf::Socket::Done) {
        packet >> header;
        packet >> game.port;

        auto existingGameEntry = findValueInSharedPointerCollection(list, game);

        if (existingGameEntry) {
            existingGameEntry->lastSeen.restart();
        } else {
            std::shared_ptr<Host> newGameEntry(new Host(game));

            list.push_back(newGameEntry);
        }
    }

    // Removes games that no longer exist.
    removeIn(list, [] (auto game) {
        return game->lastSeen.getElapsedTime().asSeconds() > 15;
    });
}

void ClientCommunicator::joinGame(Host &game, const std::string &name) {
    sf::Packet joinPacket;

    joinPacket
    << "PLANETS"
    << CONNECTION_REQUEST
    << (sf::Uint16) 45007    // Client port.
    << name;

    socket.send(joinPacket, game.address, game.port);
}

void ClientCommunicator::converse(ClientState &state) {
    bool gameJoined = false;

    while (true) {
        sleep(1);

        if (!gameJoined) {
            updateAvailableGamesList(state.availableGames);

            if (state.availableGames.size() > 0) {
                gameJoined = true;

                joinGame(*state.availableGames[0], state.name);
            }
        } else {
            GetCurrentTickRequest request(*state.availableGames[0]);

            send(request);
        }
    }
}
