#include "../Arcade/Core.hpp"

void Core::LoadGraphicLib(size_t index)
{
    displayLoader = std::make_unique<DLLoader<IDisplayModule>>(graphicLibs[index]);
    displayModule = displayLoader->getInstance();
    displayModule->init();
}

void Core::LoadGameLib(size_t index)
{
    gameLoader = std::make_unique<DLLoader<IGame>>(gameLibs[index]);
    gameModule = gameLoader->getInstance();
    gameModule->init();
}

void Core::run()
{
    gameModule->init();
    displayModule->init();
    while(isRunning) {
        Input input = displayModule->getInput();
        gameModule->update(input);
        displayModule->clear();
        displayModule->display(gameModule->getMap()); 
        
        switch (input) {
            case Input::QUIT      : isRunning = false; continue;
            case Input::REFRESH   : gameModule->init(); continue;
            case Input::PREV_LIB  :
                 displayModule->stop();
                 currentGraphicLibIndex = (currentGraphicLibIndex + graphicLibs.size() - 1) % graphicLibs.size();
                 LoadGraphicLib(currentGraphicLibIndex);
                 continue;
            case Input::PREV_GAME :
                 gameModule->stop();
                 currentGameLibIndex = (currentGameLibIndex + gameLibs.size() - 1) % gameLibs.size();
                 LoadGameLib(currentGameLibIndex);
                 continue;
            case Input::NEXT_LIB  :
                 displayModule->stop();
                 currentGraphicLibIndex = (currentGraphicLibIndex + 1) % graphicLibs.size();
                 LoadGraphicLib(currentGraphicLibIndex);
                 continue;
            case Input::NEXT_GAME :
                 gameModule->stop();
                 currentGameLibIndex = (currentGameLibIndex + 1) % gameLibs.size();
                 LoadGameLib(currentGameLibIndex);
                 continue;
            default                :
                 break;
        }
    }
    gameModule->stop();
    displayModule->stop();
}