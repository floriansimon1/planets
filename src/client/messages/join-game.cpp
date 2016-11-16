#include "./join-game.hpp"
#include "../../network/network.hpp"
#include "../../network/message-types.hpp"

JoinGame::JoinGame(const Host &h, const std::string &n): OutgoingMessage(h), name(n) {}
#include <iostream>
void JoinGame::prepare() {
    std::cout << "olol" << std::endl;
    packetWrite(packet, CONNECTION_REQUEST);
    packetWrite(packet, findAvailablePort());
    packetWrite(packet, name);
}
