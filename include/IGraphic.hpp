#ifndef IGRAPHIC_HPP
#define IGRAPHIC_HPP

#include <string>
#include <iostream>

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    REFRESH,
    NONE,
    QUIT
};

class IDisplayModule {
public :
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual Input getInput() = 0;
    virtual void display(const std::vector<std::string> &map) = 0;
    virtual void clear() = 0;
};

#endif