#include <algorithm>
#include <unistd.h>

#include <SFML/Network.hpp>
#include <experimental/optional>

#include "../network/ports.hpp"
#include "./messages/join-game.hpp"
#include "./client-communicator.hpp"
#include "../boilerplate/remove-in.hpp"
#include "../network/message-types.hpp"
#include "./client-message-handlers-list.hpp"
#include "./messages/get-current-tick-request.hpp"

ClientCommunicator::ClientCommunicator(): Communicator(clientHandlers()) {
    if (socket.bind(BROADCAST_PORT) != sf::Socket::Done) {
        throw "NetworkError";
    }

    socket.setBlocking(false);
}

void ClientCommunicator::updateAvailableGamesList(std::vector<Host> &list) {
    std::string    header;
    sf::Packet     packet;
    Host           game;
    unsigned short _;

    while (socket.receive(packet, game.address, _) == sf::Socket::Done) {
        packet >> header;
        packet >> game.port;

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

#include <iostream>
void ClientCommunicator::converse(ClientState &state) {
    process(state);

    if (state.status == SEARCHING) {
        updateAvailableGamesList(state.availableGames);

        if (state.availableGames.size() > 0) {
            const Host &game = state.availableGames[0];

            state.status = CONNECTING;
            state.game   = std::experimental::optional<Host>(game);

            JoinGame request(game, state.name);

            send(request);
        }
    } else if (state.status == PINGING) {
        std::cout << "Pingouin" << std::endl;
        GetCurrentTickRequest request(*state.game);

        send(request);
    }
}
