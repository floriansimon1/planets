#ifndef SERVER_STATE_HPP
#define SERVER_STATE_HPP

#include <string>

#include "../client.hpp"
#include "../../core/state.hpp"
#include "../../network/network.hpp"
#include "../server-application.hpp"

struct ServerState: State {
    // Adapter method that casts application parameters to client application parameters.
    virtual void process(Application &application);

    virtual void doProcess(ServerApplication &application) = 0;

    // Callbacks on specific events.
    virtual void onJoin(ServerApplication &application, Client client) {}
    virtual void onPong(ServerApplication &application, Host host, Id requestId) {}
    virtual void onInputBuffer(ServerApplication &application, Host host, std::vector<ControllerState> inputs) {}
};

#endif
