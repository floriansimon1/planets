#include <algorithm>
#include <iostream>
#include <memory>

#include "../../boilerplate/remove-in.hpp"
#include "./searching-games.hpp"
#include "./join-game.hpp"

void SearchingGames::updateAvailableGamesList(ClientCommunicator &communicator) {
    std::string    header;
    sf::Packet     packet;
    Host           game;
    unsigned short _;

    while (communicator.gameDiscoverySocket.receive(packet, game.address, _) == sf::Socket::Done) {
        if (!(packet >> header >> game.port)) {
            continue;
        }

        auto existingGameEntry = std::find(availableGames.begin(), availableGames.end(), game);

        if (existingGameEntry != availableGames.end()) {
            existingGameEntry->lastSeen.restart();
        } else {
            availableGames.push_back(game);
        }
    }

    // Removes games that no longer exist.
    removeIn(availableGames, [] (auto &game) {
        return game.lastSeen.getElapsedTime().asSeconds() > 15;
    });
}

void SearchingGames::doProcess(ClientApplication &application) {
    updateAvailableGamesList(application.clientCommunicator);

    if (availableGames.size() > 0) {
        const Host &game = availableGames.front();

        std::cout
        << ">> Connecting to first found game ("
        << game.toString()
        << ")..."
        << std::endl;

        application.addStep(std::shared_ptr<State>(new JoinGame(game)));
    }
}
