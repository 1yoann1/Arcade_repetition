#ifndef SFML_HPP
#define SFML_HPP

#include "../include/IGraphic.hpp"
#include <SFML/Graphics.hpp>

class SfmlDisplay : public IDisplayModule {
public:
    void init() override;
    void stop() override;
    Input getInput() override;
    void display(const std::vector<std::string> &map) override;

    void clear() override;
private:
    std::unique_ptr<sf::RenderWindow> window;
    const float CELL_SIZE = 20.0f;
};

#endif
