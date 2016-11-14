#ifndef CLIENT_COMMUNICATOR_HPP
#define CLIENT_COMMUNICATOR_HPP

#include <SFML/Network.hpp>

#include <string>
#include <vector>
#include <memory>

#include "../network/communicator.hpp"
#include "../network/host.hpp"

struct ClientCommunicator: Communicator {
    ClientCommunicator();

    void joinGame(Host &game, const std::string &name);

    void updateAvailableGamesList(std::vector<std::shared_ptr<Host>> &list);
};

#endif
