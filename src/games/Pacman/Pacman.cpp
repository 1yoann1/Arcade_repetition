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
    playerYstart = HEIGHT - 2;
}

void Pacman::stop()
{
}

void Pacman::score()
{
}

void Pacman::update(Input input)
{
}