#include <../graphicals/Ncurses/Ncurses.hpp>

void NibblerDisplay::init()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    start_color();
}

void NibblerDisplay::stop()
{
    endwin();
}

Input NibblerDisplay::getInput()
{
    int ch = getch();
    switch (ch) {
        case KEY_UP:    return Input::UP;
        case KEY_DOWN:  return Input::DOWN;
        case KEY_LEFT:  return Input::LEFT;
        case KEY_RIGHT: return Input::RIGHT;
        case 'r':       return Input::REFRESH;
        break;
    default:
        break;
    }
}

extern "C" IDisplayModule* create_display() {
    return new NibblerDisplay();
}