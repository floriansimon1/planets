#include "./handlers/pong-handler.hpp"
#include "../network/message-types.hpp"
#include "./client-message-handlers-list.hpp"
#include "./handlers/connection-response-handler.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> clientHandlers() {
    std::map<MessageType, std::shared_ptr<MessageHandler>> handlers;

    handlers[CONNECTION_RESPONSE] = std::shared_ptr<MessageHandler>(new ConnectionResponseHandler());
    handlers[PING]                = std::shared_ptr<MessageHandler>(new PongHandler());

    return handlers;
}
