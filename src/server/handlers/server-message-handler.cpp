#include "./server-message-handler.hpp"

void ServerMessageHandler::handle(Application &application, Message &message) const {
    doHandle(static_cast<ServerApplication&>(application), message);
}
