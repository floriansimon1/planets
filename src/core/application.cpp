#include "./application.hpp"

Application::Application(Communicator &c): communicator(c) {
}

void Application::finishStep() {
    stepStack.pop();
}

bool Application::shouldExit() const {
    return stepStack.empty();
}

void Application::addStep(std::shared_ptr<State> step) {
    stepStack.push(step);
}

void Application::requestExit() {
    hardExitRequested = true;

    awaitTermination();
}

void Application::replaceCurrentStep(std::shared_ptr<State> step) {
    finishStep();

    addStep(step);
}

void Application::awaitTermination() {
    if (std::this_thread::get_id() != applicationThread.get_id()) {
        applicationThread.join();
    }
}

void Application::run() {
    // Network I/O.
    communicator.communicate(*this);

    // Game logic.
    getCurrentStep()->process(*this);

    // Application-dependent post actions.
    afterApplicationStep();

    // Something requested an exit.
    if (hardExitRequested) {
        while (!shouldExit()) {
            finishStep();
        }
    }

    // Recursion optimized via TCO.
    if (!shouldExit()) {
        run();
    }
}

void Application::start() {
    applicationThread = std::thread(&Application::run, this);
}

std::shared_ptr<State> Application::getCurrentStep() const {
    return stepStack.top();
}
