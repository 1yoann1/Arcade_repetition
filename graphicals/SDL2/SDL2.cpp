#include "../graphicals/SDL2.hpp"

void SDL2Display::init()
{
}

void SDL2Display::stop()
{
}

Input SDL2Display::getInput()
{
}

extern "C" IDisplayModule* create_dipsplay() {
    return new SLD2Display();
}