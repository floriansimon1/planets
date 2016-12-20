#ifndef SERVE_GAME_HPP
#define SERVE_GAME_HPP

#include "../client.hpp"
#include "../../core/world.hpp"
#include "../../network/host.hpp"
#include "../server-application.hpp"

struct ServeGame: State {
    World               world;
    std::vector<Client> clients;
    unsigned int        maxPlayers;

    ServeGame();

    virtual void process(Application &application);
    virtual void doProcess(ServerApplication &application);
};

#endif
