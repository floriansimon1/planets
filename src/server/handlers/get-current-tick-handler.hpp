#ifndef GET_CURRENT_TICK_HANDLER
#define GET_CURRENT_TICK_HANDLER

#include "../../network/message-handler.hpp"

struct GetCurrentTickHandler: MessageHandler {
    virtual void handle(Communicator *communicator, Message &message, AgentState *state) const;
};

#endif
