#include "../include/IGame.hpp"

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

    //std::vector<std::string> move();
    void move();
    void checkCollision();
    void placeFood();
    void handleInput(Input input);
    //std::vector<std::string> handleInput(Input input);
    std::vector<std::string> refresh();

    std::vector<std::string> getMap() const override {
         return mapData;
    }
    int getScore() const override {
         return scores;
    }
    bool isGameOver() const override { return gameOver; }

private:
    Input currentDirection;
    std::vector<std::string> mapData;
    int HEIGHT, WIDTH;
    int snakeXstart, snakeYstart;
    std::deque<Position> snake;
    foodPosition food;
    bool hasEaten = false;
    int scores;
    bool gameOver = false;
    //bool refresh;
    //int food;
};

