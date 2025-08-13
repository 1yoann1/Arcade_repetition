#include "../include/IGame.hpp"

class Pacman : public IGame {
public:
    void init() override;
    void score() override;
    void stop() override;
private:
};