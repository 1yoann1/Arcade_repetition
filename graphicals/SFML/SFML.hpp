#ifndef SFML_HPP
#define SFML_HPP

#include "../include/IGraphic.hpp"
#include <SFML/Graphics.hpp>

class SfmlDisplay : public IDisplayModule {
public:
    void init() override;
    void stop() override;
    Input getInput() override;
    void display(std::vector<std::string> &map) override;

    void clear();
private:
    std::unique_ptr<sf::RenderWindow> window;
};

#endif
