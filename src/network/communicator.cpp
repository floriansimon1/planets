#include "./host.hpp"
#include "./network.hpp"
#include "./message.hpp"
#include "./communicator.hpp"
#include "../boilerplate/repeat-max.hpp"

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

void Communicator::processNextMessagesBatch(Application &application, unsigned int batchSize) {
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

            packetTypeRead(message.packet, type);

            if (messageHandlers.count(type)) {
                messageHandlers[type]->handle(application, message);
            }
        } catch (PacketReadError&) {}
    }
}

void Communicator::communicate(Application &application) {
    messageQueue.appendMessages(readNextMessagesBatch(processBatchSize));

    processNextMessagesBatch(application, processBatchSize);
}

sf::Socket::Status Communicator::send(OutgoingMessage &message) {
    message.doPrepare();

    if (!message.error) {
        return socket.send(message.packet, message.host.address, message.host.port);
    } else {
        return sf::Socket::Error;
    }
}
