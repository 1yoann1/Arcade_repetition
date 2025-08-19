#include "../src/graphicals/SDL2/SDL2.hpp"

void Sdl2Display::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("ARCADE SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 700, 0);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Sdl2Display::stop()
{
    if (render) {
        SDL_DestroyRenderer(render);
        render = nullptr;
    }
    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

Input Sdl2Display::getInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) return Input::QUIT;
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_UP    : return Input::UP;
                case SDLK_DOWN  : return Input::DOWN;
                case SDLK_LEFT  : return Input::LEFT;
                case SDLK_RIGHT : return Input::RIGHT;
                case SDLK_q     : return Input::QUIT;
                case SDLK_r     : return Input::REFRESH;
            }
        }
    }
    return Input::NONE;
}

void Sdl2Display::display(const std::vector<std::string> &map)
{
    for (size_t y = 0; y < map.size(); y++) {
        for (size_t x = 0; x < map[y].size(); x++) {
            char c = map[y][x];

            switch(c) {
                case '#' : SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
                           break;
                case 'O' : SDL_SetRenderDrawColor(render, 0, 150, 0, 225);
                           break;
                case 'C' : SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
                           break;
                case '*' : SDL_SetRenderDrawColor(render, 255, 255, 0, 255);
                           break;
                default  : continue;
            }
            SDL_Rect rect;
            rect.x = x * CELL_SIZE;
            rect.y = y * CELL_SIZE;
            rect.w = CELL_SIZE;
            rect.h = CELL_SIZE;
            
            SDL_RenderFillRect(render, &rect);
        }
    }
    SDL_RenderPresent(render);
}

void Sdl2Display::clear()
{
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderClear(render);
}

extern "C" IDisplayModule* create_display() {
    return new Sdl2Display();
}