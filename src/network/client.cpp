#include <iostream>
#include <algorithm>

#include "./client.hpp"
#include "../boilerplate/remove-in.hpp"
#include "../boilerplate/find-value-in-shared-pointer-collection.hpp"

using namespace std;

Client::Client() {
    if (socket.bind(BROADCAST_PORT) != sf::Socket::Done) {
        throw "NetworkError";
    }

    socket.setBlocking(false);
}

void Client::updateAvailableGamesList(std::vector<std::shared_ptr<HostedGame>> &list) {
    sf::Packet packet;
    HostedGame game;

    while (socket.receive(packet, game.host, game.port) == sf::Socket::Done) {
        auto existingGameEntry = findValueInSharedPointerCollection(list, game);

        if (existingGameEntry) {
            existingGameEntry->lastSeen.restart();

            cout
            << "Updated existing game!"
            << endl;
        } else {
            std::shared_ptr<HostedGame> newGameEntry(new HostedGame(game));

            list.push_back(newGameEntry);

            cout
            << "Found a game!"
            << endl;
        }
    }

    // Removes games that no longer exist.
    removeIn(list, [] (auto game) {
        if (game->lastSeen.getElapsedTime().asSeconds() > 1) {
            cout
            << "Removed game"
            << endl;

            return true;
        } else {
            return false;
        }
    });
}

void Client::joinGame(HostedGame &game) {
}
