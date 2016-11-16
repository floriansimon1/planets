#include "./timer.hpp"

void Timer::start() {
    if (started) {
        return;
    }

    started = true;

    clock.restart();
}

sf::Time Timer::stop() {
    sf::Time time = peek();

    started = false;

    return time;
}

sf::Time Timer::peek() {
    if (!started) {
        throw TimerNotStartedError();
    }

    return clock.getElapsedTime();
}
