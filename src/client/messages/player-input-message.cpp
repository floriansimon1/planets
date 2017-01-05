#include "../../network/network.hpp"
#include "./player-input-message.hpp"
#include "../../network/message-types.hpp"

PlayerInputMessage::PlayerInputMessage(const Host &h,  const std::list<ControllerState> &i):
    OutgoingMessage(h),
    inputs(i)
{
}

void PlayerInputMessage::prepare() {
    if (inputs.empty()) {
        error = true;

        return;
    }

    packetTypeWrite(packet, MessageType::ClientInput);

    // TODO: Check that packet size does not exceed max datagram size.
    for (const auto &state: inputs) {
        packetWrite(packet, state.timestamp);
        packetWrite(packet, state.turnLeft());
        packetWrite(packet, state.turnRight());
        packetWrite(packet, state.accelerate());
        packetWrite(packet, state.accelerateBackward());
    }
}
