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
    if (hasEaten = true) {
        scores += 10;
    }
}

void Nibbler::handleInput(Input input)
{
    if (input == Input::UP && currentDirection != Input::DOWN) currentDirection = Input::UP;
    else if (input == Input::DOWN && currentDirection != Input::UP) currentDirection = Input::DOWN;
    else if (input == Input::RIGHT && currentDirection != Input::LEFT) currentDirection = Input::RIGHT;
    else if (input == Input::LEFT && currentDirection != Input::RIGHT) currentDirection = Input::LEFT;

    //Dans ton enum ajoute une input pour le refress
    //Gère le cas par défaut (else) parce quand dans un nibbler on a bas toujours besoin d'appuyer pour que le serpent se déplace
    //Si il s'agit d'une input de dépalceùent
        //call  move
    //S'il s'agit d'une input de refresh ou de pause ou de menu

    //Ta fonction handle Input décide la fonction à appeler et retourne la map
}

void Nibbler::move()
{
    Position currentHead = snake.front();
    int snakeHeadX = currentHead.x;
    int snakeHeadY = currentHead.y;
    char s = 'O';

    if (currentDirection == Input::UP) snakeHeadY--;
    else if (currentDirection == Input::DOWN) snakeHeadY++;
    else if (currentDirection == Input::RIGHT) snakeHeadX++;
    else if (currentDirection == Input::LEFT) snakeHeadX--;

    snake.push_front({snakeHeadX, snakeHeadY});
    if (!hasEaten) {
        Position tail = snake.back();
        mapData[tail.x][tail.y] = ' ';
        snake.pop_back();
    } else {
        hasEaten = false;
    }
    mapData[snakeHeadY][snakeHeadX] = s;
    checkCollision();   
    //Vu que tu places le joueur et son corps dans la map
    //Tu n'auras plus besoin d'envoyer la position du player au core
    //Ta fonction move doit retourner la map
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
        mapData[food.foodX][food.foodY] = ' ';
        //Ici lorsqu'il bouffe appelle ta fonction placeFood pour regenérer automatiquement autre food
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

void Nibbler::update(int input) {
    //appeler le handle input

    //Ensuite vu que les fonctions que handle input gère retournent la map
    //Ta fonction update aussi doit retourner la map
}

