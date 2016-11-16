#include <cstdlib>
#include <unistd.h>

#include "./server/server-state.hpp"
#include "./server/server-communicator.hpp"

int main(void) {
    ServerCommunicator server;
    ServerState        state;

    while (!server.exit) {
        server.serve(state);

        usleep(10000);
    }

    return EXIT_SUCCESS;
}
