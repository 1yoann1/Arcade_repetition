#include "../include/IGame.hpp"

class Nibbler : public IGame {
public:
    void init() override;
    void score() override;
    void stop() override;
private:
    std::vector<std::string> mapData;
    int HEIGHT, WIDTH;
};
