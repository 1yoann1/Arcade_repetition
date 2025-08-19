#ifndef NCURSES_HPP
#define NCURSES_HPP

#include "../include/IGraphic.hpp"
#include <ncurses.h>

class NcursesDisplay : public IDisplayModule {
public:
    void init() override;
    void stop() override;
    Input getInput() override;
    void display(const std::vector<std::string> &map) override;

    void clear() override;
private:
};

#endif
