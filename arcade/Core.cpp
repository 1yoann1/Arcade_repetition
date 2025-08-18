#include "../Arcade/Core.hpp"

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
            case Input::QUIT    : isRunning = false; continue;
            case Input::REFRESH : gameModule->init(); continue;
        }
    }
    gameModule->stop();
    displayModule->stop();
}