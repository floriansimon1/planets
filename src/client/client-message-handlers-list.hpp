#ifndef CLIENT_MESSAGE_HANDLER_LIST_HPP
#define CLIENT_MESSAGE_HANDLER_LIST_HPP

#include <map>
#include <memory>
#include <SFML/System.hpp>

#include "../network/message-handler.hpp"
#include "../network/message-types.hpp"

std::map<MessageType, std::shared_ptr<MessageHandler>> clientHandlers();

#endif
