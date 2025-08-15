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
}

std::vector<std::string> Pacman::movePlayer()
{
}

void Pacman::checkCollision()
{
}

void Pacman::update(Input input)
{
}