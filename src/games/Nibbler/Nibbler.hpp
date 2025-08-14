#include "../include/IGame.hpp"

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct foodPosition {
    int foodX, foodY;
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
    void handleInput(Input input);
private:
    Input currentDirection;
    std::vector<std::string> mapData;
    int HEIGHT, WIDTH;
    int snakeXstart, snakeYstart;
    std::deque<Position> snake;
    foodPosition food;
    bool hasEaten = false;
    int scores;
    //int food;
};
