#include "./message-queue.hpp"

void MessageQueue::appendMessages(const std::vector<Message> &newMessages) {
    for (const auto message : newMessages) {
        queue.push(message);
    }
}

Message MessageQueue::nextMessage() {
    const auto nextMessage = queue.front();

    queue.pop();

    return nextMessage;
}

bool MessageQueue::isEmpty() {
    return queue.empty();
}
