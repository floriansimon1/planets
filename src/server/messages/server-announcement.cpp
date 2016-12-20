#include "./server-announcement.hpp"
#include "../states/serve-game.hpp"
#include "../../network/ports.hpp"

sf::Packet ServerAnnouncement::getPacket(const ServerApplication &application) {
    const auto &step = static_cast<ServeGame&>(*application.getCurrentStep());

    sf::Packet announcement;

    announcement
    << "PLANETS"
    << (sf::Uint16) SERVER_PORT
    << (sf::Uint8) step.world.players.size()
    << (sf::Uint8) step.maxPlayers;

    return announcement;
}
