#ifndef SERVER_STATE_HPP
#define SERVER_STATE_HPP

#include "./client.hpp"
#include "../core/world.hpp"
#include "../network/host.hpp"
#include "../core/agent-state.hpp"

struct ServerState: AgentState {
    World               world;
    std::vector<Client> clients;
    unsigned int        maxPlayers;

    ServerState(): maxPlayers(5) {}
};

#endif
