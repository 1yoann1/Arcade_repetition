#ifndef SDL2_HPP
#define SDL2_HPP

#include "../include/IGraphic.hpp"
#include <SDL2/SDL.h>

class Sdl2Display : public IDisplayModule {
public:
    void init() override;
    void stop() override;
    Input getInput() override;
    void display(const std::vector<std::string> &map) override;

    void clear() override;
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;
    const int CELL_SIZE = 20;
};

#endif
