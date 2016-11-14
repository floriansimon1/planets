#ifndef CLIENT_STATE_HPP
#define CLIENT_STATE_HPP

#include <string>

#include "../network/host.hpp"
#include "../core/agent-state.hpp"

struct ClientState: AgentState {
    std::string name;
    Host        game;
};

#endif
