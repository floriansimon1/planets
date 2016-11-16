#include "./join-game.hpp"
#include "../../network/network.hpp"
#include "../../network/message-types.hpp"

JoinGame::JoinGame(const Host &h, const std::string &n, unsigned short p):
    OutgoingMessage(h),
    localPort(p),
    name(n)
{}

void JoinGame::prepare() {
    packetWrite(packet, CONNECTION_REQUEST);
    packetWrite(packet, localPort);
    packetWrite(packet, name);
}
