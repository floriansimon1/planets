#include "./application.hpp"

void Application::finishStep() {
    stepStack.pop();
}

bool Application::shouldExit() {
    return stepStack.empty();
}

void Application::addStep(State &step) {
    stepStack.push(step);
}

void Application::replaceCurrentStep(State &step) {
    finishStep();

    addStep(step);
}

void Application::run() {
    const auto &step = stepStack.top();

    communicator.communicate(*this);

    step.process(*this);
}

State &Application::getCurrentStep() {
    return stepStack.top();
}
