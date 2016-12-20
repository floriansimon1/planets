#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "./server/server-application.hpp"

int main(void) {
    ServerApplication server;

    std::cout << ">> PLANETS (server)" << std::endl;

    while (!server.shouldExit()) {
        server.run();

        usleep(10000);
    }

    return EXIT_SUCCESS;
}
