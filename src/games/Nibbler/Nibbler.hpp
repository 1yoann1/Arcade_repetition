#include "../include/IGame.hpp"

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    REFRESH,
    NONE
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
    void update(Input input) override;

    std::vector<std::string> move();
    void checkCollision();
    void placeFood();
    std::vector<std::string> handleInput(Input input);
    std::vector<std::string> refresh();
private:
    Input currentDirection;
    std::vector<std::string> mapData;
    int HEIGHT, WIDTH;
    int snakeXstart, snakeYstart;
    std::deque<Position> snake;
    foodPosition food;
    bool hasEaten = false;
    int scores;
    //bool refresh;
    //int food;
};

