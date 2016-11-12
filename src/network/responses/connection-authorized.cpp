#include "./connection-authorized.hpp"
#include "../message-types.hpp"

void ConnectionAuthorized::specializedResponsePreparation(sf::Packet &packet) {
    packet
    << CONNECTION_RESPONSE
    << true;
}
