#ifndef CLIENT_COMMUNICATOR_HPP
#define CLIENT_COMMUNICATOR_HPP

#include <SFML/Network.hpp>

#include <string>
#include <vector>

#include "../network/communicator.hpp"
#include "../network/host.hpp"
#include "./client-state.hpp"

struct ClientCommunicator: Communicator {
    ClientCommunicator();

    void converse(ClientState &clientState);

    void updateAvailableGamesList(std::vector<Host> &list);
};

#endif
