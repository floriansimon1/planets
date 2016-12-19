#ifndef CLIENT_STATE_HPP
#define CLIENT_STATE_HPP

#include "../../core/state.hpp"
#include "../../network/network.hpp"
#include "../client-application.hpp"

struct ClientState: State {
    // Adapter method that casts application parameters to client application parameters.
    virtual void process(Application &application);

    virtual void doProcess(ClientApplication &ClientApplication) = 0;

    // Callbacks on specific events.
    virtual void onConnection(ClientApplication &application) {}
    virtual void onConnectionRefused(ClientApplication &application) {}
    virtual void onPong(ClientApplication &application, Id pongId, sf::Int32 serverClockOffset) {}

    // Identification methods.
    virtual bool isGameState() const;
    virtual bool isConnectionState() const;
};

#endif
