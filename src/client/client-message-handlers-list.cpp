#include "./handlers/pong-handler.hpp"
#include "../network/message-types.hpp"
#include "./client-message-handlers-list.hpp"
#include "./handlers/connection-response-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> clientHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[MessageType::ConnectionResponse] = std::make_shared<ConnectionResponseHandler>();
    handlers[MessageType::Ping]               = std::make_shared<PongHandler>();

    return handlers;
}
