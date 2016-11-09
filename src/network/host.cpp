#include "./host.hpp"

bool Host::operator==(const Host &g) const {
    return g.port == port && g.address == address;
}
