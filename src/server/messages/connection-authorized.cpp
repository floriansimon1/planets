#include "../../network/network.hpp"
#include "./connection-authorized.hpp"
#include "../../network/message-types.hpp"

void ConnectionAuthorized::prepare() {
    packetTypeWrite(packet, MessageType::ConnectionResponse);

    packetWrite(packet, true);
}
