#ifndef CLIENT_APPLICATION_HPP
#define CLIENT_APPLICATION_HPP

#include <string>
#include <thread>
#include <SFML/Graphics.hpp>

#include "../core/application.hpp"
#include "../graphics/renderer.hpp"
#include "./client-communicator.hpp"

struct ClientApplication: Application {
    sf::RenderWindow &window;
    Renderer         renderer;
    std::string      localPlayerName;

    ClientApplication(sf::RenderWindow &window);

    /*
    * Used to avoid pointers when calling the application constructor
    * and annoying casting in game logic code. clientCommunicator and
    * communicator are the same object, with different type info.
    */
    ClientCommunicator clientCommunicator;
};

#endif
