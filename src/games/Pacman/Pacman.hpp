#include "../include/IGame.hpp"

struct foodPosition {
    int foodX, foodY;
};

struct enemyPosition {
    int eneX, eneY;
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

    void movePlayer();
    void enemyMove();
    void checkCollision();
    void placeFood();
    void handleInput(Input input);
    void refresh();

    const std::vector<std::string> getMap() const override { return mapData; }
    int getScore() const override { return scores; }
    bool isGameOver() const override { return gameOver; }
private:
    Input currentDirection;
    Input currentEDirection;
    std::vector<std::string> mapData;
    std::deque<Position> player;
    //std::deque<Position> enemyPlayer;
    //std::deque<Position> enemyPlayer1;
    std::deque<Position> enemies;
    foodPosition food;
    int playerXstart, playerYstart;
    int enemyXstart, enemyYstart;
    int enemyXstart1, enemyYstart1;
    int HEIGHT, WIDTH;
    int scores;
    bool hasEaten = false;
    bool gameOver = false;
};