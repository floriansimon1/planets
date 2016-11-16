#include "./outgoing-message.hpp"
#include "./network.hpp"

OutgoingMessage::OutgoingMessage(const Host &h) {
    host = h;

    packetWrite(packet, "PLANETS");
}

void OutgoingMessage::tryPrepare() {
    if (prepared) {
        return;
    }

    prepare();

    prepared = true;
}
