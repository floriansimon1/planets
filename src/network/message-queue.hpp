#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <queue>

#include "./message.hpp"

struct MessageQueue {
    void appendMessages(const std::vector<Message> &newMessages);

    Message nextMessage();

    bool isEmpty();

    private:
        std::queue<Message> queue;
};

#endif
