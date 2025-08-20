#include "../src/graphicals/SFML/SFML.hpp"

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
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) return Input::QUIT;
        if (event.type == sf::Event::KeyPressed) {
            switch(event.key.code) {
                case sf::Keyboard::Up    : return Input::UP;
                case sf::Keyboard::Down  : return Input::DOWN;
                case sf::Keyboard::Left  : return Input::LEFT;
                case sf::Keyboard::Right : return Input::RIGHT;
                case sf::Keyboard::Q     : return Input::QUIT;
                case sf::Keyboard::R     : return Input::REFRESH;
                case sf::Keyboard::N     : return Input::NEXT_LIB;
                case sf::Keyboard::P     : return Input::PREV_LIB;
                case sf::Keyboard::G     : return Input::NEXT_GAME;
                case sf::Keyboard::B     : return Input::PREV_GAME;
                default                  : break;
            }
        }
    }
    return Input::NONE;
}

void SfmlDisplay::display(const std::vector<std::string> &map)
{
    for (size_t y = 0; y < map.size(); y++) {
        for (size_t x = 0; x < map[y].size(); x++) {
            char c = map[y][x];

            sf::Color color;
            switch(c) {
                case '#' : color = sf::Color::White;
                           break;
                case 'O' : color = sf::Color::Green;
                           break;
                case 'C' : color = sf::Color::Red;
                           break;
                case '*' : color = sf::Color::Yellow;
                           break;
            }
            sf::RectangleShape shape(sf::Vector2f(CELL_SIZE - 1.0f, CELL_SIZE - 1.0f));
            shape.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            shape.setFillColor(color);
            window->draw(shape);
        }
    }
    window->display();
}

void SfmlDisplay::clear()
{
    window->clear(sf::Color::Black);
}

extern "C" IDisplayModule* create_lib() {
    return new SfmlDisplay();
}