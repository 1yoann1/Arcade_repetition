#ifndef IGAME_HPP
#define IGAME_HPP

#include <string>
#include <algorithm>
#include <vector>

class IGame {
public:
    virtual ~IGame() = default;
    virtual void init() = 0;
    virtual void score() = 0;
    virtual void stop() = 0;
};

#endif //IGAME_HPP