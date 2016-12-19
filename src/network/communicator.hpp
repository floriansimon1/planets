#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <SFML/Network.hpp>
#include <memory>
#include <map>

#include "./message-queue.hpp"
#include "./message-types.hpp"
#include "./message-handler.hpp"
#include "./outgoing-message.hpp"

struct Communicator {
    std::map<MessageType, std::shared_ptr<MessageHandler>> messageHandlers;
    MessageQueue                                           messageQueue;
    sf::UdpSocket                                          socket;

    void communicate(Application &application);
    sf::Socket::Status send(OutgoingMessage &message);

    Communicator(const std::map<MessageType, std::shared_ptr<MessageHandler>> handlers): messageHandlers(handlers) {}
    virtual ~Communicator() {}

    private:
        std::vector<Message> readNextMessagesBatch(unsigned int batchSize);
        void  processNextMessagesBatch(Application &application, unsigned int batchSize);
};

#endif
