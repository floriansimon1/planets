#include "./states/serve-game.hpp"
#include "./server-application.hpp"

ServerApplication::ServerApplication(): Application(serverCommunicator) {
    stepStack.push(std::make_shared<ServeGame>());
}
