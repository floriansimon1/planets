#include <numeric>
#include <memory>

#include "./client-application.hpp"
#include "./states/searching-games.hpp"

ClientApplication::ClientApplication(sf::RenderWindow &w):
    Application(clientCommunicator),
    window(w),
    renderer(w),
    localPlayerName("Paul")
{
    addStep(std::make_shared<SearchingGames>());

    start();
}
