#ifndef CORE_HPP
#define CORE_HPP

#include "../Arcade/DLLoader.hpp"
#include "../include/IGame.hpp"
#include "../include/IGraphic.hpp"

class Core {
public:
    void run();
private:
    std::unique_ptr<IGame> gameModule;
    std::unique_ptr<IDisplayModule> displayModule;
    std::unique_ptr<DLLoader<IGame>> gameLoader;
    std::unique_ptr<DLLoader<IDisplayModule>> displayLoader;

    std::vector<std::string> gameLibs;
    std::vector<std::string> graphicLibs;
    size_t currentGraphicLibIndex = 0;
    size_t currentGameLibIndex = 0;
    bool isRunning = true;
};

#endif