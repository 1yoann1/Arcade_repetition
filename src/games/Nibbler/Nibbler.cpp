#include "../src/games/Nibbler/Nibbler.hpp"

void Nibbler::init()
{
    mapData = {
        "########################################",
        "#             #                        #",
        "#   #######   #   ###########   ####   #",
        "#   #             #         #          #",
        "#   #   #   #######   ###   ########   #",
        "#       #                  #          ##",
        "#                   #                 ##",
        "### ########## ### ##############   ####",
        "#                        #             #",
        "#                   #                 ##",
        "#   ######               #######       #",
        "#        #                            ##",
        "#        #                            ##",
        "########################################"
    };
    HEIGHT = mapData.size();
    WIDTH = mapData[0].size();

    snakeXstart = WIDTH / 2;
    snakeYstart = HEIGHT - 2;

    snake.push_front({snakeXstart, snakeYstart});
    snake.push_front({snakeXstart - 1, snakeYstart});
    snake.push_front({snakeXstart - 2, snakeYstart});
    snake.push_front({snakeXstart - 3, snakeYstart});

    for (Position pos: snake) {
        mapData[pos.y][pos.x] = 'O';
    }

    currentDirection = Input::RIGHT;
    scores = 0;

    for (int i = 0; i < 10; i++) {
        placeFood();
    }
}

void Nibbler::stop() 
{   
}

void Nibbler::score()
{
    if (hasEaten == true) {
        scores += 10;
    }
}

std::vector<std::string> Nibbler::handleInput(Input input)
{
    if (input == Input::UP && currentDirection != Input::DOWN)
        currentDirection = Input::UP;
    else if (input == Input::DOWN && currentDirection != Input::UP)
        currentDirection = Input::DOWN;
    else if (input == Input::RIGHT && currentDirection != Input::LEFT)
        currentDirection = Input::RIGHT;
    else if (input == Input::LEFT && currentDirection != Input::RIGHT)
        currentDirection = Input::LEFT;
    else if (input == Input::REFRESH) {
        return refresh();
    }
    return move(); 
}

std::vector<std::string> Nibbler::move()
{
    Position currentHead = snake.front();
    int snakeHeadX = currentHead.x;
    int snakeHeadY = currentHead.y;
    char s = 'O';

    if (currentDirection == Input::UP)
        snakeHeadY--;
    else if (currentDirection == Input::DOWN)
        snakeHeadY++;
    else if (currentDirection == Input::RIGHT)
        snakeHeadX++;
    else if (currentDirection == Input::LEFT)
        snakeHeadX--;

    snake.push_front({snakeHeadX, snakeHeadY});
    if (!hasEaten) {
        Position tail = snake.back();
        mapData[tail.y][tail.x] = ' ';
        snake.pop_back();
    } else {
        hasEaten = false;
    }
    mapData[snakeHeadY][snakeHeadX] = s;
    checkCollision();   
    return mapData;
}

void Nibbler::checkCollision()
{
    Position currentHead = snake.front();
    int snakeHeadX = currentHead.x;
    int snakeHeadY = currentHead.y;

    if (mapData[snakeHeadY][snakeHeadX] == '#') {
        return;
    }

    for (size_t i = 1; i < snake.size();  i++) {
        if (snakeHeadX == snake[i].x && snakeHeadY == snake[i].y) {
            stop();
            return;
        }
    }

    int i = 0;
    if (snakeHeadX == food.foodX && snakeHeadY == food.foodY) {
        hasEaten = true;
        mapData[food.foodY][food.foodX] = ' ';
        scores += 1;
        placeFood();
    }
}

void Nibbler::placeFood()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(1, WIDTH - 1);
    std::uniform_int_distribution<> distribY(1, HEIGHT - 1);

    //int foodX, foodY;
    do {
        food.foodX = distribX(gen);
        food.foodY = distribY(gen);
    } while (mapData[food.foodY][food.foodX] != ' ');

    mapData[food.foodY][food.foodX] = '*';
}

std::vector<std::string> Nibbler::refresh()
{
    scores = 0;
    snake.clear();
    snakeXstart = WIDTH / 2;
    snakeYstart = HEIGHT - 2;

    snake.push_front({snakeXstart, snakeYstart});
    snake.push_front({snakeXstart - 1, snakeYstart});
    snake.push_front({snakeXstart - 2, snakeYstart});
    snake.push_front({snakeXstart - 3, snakeYstart});

    for (Position pos: snake) {
        mapData[pos.y][pos.x] = 'O';
    }

    currentDirection = Input::RIGHT;

    return mapData;
}

void Nibbler::update(Input input)
{
    if (input != Input::NONE) {
        handleInput(input);
    }
    move();
}


