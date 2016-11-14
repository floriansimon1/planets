#include "./connection-authorized.hpp"
#include "../../network/message-types.hpp"

void ConnectionAuthorized::prepare() {
    packet
    << CONNECTION_RESPONSE
    << true;
}
