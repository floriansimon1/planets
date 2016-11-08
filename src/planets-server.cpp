#include <cstdlib>

#include <unistd.h>

#include "./network/server.hpp"

int main(void) {
    Server server;

    while (true) {
        sleep(4);

        server.publish();
    }

    return EXIT_SUCCESS;
}
