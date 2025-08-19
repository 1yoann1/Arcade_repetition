#include <../src/graphicals/Ncurses/Ncurses.hpp>

void NcursesDisplay::init()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
}

void NcursesDisplay::stop()
{
    endwin();
}

Input NcursesDisplay::getInput()
{
    int ch = getch();
    switch (ch) {
        case KEY_UP    : return Input::UP;
        case KEY_DOWN  : return Input::DOWN;
        case KEY_LEFT  : return Input::LEFT;
        case KEY_RIGHT : return Input::RIGHT;
        case 'q'       : return Input::QUIT;
        case 'r'       : return Input::REFRESH;
        default        : return Input::NONE;
    }
}

void NcursesDisplay::display(const std::vector<std::string> &map)
{
    clear();
    for (size_t i = 0; i < map.size(); i++) {
        mvprintw(i, 0, "%s", map[i].c_str());
    }
    refresh();
}

void NcursesDisplay::clear()
{
    erase();
}

extern "C" IDisplayModule* create_lib() {
    return new NcursesDisplay();
}