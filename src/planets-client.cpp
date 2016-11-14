#include <vector>
#include <cstdlib>
#include <unistd.h>

#include <SFML/Graphics.hpp>

#include "./client/messages/get-current-tick-request.hpp"
#include "./client/client-communicator.hpp"
#include "./client/client-state.hpp"
#include "./graphics/renderer.hpp"
#include "./input/controller.hpp"
#include "./network/host.hpp"

int main(void) {
    ClientState        state;
    ClientCommunicator communicator;

    state.name = "Paul";
    //sf::RenderWindow window(sf::VideoMode(900, 900), "Planets");

    /*Controller controller(world.players[0]);
    Renderer   renderer(window);

    std::vector<Controller*> controllers;

    controllers.push_back(&controller);

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (
                event.type == sf::Event::KeyPressed
                && event.key.code == sf::Keyboard::Escape
            ) {
                window.close();
            }
        }

        world.makeNextFrame(controllers);

        renderer.render(world);
    }*/

    std::vector<std::shared_ptr<Host>> games;

    bool gameJoined = false;

    while (true) {
        sleep(1);

        if (!gameJoined) {
            communicator.updateAvailableGamesList(games);

            if (games.size() > 0) {
                gameJoined = true;

                communicator.joinGame(*games[0], state.name);
            }
        } else {
            GetCurrentTickRequest request(*games[0]);

            communicator.send(request);
        }
    }



    return EXIT_SUCCESS;
}
