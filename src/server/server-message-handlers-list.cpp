#include "./server-message-handlers-list.hpp"
#include "./handlers/get-current-tick-handler.hpp"
#include "./handlers/connection-request-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> serverHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[PING]               = std::shared_ptr<MessageHandler>(new GetCurrentTickHandler());
    handlers[CONNECTION_REQUEST] = std::shared_ptr<MessageHandler>(new ConnectionRequestHandler());

    return handlers;
}
