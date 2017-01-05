#include "./pong.hpp"
#include "../../network/network.hpp"
#include "../../network/message-types.hpp"

Pong::Pong(const Host &h, const Id requestId, const ServeGame &state): OutgoingMessage(h) {
    packetTypeWrite(packet, MessageType::Ping);

    packetWrite(packet, requestId);
    packetWrite(packet, state.getGameTimestamp());
}
