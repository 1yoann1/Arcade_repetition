#include "../src/games/Pacman/Pacman.hpp"

void Pacman::init()
{
    mapData = {
        "###########################################",
        "#                                         #",
        "#   #######     #############   #######   #",
        "#                                         #",
        "#####   #   #        ###         #####  ###",
        "#       #   #   #           #             #",
        "#   #           #           #   #   #     #",
        "#   ###   ###   #           #   #      ####",
        "#         #     # # # # # # #   #         #",
        "#   #                           #    #    #",
        "#   ######      #############   #    #  ###",
        "#                                    #    #",
        "#   ###      ###########             #    #",
        "#                #          #             #",
        "###########################################"
    };
    HEIGHT = mapData.size();
    WIDTH =  mapData[0].size();

    playerXstart = WIDTH / 2;
    playerYstart = HEIGHT - 14;

    player.push_front({playerXstart, playerYstart});

    Position pos;
    mapData[pos.y][pos.x] = 'O';
    currentDirection = Input::RIGHT;
    scores = 0;

    for (int i = 0; i <= 10; i++) {
        placeFood();
    }
}

std::vector<std::string> Pacman::handleInput(Input input)
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
    return movePlayer(); 
}

void Pacman::stop()
{
}

void Pacman::score()
{
    if (hasEaten == true) {
        scores += 10;
    }
}

std::vector<std::string> Pacman::movePlayer()
{
    Position currentHead = player.front();
    int playerHeadX = currentHead.x;
    int playerHeadY = currentHead.y;
    char s = 'O';

    if (currentDirection == Input::UP)
        playerHeadY--;
    else if (currentDirection == Input::DOWN)
        playerHeadY++;
    else if (currentDirection == Input::RIGHT)
        playerHeadX++;
    else if (currentDirection == Input::LEFT)
        playerHeadX--;

    player.push_front({playerHeadX, playerHeadY});
    if (!hasEaten) {
        score();
    } else {
        hasEaten = false;
    }
    mapData[playerHeadY][playerHeadX] = s;
    checkCollision();   
    return mapData;
}

void Pacman::checkCollision()
{
    Position currentHead = player.front();
    int playerHeadX = currentHead.x;
    int playerHeadY = currentHead.y;

    if (mapData[playerHeadY][playerHeadX] == '#') {
        return;
    }

    //collision with ennemi players

    if (playerHeadX == food.foodX && playerHeadY == food.foodY) {
        hasEaten = true;
        mapData[food.foodY][food.foodX] = ' ';
        scores += 1;
        placeFood();
    }
}

void Pacman::placeFood()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(1, WIDTH - 1);
    std::uniform_int_distribution<> distribY(1, HEIGHT - 1);

    do {
        food.foodX = distribX(gen);
        food.foodY = distribY(gen);
    } while (mapData[food.foodY][food.foodX] != ' ');

    mapData[food.foodY][food.foodX] = '*';
}

std::vector<std::string> Pacman::refresh()
{
}

void Pacman::update(Input input)
{
}