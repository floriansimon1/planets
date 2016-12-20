#ifndef SERVER_APPLICATION_HPP
#define SERVER_APPLICATION_HPP

#include "./server-communicator.hpp"
#include "../core/application.hpp"

struct ServerApplication: Application {
    ServerApplication();

    /*
    * Used to avoid pointers when calling the application constructor
    * and annoying casting in game logic code. serverCommunicator and
    * communicator are the same object, with different type info.
    */
    ServerCommunicator serverCommunicator;
};

#endif
