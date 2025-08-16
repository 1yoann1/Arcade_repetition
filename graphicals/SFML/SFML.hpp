#ifndef SFML_HPP
#define SFML_HPP

#include "../include/IGraphic.hpp"
#include <SFML/Graphics.hpp>

class SFML : public IDisplayModule {
public:
    void init() override;
    void stop() override;
    Input getInput() override;
private:
};

#endif
