#ifndef CLIENT_STATE_HPP
#define CLIENT_STATE_HPP

#include <string>
#include <vector>
#include <memory>

#include "../network/host.hpp"
#include "../core/agent-state.hpp"
#include "../core/client-status.hpp"

struct ClientState: AgentState {
    ClientStatus status = SEARCHING;

    std::vector<std::shared_ptr<Host>> availableGames;
    std::string                        name;
    Host                               game;
};

#endif
