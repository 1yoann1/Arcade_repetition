#include "../graphicals/SFML.hpp"

void SfmlDisplay::init()
{
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 700), "ARCADE SFML", 0);
    window->setFramerateLimit(60);
}

void SfmlDisplay::stop()
{
    if (window) {
        window->close();
    }
}

Input SfmlDisplay::getInput()
{
    sfEvent event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) return Input::QUIT;
        if (event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
                case sf::Keyboard::UP    : return Input::UP;
                case sf::Keyboard::DOWN  : return Input::DOWN;
                case sf::Keyboard::LEFT  : return Input::LEFT;
                case sf::Keyboard::RIGHT : return Input::RIGHT;
                case sf::Keyboard::Q     : return Input::QUIT;
                case sf::Keyboard::R     : return Input::REFRESH;
                default                  : break;
            }
        }
    }
}

void SfmlDisplay::display(std::vector<std::string> &map)
{
}

void SfmlDisplay::clear()
{
    window->clear(sf::Color::Black);
}

extern "C" IDisplayModule* create_dipsplay() {
    return new SfmlDisplay();
}