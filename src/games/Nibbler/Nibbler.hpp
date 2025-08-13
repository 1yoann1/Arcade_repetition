#include "../include/IGame.hpp"

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Position {
    int x, y;
};

class Nibbler : public IGame {
public:
    void init() override;
    void score() override;
    void stop() override;

    void move();
    void checkCollision();
    void placeFood();
private:
    Input currentDirection;
    std::vector<std::string> mapData;
    int HEIGHT, WIDTH;
    int snakeXstart, snakeYstart;
    std::deque<Position> snake;
    int scores;
    int food;
};
