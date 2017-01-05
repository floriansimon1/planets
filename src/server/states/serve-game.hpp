#ifndef SERVE_GAME_HPP
#define SERVE_GAME_HPP

#include "../client.hpp"
#include "./server-state.hpp"
#include "../../core/world.hpp"
#include "../server-application.hpp"

struct ServeGame: ServerState {
    // In ms.
    const sf::Int32 processingDelay = 100;

    World               world;
    std::vector<Client> clients;
    unsigned int        maxPlayers;

    ServeGame();

    sf::Int32 getGameTimestamp() const;
    std::vector<Client>::iterator findClient(Host host);

    virtual void doProcess(ServerApplication &application) override;
    virtual void onJoin(ServerApplication &application, Client client) override;
    virtual void onPong(ServerApplication &application, Host host, Id requestId) override;
    virtual void onInputBuffer(ServerApplication &application, Host host, std::vector<ControllerState> inputs) override;
};

#endif
