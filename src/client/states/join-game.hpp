#ifndef JOIN_GAME_HPP
#define JOIN_GAME_HPP

#include "./client-state.hpp"
#include "../../network/host.hpp"
#include "../client-application.hpp"

struct JoinGame: ClientState {
    bool requestSent = false;

    Host game;

    JoinGame(Host &game);

    virtual void doProcess(ClientApplication &application);

    virtual void onConnection(ClientApplication &application);
    virtual void onConnectionRefused(ClientApplication &application);

    virtual bool isConnectionState();
};

#endif
