#ifndef CLIENT_APPLICATION_HPP
#define CLIENT_APPLICATION_HPP

#include <string>

#include "../core/application.hpp"
#include "./client-communicator.hpp"

struct ClientApplication: Application {
    std::string localPlayerName;

    ClientApplication();

    /*
    * Used to avoid pointers when calling the application constructor
    * and annoying casting in game logic code. clientCommunicator and
    * communicator are the same object, with different type info.
    */
    ClientCommunicator clientCommunicator;
};

#endif
