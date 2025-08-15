#include "../include/IGame.hpp"

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    REFRESH,
    NONE
};

class Pacman : public IGame {
public:
    void init() override;
    void score() override;
    void stop() override;
private:
};