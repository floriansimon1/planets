#include "./message-handlers-list.hpp"
#include "./connection-request-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> serverHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[CONNECTION_REQUEST] = std::shared_ptr<MessageHandler>(new ConnectionRequestHandler());

    return handlers;
}
