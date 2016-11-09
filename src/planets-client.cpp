#include <vector>
#include <cstdlib>
#include <unistd.h>

#include <SFML/Graphics.hpp>

#include "./network/client-communicator.hpp"
#include "./graphics/renderer.hpp"
#include "./io/controller.hpp"
#include "./network/host.hpp"

int main(void) {
    World              world;
    ClientCommunicator client;
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

    std::shared_ptr<Host> game = nullptr;

    while (true) {
        sleep(1);

        if (!game) {
            client.updateAvailableGamesList(games);

            if (games.size() > 0) {
                game = games[0];
            }
        } else {
            client.joinGame(*game, "Paul");

            break;
        }
    }

    return EXIT_SUCCESS;
}
