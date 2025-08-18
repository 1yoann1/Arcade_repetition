#ifndef IGAME_HPP
#define IGAME_HPP

#include "../include/IGraphic.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <deque>
#include <random>

class IGame {
public:
    virtual ~IGame() = default;
    virtual void init() = 0;
    virtual void score() = 0;
    virtual void stop() = 0;
    virtual void update(Input input) = 0;

    virtual const std::vector<std::string> getMap() const = 0;
    virtual int getScore() const = 0;
    virtual bool isGameOver() const = 0;
};

#endif //IGAME_HPP