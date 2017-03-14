#include "./states/serve-game.hpp"
#include "./server-application.hpp"

ServerApplication::ServerApplication(): Application(serverCommunicator) {
    addStep(std::make_shared<ServeGame>());

    start();
}
