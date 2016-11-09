#include "./message-queue.hpp"

void MessageQueue::appendMessages(std::vector<Message> &newMessages) {
    for (const auto message : newMessages) {
        queue.push_back(message);
    }
}
