#include "../Arcade/DLLoader.hpp"
#include "../include/IGame.hpp"
#include "../include/IGraphic.hpp"
#include "../Arcade/Core.hpp"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        std::cerr << "Usage: ./arcade ./lib/your_graphic_lib.so [./lib/your_game_lib.so]" << std::endl;
        return 84;
    }

    Core core;
    core.graphicLibs = {
        "./lib/arcade_ncurses.so",
        "./lib/arcade_sdl2.so",
        "./lib/arcade_sfml.so"
    };

    core.gameLibs = {
        "./lib/arcade_nibbler.so",
        "./lib/arcade_pacman.so"
    };

    core.currentGraphicLibIndex = 0;
    core.currentGameLibIndex = 0;

    try {
        core.displayLoader = std::make_unique<DLLoader<IDisplayModule>>(av[1]);
        core.displayModule = core.displayLoader->getInstance();

        if (ac >= 3) {
            core.gameLoader = std::make_unique<DLLoader<IGame>>(av[2]);
            core.gameModule = core.gameLoader->getInstance();
        } else {
            core.gameLoader = std::make_unique<DLLoader<IGame>>(core.gameLibs[0]);
            core.gameModule = core.gameLoader->getInstance();
        }

        core.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
