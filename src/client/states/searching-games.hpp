#ifndef SEARCHING_GAMES_HPP
#define SEARCHING_GAMES_HPP

#include <vector>

#include "./client-state.hpp"
#include "../../network/host.hpp"

struct SearchingGames: ClientState {
    std::vector<Host> availableGames;

    virtual void doProcess(Communicator &communicator);
    void updateAvailableGamesList(ClientCommunicator &communicator);
};

#endif
