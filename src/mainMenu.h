#ifndef MAIM_MENU_H
#define MAIN_MENU_H

#include "Player.h"
#include "GameDifficulty.h"
#include<string>

class MainMenu{
    public:
    MainMenu(Player &&player);

    void StartMenu();  

    private:
    GameDifficulty leveldifficulty;
    bool isGameRunning{false};
    Player player;
    const std::size_t kFramesPerSecond{60};
    const std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    const std::size_t kScreenWidth{640};
    const std::size_t kScreenHeight{640};
    const std::size_t kGridWidth{32};
    const std::size_t kGridHeight{32};
    

    void EnterPlayerName();
    void SetGameDifficulty();
    void PlayGame();
    void Quit();
};

#endif
