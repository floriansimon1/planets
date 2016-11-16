#ifndef PONG_HANDLER
#define PONG_HANDLER

#include "../../network/message-handler.hpp"
#include "../../network/communicator.hpp"
#include "../../core/agent-state.hpp"
#include "../../network/message.hpp"

struct PongHandler: MessageHandler {
    virtual void handle(Communicator &communicator, Message &message, AgentState &state) const;
};

#endif
