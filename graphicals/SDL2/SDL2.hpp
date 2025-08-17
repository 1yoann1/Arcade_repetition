#ifndef SDL2_HPP
#define SDL2_HPP

#include "../include/IGraphic.hpp"
#include <SDL2/SDL.h>

class SDL2Display : public IDisplayModule {
public:
    void init() override;
    void stop() override;
    Input getInput() override;
private:
};

#endif
