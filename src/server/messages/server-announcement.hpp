#ifndef SERVER_ANNOUNCEMENT_HPP
#define SERVER_ANNOUNCEMENT_HPP

#include <SFML/Network.hpp>

#include "../server-application.hpp"

struct ServerAnnouncement {
    static sf::Packet getPacket(const ServerApplication &application);
};

#endif
