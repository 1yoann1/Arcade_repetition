#ifndef IDISPLAY_MODULE
#define IDISPLAY_MODULE

#include <string>
#include <iostream>

class IDisplayModule {
public :
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual const std::string &getName() const = 0;
};

#endif