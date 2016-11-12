#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <SFML/Network.hpp>
#include <memory>
#include <map>

#include "./message-queue.hpp"
#include "./message-types.hpp"
#include "../core/agent-state.hpp"

struct PacketReadError {};

struct MessageHandler;

struct Communicator {
    std::map<MessageType, std::shared_ptr<MessageHandler>> messageHandlers;
    MessageQueue                                           messageQueue;
    sf::UdpSocket                                          socket;

    void process(AgentState *state);

    Communicator(const std::map<MessageType, std::shared_ptr<MessageHandler>> handlers): messageHandlers(handlers) {}

    private:
        std::vector<Message> readNextMessagesBatch(unsigned int batchSize);
        void processNextMessagesBatch(AgentState *state, unsigned int batchSize);
};

#endif
