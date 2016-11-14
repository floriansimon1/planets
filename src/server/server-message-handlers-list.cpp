#include "./server-message-handlers-list.hpp"
#include "./handlers/connection-request-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> serverHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[CONNECTION_REQUEST] = std::shared_ptr<MessageHandler>(new ConnectionRequestHandler());

    return handlers;
}
