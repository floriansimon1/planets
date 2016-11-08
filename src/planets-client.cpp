#include <vector>
#include <cstdlib>
#include <unistd.h>

#include <SFML/Graphics.hpp>

#include "./network/hosted-game.hpp"
#include "./graphics/renderer.hpp"
#include "./network/client.hpp"
#include "./io/controller.hpp"

int main(void) {
    World            world;
    Client           client;
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

    std::vector<std::shared_ptr<HostedGame>> games;

    while (true) {
        sleep(1);

        client.updateAvailableGamesList(games);
    }

    return EXIT_SUCCESS;
}
