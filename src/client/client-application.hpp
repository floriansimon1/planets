#ifndef CLIENT_APPLICATION_HPP
#define CLIENT_APPLICATION_HPP

#include <experimental/optional>
#include <string>

#include "../core/world.hpp"
#include "../core/timer.hpp"
#include "./input-history.hpp"
#include "../network/host.hpp"
#include "../input/gamepad.hpp"
#include "../core/application.hpp"
#include "../input/controller-state.hpp"

struct ClientApplication: Application {
    InputHistory                             inputHistory;
    World                                    serverWorld;
    Gamepad                                  gamepad;
    World                                    world;
    std::experimental::optional<Host>        game;
    std::string                              name;

    sf::Int32 getServerTimestamp() const;

    // Advances the game simulation.
    void process();

    ClientApplication();

    private:
        void processInputHistory(Id from);
};

#endif
