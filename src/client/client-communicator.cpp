#include <algorithm>
#include <iostream>
#include <unistd.h>

#include <SFML/Network.hpp>
#include <experimental/optional>

#include "../network/ports.hpp"
#include "../network/network.hpp"
#include "./messages/join-game.hpp"
#include "./client-communicator.hpp"
#include "./messages/player-input.hpp"
#include "../boilerplate/remove-in.hpp"
#include "../network/message-types.hpp"
#include "./client-message-handlers-list.hpp"
#include "./messages/get-current-tick-request.hpp"

ClientCommunicator::ClientCommunicator(): Communicator(clientHandlers()) {
    if (gameDiscoverySocket.bind(BROADCAST_PORT) != sf::Socket::Done) {
        throw SocketBindError();
    }

    bindToAnyAvailablePort(socket);

    socket.setBlocking(false);
    gameDiscoverySocket.setBlocking(false);
}

void ClientCommunicator::updateAvailableGamesList(std::vector<Host> &list) {
    std::string    header;
    sf::Packet     packet;
    Host           game;
    unsigned short _;

    while (gameDiscoverySocket.receive(packet, game.address, _) == sf::Socket::Done) {
        if (!(packet >> header >> game.port)) {
            continue;
        }

        auto existingGameEntry = std::find(list.begin(), list.end(), game);

        if (existingGameEntry != list.end()) {
            existingGameEntry->lastSeen.restart();
        } else {
            list.push_back(game);
        }
    }

    // Removes games that no longer exist.
    removeIn(list, [] (auto &game) {
        return game.lastSeen.getElapsedTime().asSeconds() > 15;
    });
}

// Network processing main loop.
void ClientCommunicator::converse(ClientState &state) {
    process(state);

    try {
        if (state.status == SEARCHING) {
            updateAvailableGamesList(state.availableGames);

            if (state.availableGames.size() > 0) {
                const Host &game = state.availableGames[0];

                std::cout
                << ">> Connecting to first found game ("
                << game.toString()
                << ")..."
                << std::endl;

                state.status = CONNECTING;
                state.game   = std::experimental::optional<Host>(game);

                JoinGame request(game, state.name, socket.getLocalPort());

                send(request);
            }
        } else if (state.status == SYNC) {
            if (!state.currentlyExpectedPingRequestId) {
                std::cout << ">> Initiating game clock synchronization..." << std::endl;

                GetCurrentTickRequest request(state.game.value(), state.reserveNextPingRequestId());

                send(request);
            }
        } else if (state.status == PLAYING) {
            // TODO: Send input to server.
        }
    } catch (PacketWriteError &e) {}
}
