#include <cstdlib>

#include <unistd.h>

#include "./network/server-communicator.hpp"

int main(void) {
    ServerCommunicator server;

    while (!server.exit) {
        server.serve();
    }

    return EXIT_SUCCESS;
}
