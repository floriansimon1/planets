#include "./join-game-message.hpp"
#include "../../network/network.hpp"
#include "../../network/message-types.hpp"

JoinGameMessage::JoinGameMessage(const Host &h, const std::string &n, unsigned short p):
    OutgoingMessage(h),
    localPort(p),
    name(n) {
}

void JoinGameMessage::prepare() {
    packetTypeWrite(packet, MessageType::ConnectionRequest);

    packetWrite(packet, localPort);
    packetWrite(packet, name);
}
