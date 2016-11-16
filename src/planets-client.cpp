#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "./client/client-communicator.hpp"
#include "./client/client-state.hpp"
#include "./core/client-status.hpp"

int main(void) {
    ClientState        state;
    ClientCommunicator communicator;

    state.name = "Paul";

    std::cout << ">> PLANETS (client)" << std::endl;

    while (state.status != EXIT) {
        usleep(10000);

        communicator.converse(state);
    }

    return EXIT_SUCCESS;
}
