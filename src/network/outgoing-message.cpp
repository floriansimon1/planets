#include "./outgoing-message.hpp"
#include "./network.hpp"

OutgoingMessage::OutgoingMessage(const Host &h) {
    host = h;

    preparePlanetsPacket(packet);
}

void OutgoingMessage::doPrepare() {
    if (prepared) {
        return;
    }

    prepare();

    prepared = true;
}
