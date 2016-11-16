#include "./host.hpp"

#include <sstream>

bool Host::operator==(const Host &g) const {
    return g.port == port && g.address == address;
}

std::string Host::toString() const {
    std::ostringstream builder;

    builder << address << ", " << port;

    return builder.str();
}
