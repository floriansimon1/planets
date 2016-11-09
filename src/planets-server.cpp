#include <cstdlib>

#include <unistd.h>

#include "./network/server-communicator.hpp"

int main(void) {
    ServerCommunicator server;

    while (true) {
        sleep(1);

        server.publish();

        server.handleJoinRequest();
    }

    return EXIT_SUCCESS;
}
