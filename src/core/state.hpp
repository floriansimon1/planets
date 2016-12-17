#ifndef STATE_HPP
#define STATE_HPP

struct Application;

struct State {
    virtual void process(Application &state) = 0;
};

#endif
