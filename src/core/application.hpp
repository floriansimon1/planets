#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <stack>

#include "./state.hpp"
#include "../network/communicator.hpp"

struct Application {
    Application(Communicator &communicator);

    Communicator &communicator;

    void run();
    void finishStep();
    bool shouldExit() const;
    void addStep(std::shared_ptr<State> step);
    std::shared_ptr<State> getCurrentStep() const;
    void replaceCurrentStep(std::shared_ptr<State> step);

    protected:
        std::stack<std::shared_ptr<State>> stepStack;
};

#endif
