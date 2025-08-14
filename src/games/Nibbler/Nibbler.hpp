#include "../include/IGame.hpp"

enum class Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    REfRESH
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
    void handleInput(Input input);
private:
    Input currentDirection;
    std::vector<std::string> mapData;
    int HEIGHT, WIDTH;
    int snakeXstart, snakeYstart;
    std::deque<Position> snake;
    foodPosition food;
    bool hasEaten = false;
    sf:Clock clock;
    sf::Time speed = sf::milliseconds(200);
    int speed = 150;
    int scores;
    bool refresh;
    //int food;
};

