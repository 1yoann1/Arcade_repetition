#include "../include/IGame.hpp"

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    REFRESH,
    NONE
};

struct Position {
    int x, y;
};

class Pacman : public IGame {
public:
    void init() override;
    void score() override;
    void stop() override;
    void update(Input input) override;

    std::vector<std::string> movePlayer();
    void checkCollision();
    std::vector<std::string> handleInput(Input input);
    std::vector<std::string> refresh();
private:
    Input currentDirection;
    std::vector<std::string> mapData;
    std::deque<Position> player;
    int playerXstart, playerYstart;
    int HEIGHT, WIDTH;
    int scores;
};