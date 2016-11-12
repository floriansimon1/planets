#include <cstdlib>

#include "./server/server-state.hpp"
#include "./server/server-communicator.hpp"

int main(void) {
    ServerCommunicator server;
    ServerState        state;

    while (!server.exit) {
        server.serve(state);
    }

    return EXIT_SUCCESS;
}
