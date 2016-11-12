#ifndef SERVER_COMMUNICATOR_HPP
#define SERVER_COMMUNICATOR_HPP

#include <vector>

#include "../network/communicator.hpp"
#include "./server-state.hpp"
#include "../core/world.hpp"

struct ServerCommunicator: Communicator {
    const bool exit = false;

    ServerCommunicator();

    void serve(ServerState &state);

    private:
        void publish(ServerState &state);
};

#endif
