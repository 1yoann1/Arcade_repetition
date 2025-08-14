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

    currentDirection = Input::RIGHT;
    scores = 0;

    for (int i = 0; i <= 7; i++) {
        placeFood();
    }
}

void Nibbler::stop() 
{   
}

void Nibbler::score()
{
}

void Nibbler::handleInput(Input input)
{
    if (input == Input::UP && currentDirection != Input::DOWN) currentDirection = Input::UP;
    else if (input == Input::DOWN && currentDirection != Input::UP) currentDirection = Input::DOWN;
    else if (input == Input::RIGHT && currentDirection != Input::LEFT) currentDirection = Input::RIGHT;
    else if (input == Input::LEFT && currentDirection != Input::RIGHT) currentDirection = Input::LEFT;
}

void Nibbler::move()
{
}

void Nibbler::checkCollision()
{
    Position currentHead = snake.front();
    int snakeHeadX = currentHead.x;
    int snakeHeadY = currentHead.y;

    if (mapData[snakeHeadX][snakeHeadY] == '#') {
        return;
    }

    for (size_t i = 1; snake.size();  i++) {
        if (snakeHeadX == snake[i].x && snakeHeadY == snake[i].y) {
            stop();
            return;
        }
    }
}

void Nibbler::placeFood()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(1, WIDTH - 1);
    std::uniform_int_distribution<> distribY(1, HEIGHT - 1);

    foodPosition food;
    //int foodX, foodY;
    do {
        food.foodX = distribX(gen);
        food.foodY = distribY(gen);
    } while (mapData[food.foodY][food.foodX] != ' ');
    
    mapData[food.foodX][food.foodY] = '*';
}
