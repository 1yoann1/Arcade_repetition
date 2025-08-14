#ifndef IGAME_HPP
#define IGAME_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <deque>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class IGame {
public:
    virtual ~IGame() = default;
    virtual void init() = 0;
    virtual void score() = 0;
    virtual void stop() = 0;
    virtual void update(Input input) = 0;
};

#endif //IGAME_HPP