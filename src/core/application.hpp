#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <stack>

#include "./state.hpp"
#include "../network/communicator.hpp"

struct Application {
    Communicator &communicator;

    void run();
    void finishStep();
    bool shouldExit();
    State &getCurrentStep();
    void addStep(State &step);
    void replaceCurrentStep(State &step);

    protected:
        std::stack<State> stepStack;
};

#endif
