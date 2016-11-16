#include "../../network/network.hpp"
#include "./connection-authorized.hpp"
#include "../../network/message-types.hpp"

void ConnectionAuthorized::prepare() {
    packetWrite(packet, CONNECTION_RESPONSE);
    packetWrite(packet, true);
}
