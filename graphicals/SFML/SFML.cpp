#include "../graphicals/SFML.hpp"

void SfmlDisplay::init()
{
}

void SfmlDisplay::stop()
{
}

Input SfmlDisplay::getInput()
{
}

void SfmlDisplay::display(std::vector<std::string> &map)
{
}

void SfmlDisplay::clear()
{
}

extern "C" IDisplayModule* create_dipsplay() {
    return new SfmlDisplay();
}