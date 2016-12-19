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

void Application::replaceCurrentStep(std::shared_ptr<State> step) {
    finishStep();

    addStep(step);
}

void Application::run() {
    communicator.communicate(*this);

    getCurrentStep()->process(*this);
}

std::shared_ptr<State> Application::getCurrentStep() const {
    return stepStack.top();
}
