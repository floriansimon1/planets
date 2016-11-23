#include "./server-message-handlers-list.hpp"
#include "./handlers/client-input-handler.hpp"
#include "./handlers/get-current-tick-handler.hpp"
#include "./handlers/connection-request-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> serverHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[CLIENT_INPUT]       = std::shared_ptr<MessageHandler>(new ClientInputHandler());
    handlers[PING]               = std::shared_ptr<MessageHandler>(new GetCurrentTickHandler());
    handlers[CONNECTION_REQUEST] = std::shared_ptr<MessageHandler>(new ConnectionRequestHandler());

    return handlers;
}
