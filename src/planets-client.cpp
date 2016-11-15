#include <cstdlib>

#include "./client/client-communicator.hpp"
#include "./client/client-state.hpp"
#include "./core/client-status.hpp"

int main(void) {
    ClientState        state;
    ClientCommunicator communicator;

    state.name = "Paul";

    while (state.status != EXIT) {
        communicator.converse(state);
    }

    return EXIT_SUCCESS;
}
