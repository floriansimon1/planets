#include "./server-message-handlers-list.hpp"
#include "./handlers/client-input-handler.hpp"
#include "./handlers/get-current-tick-handler.hpp"
#include "./handlers/connection-request-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> serverHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[CLIENT_INPUT]       = std::make_shared<ClientInputHandler>();
    handlers[PING]               = std::make_shared<GetCurrentTickHandler>();
    handlers[CONNECTION_REQUEST] = std::make_shared<ConnectionRequestHandler>();

    return handlers;
}
