#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>

#include "./client/client-communicator.hpp"
#include "./client/client-state.hpp"
#include "./core/client-status.hpp"
#include "./graphics/renderer.hpp"

int main(void) {
    ClientState        state;
    ClientCommunicator communicator;

    sf::RenderWindow window(sf::VideoMode(900, 900), "Planets");

    Renderer renderer(window);

    state.name = "Paul";

    window.setFramerateLimit(200);

    std::cout << ">> PLANETS (client)" << std::endl;

    while (state.status != EXIT && window.isOpen()) {
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

        state.process();

        renderer.render(state.world);

        communicator.converse(state);
    }

    return EXIT_SUCCESS;
}
