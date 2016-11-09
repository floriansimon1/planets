#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <vector>

#include "./message.hpp"

struct MessageQueue {
    void appendMessages(std::vector<Message> &newMessages);

    private:
        std::vector<Message> queue;
};

#endif
