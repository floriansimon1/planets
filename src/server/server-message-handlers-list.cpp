#include "./server-message-handlers-list.hpp"
#include "./handlers/client-input-handler.hpp"
#include "./handlers/get-current-tick-handler.hpp"
#include "./handlers/connection-request-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> serverHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[MessageType::ClientInput]       = std::make_shared<ClientInputHandler>();
    handlers[MessageType::Ping]              = std::make_shared<GetCurrentTickHandler>();
    handlers[MessageType::ConnectionRequest] = std::make_shared<ConnectionRequestHandler>();

    return handlers;
}
