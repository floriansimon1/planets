#include <SFML/Network.hpp>

#include "./host.hpp"
#include "./message.hpp"
#include "./communicator.hpp"
#include "../boilerplate/repeat-max.hpp"

const unsigned int processBatchSize = 6;

std::vector<Message> Communicator::readNextMessagesBatch(unsigned int batchSize) {
    return repeatMax<Message>(batchSize, [this] () {
        sf::Packet packet;
        Message    message;

        const auto status = socket.receive(packet, message.host.address, message.host.port);

        if (status != sf::Socket::Done) {
            throw InterruptRepeatMaxException();
        }

        return message;
    });
}

// Main network processing loop for the server.
void Communicator::process() {
    const auto messages = readNextMessagesBatch(processBatchSize);
}
