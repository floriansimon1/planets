#include "./response.hpp"

sf::Packet Response::prepare() {
    sf::Packet packet;

    packet << "PLANETS";

    specializedResponsePreparation(packet);

    return packet;
}
