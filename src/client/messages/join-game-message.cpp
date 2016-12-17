#include "./join-game-message.hpp"
#include "../../network/network.hpp"
#include "../../network/message-types.hpp"

JoinGameMessage::JoinGameMessage(const Host &h, const std::string &n, unsigned short p):
    OutgoingMessage(h),
    localPort(p),
    name(n) {
}

void JoinGameMessage::prepare() {
    packetWrite(packet, CONNECTION_REQUEST);
    packetWrite(packet, localPort);
    packetWrite(packet, name);
}
