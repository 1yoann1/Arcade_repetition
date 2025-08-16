#ifndef IDISPLAY_MODULE
#define IDISPLAY_MODULE

#include <string>
#include <iostream>

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    REFRESH,
    NONE
};

class IDisplayModule {
public :
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual std::vector<std::string> getInput() = 0;
};

#endif