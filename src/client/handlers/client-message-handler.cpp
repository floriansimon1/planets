#include "./client-message-handler.hpp"

void ClientMessageHandler::handle(Application &application, Message &message) const {
    doHandle(static_cast<ClientApplication&>(application), message);
}
