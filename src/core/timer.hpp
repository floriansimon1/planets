#ifndef TIMER_HPP
#define TIMER_HPP

#include <SFML/System.hpp>

struct TimerNotStartedError {};

struct Timer {
    void     start();
    sf::Time stop();
    sf::Time peek();

    bool started = false;

    private:
        sf::Clock clock;
};

#endif
