#include "../Arcade/DLLoader.hpp"
#include "../include/IGame.hpp"
#include "../include/IGraphic.hpp"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        std::cerr << "Usage: ./arcade ./lib/your_graphic_lib.so [./lib/your_game_lib.so]" << std::endl;
        return 84;
    }

    try {
        std::string graphicPath = av[1];
        std::string gamePath = (ac == 3) ? av[2] : "";
        DLLoader<IDisplayModule> loader(graphicPath);
        loader.getInstance();
        DLLoader<IGame> loader(gamePath);
        loader.getInstance();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
