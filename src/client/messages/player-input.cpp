#include "./player-input.hpp"
#include "../../network/network.hpp"
#include "../../network/message-types.hpp"

PlayerInput::PlayerInput(const Host &h,  const std::deque<std::vector<ControllerState>> &i):
    OutgoingMessage(h), inputs(i) {
}

void PlayerInput::prepare() {
    if (inputs.empty()) {
        error = true;

        return;
    }

    packetWrite(packet, CLIENT_INPUT);

    // TODO: Check that size does not exceed max datagram size.
    for (auto &controllers: inputs) {
        // We only need to send the input of the local player.
        const auto &controller = controllers[0];

        packetWrite(packet, controller.timestamp);
        packetWrite(packet, controller.turnLeft());
        packetWrite(packet, controller.turnRight());
        packetWrite(packet, controller.accelerate());
        packetWrite(packet, controller.accelerateBackward());
    }
}
