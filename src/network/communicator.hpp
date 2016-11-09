#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <SFML/Network.hpp>

#include "./message-queue.hpp"

struct Communicator {
    MessageQueue  messageQueue;
    sf::UdpSocket socket;

    void process();

    private:
        std::vector<Message> readNextMessagesBatch(unsigned int batchSize);
};

#endif
