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

    snakeXstart = HEIGHT / 2;
    snakeYstart = WIDTH - 2;

    snake.push_front({snakeXstart + 3, snakeYstart});
    snake.push_front({snakeXstart + 2, snakeYstart});
    snake.push_front({snakeXstart + 1, snakeYstart});
    snake.push_front({snakeXstart, snakeYstart});
}