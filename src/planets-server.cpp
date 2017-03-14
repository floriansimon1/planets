#include <cstdlib>
#include <iostream>

#include "./server/server-application.hpp"

int main(void) {
    ServerApplication server;

    std::cout << ">> PLANETS (server)" << std::endl;

    server.awaitTermination();

    return EXIT_SUCCESS;
}
