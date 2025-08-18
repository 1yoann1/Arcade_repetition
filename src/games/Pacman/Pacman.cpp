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

    enemyXstart = WIDTH / 2;
    enemyYstart = HEIGHT - 9;

    enemyXstart1 = (WIDTH / 2) - 2;
    enemyYstart1 = HEIGHT - 9;
    player.push_front({playerXstart, playerYstart});
    mapData[playerYstart][playerXstart] = 'O';
    //enemyPlayer.push_front({enemyXstart, enemyYstart});
    //enemyPlayer1.push_front({enemyXstart1, enemyYstart1});
    enemies.push_front({enemyXstart, enemyYstart});
    enemies.push_front({enemyYstart1, enemyYstart1});
    for (auto &e : enemies) {
        mapData[e.y][e.x] = 'C';
    }

    //Position pos, enemyPos;
    //mapData[pos.y][pos.x] = 'O';
    //mapData[enemyPos.y][enemyPos.x] = 'C';
    //mapData[playerYstart][playerXstart] = 'O';
    //mapData[enemyYstart][enemyXstart] = 'C';
    //mapData[enemyYstart1][enemyXstart1] = 'C';
    currentDirection = Input::RIGHT;
    //currentEDirection = Input::UP;
    scores = 0;

    for (int i = 0; i < 10; i++) {
        placeFood();
    }
}

void Pacman::handleInput(Input input)
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
        refresh();
    }
    //return movePlayer(); 
}

void Pacman::stop()
{
    gameOver = true;
}

void Pacman::score()
{
    if (hasEaten == true) {
        scores += 10;
    }
}

void Pacman::movePlayer()
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
    //return mapData;
}

void Pacman::enemyMove()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<Input> directions = {Input::UP, Input::DOWN, Input::LEFT, Input::RIGHT};

    for (size_t i = 0; i < enemies.size(); i++) {
        Position oldPos = enemies[i];
        mapData[oldPos.y][oldPos.x] = ' ';

        std::shuffle(directions.begin(), directions.end(), gen);
        for (auto &dir : directions) {
            int dx = oldPos.x;
            int dy = oldPos.y;

            if (dir == Input::UP) dy--;
            else if (dir == Input::DOWN) dy++;
            else if (dir == Input::LEFT) dx --;
            else if (dir == Input::RIGHT) dx ++;

            if (mapData[dy][dx] != '#' && mapData[dy][dx] != 'C') {
                enemies[i] = {dx, dy};
                break;
            }
        }
        mapData[enemies[i].y][enemies[i].x] = 'C';
    }
    //return mapData;
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
    for (auto ep : enemies) {
        if (playerHeadX == ep.x && playerHeadY == ep.y) {
            stop();
            return;
        }
    }

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

void Pacman::refresh()
{
    scores = 0;
    player.clear();
    enemies.clear();

    playerXstart = WIDTH / 2;
    playerYstart = HEIGHT - 14;

    enemyXstart = WIDTH / 2;
    enemyYstart = HEIGHT - 9;

    enemyXstart1 = (WIDTH / 2) - 2;
    enemyYstart1 = HEIGHT - 9;

    player.push_front({playerXstart, playerYstart});
    mapData[playerYstart][playerXstart] = 'O';

    enemies.push_front({enemyXstart, enemyYstart});
    enemies.push_front({enemyXstart1, enemyYstart1});

    for (auto &e : enemies) {
        mapData[e.y][e.x] = 'C';
    }

    currentDirection = Input::RIGHT;

    //return mapData;
}

void Pacman::update(Input input)
{
    if (input != Input::NONE) {
        handleInput(input);
    }
    movePlayer();
    enemyMove();
    checkCollision();
}

extern "C" IGame* create_game()
{
    return new Pacman();
}