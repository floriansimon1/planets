#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <thread>
#include <memory>
#include <stack>

#include "./state.hpp"
#include "../network/communicator.hpp"

// Child classes must call the start method in their constructor.
struct Application {
    Application(Communicator &communicator);

    Communicator &communicator;

    /***********************************************/
    /* METHODS THAT CAN BE CALLED IN OTHER THREADS */
    /***********************************************/

    void requestExit();
    bool shouldExit() const;
    void awaitTermination();

    /******************************/
    /* APPLICATION THREAD METHODS */
    /******************************/

    void finishStep();
    void addStep(std::shared_ptr<State> step);
    std::shared_ptr<State> getCurrentStep() const;
    void replaceCurrentStep(std::shared_ptr<State> step);

    protected:
        virtual void afterApplicationStep();
        void start();

    private:
        std::stack<std::shared_ptr<State>> stepStack;
        std::thread                        applicationThread;
        bool                               hardExitRequested;

        void run();
};

#endif
