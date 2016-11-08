#include "./hosted-game.hpp"

bool HostedGame::operator==(const HostedGame &g) const {
    return g.port == port && g.host == host;
}
