#include <algorithm>

#include "./host.hpp"
#include "./message.hpp"
#include "./communicator.hpp"
#include "./message-handler.hpp"
#include "../boilerplate/repeat-max.hpp"

#define packetRead(packet, var) \
    if (!(packet >> var)) { \
        throw PacketReadError(); \
    }

static const unsigned int processBatchSize = 6;

std::vector<Message> Communicator::readNextMessagesBatch(unsigned int batchSize) {
    return repeatMax<Message>(batchSize, [this] () {
        sf::Packet packet;
        Message    message;

        const auto status = socket.receive(message.packet, message.host.address, message.host.port);

        if (status != sf::Socket::Done) {
            throw InterruptRepeatMaxException();
        }

        return message;
    });
}

void Communicator::processNextMessagesBatch(AgentState *state, unsigned int batchSize) {
    for (unsigned int i = 0; i < batchSize; i++) {
        Message     message;
        std::string header;

        if (messageQueue.isEmpty()) {
            break;
        }

        message = messageQueue.nextMessage();

        try {
            packetRead(message.packet, header);

            if (header != "PLANETS") {
                throw PacketReadError();
            }

            MessageType type;

            packetRead(message.packet, type);

            if (messageHandlers.count(type)) {
                messageHandlers[type]->handle(this, message, state);
            }
        } catch (PacketReadError&) {}
    }
}

// Main network processing loop for the server.
void Communicator::process(AgentState *state) {
    messageQueue.appendMessages(readNextMessagesBatch(processBatchSize));

    processNextMessagesBatch(state, processBatchSize);
}
