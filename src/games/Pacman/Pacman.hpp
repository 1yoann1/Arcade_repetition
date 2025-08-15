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

    std::vector<std::string> movePlayer();
    std::vector<std::string> enemyMove();
    void checkCollision();
    void placeFood();
    std::vector<std::string> handleInput(Input input);
    std::vector<std::string> refresh();
private:
    Input currentDirection;
    Input currentEDirection;
    std::vector<std::string> mapData;
    std::deque<Position> player;
    std::deque<Position> enemyPlayer;
    foodPosition food;
    int playerXstart, playerYstart;
    int enemyXstart, enemyYstart;
    int HEIGHT, WIDTH;
    int scores;
    bool hasEaten = false;
};