#include "./client-message-handlers-list.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> clientHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    return handlers;
}
