#include "../../network/message-types.hpp"
#include "./get-current-tick-request.hpp"
#include "../../network/network.hpp"

void GetCurrentTickRequest::prepare() {
    packetWrite(packet, PING);
    packetWrite(packet, requestId);
}
