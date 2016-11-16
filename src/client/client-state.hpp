#ifndef CLIENT_STATE_HPP
#define CLIENT_STATE_HPP

#include <experimental/optional>
#include <string>
#include <vector>

#include "../network/host.hpp"
#include "../core/agent-state.hpp"
#include "../core/client-status.hpp"

struct ClientState: AgentState {
    ClientStatus status = SEARCHING;

    std::vector<Host>                 availableGames;
    std::experimental::optional<Host> game;
    std::string                       name;
};

#endif
