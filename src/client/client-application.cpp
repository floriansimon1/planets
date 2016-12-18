#include <numeric>
#include <memory>

#include "./client-application.hpp"
#include "./states/searching-games.hpp"

ClientApplication::ClientApplication(): Application(clientCommunicator) {
    stepStack.push(std::shared_ptr<SearchingGames>(new SearchingGames()));
}
