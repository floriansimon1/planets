#include "./application.hpp"

Application::Application(Communicator &c): communicator(c) {
}

void Application::finishStep() {
    stepStack.pop();
}

bool Application::shouldExit() {
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
    auto &step = getCurrentStep();

    communicator.communicate(*this);

    step.process(*this);
}

State &Application::getCurrentStep() {
    return *stepStack.top();
}
