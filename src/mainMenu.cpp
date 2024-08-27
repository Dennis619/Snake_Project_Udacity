#include "mainMenu.h"
#include "GameDifficulty.cpp"
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "Player.cpp"

#include<iostream>
#include<thread>


MainMenu::MainMenu(Player &&player): player(std::move(player)), isGameRunning(true){}

void MainMenu::StartMenu(){
    int option;
    do{
        //std::cout<< "Player " << player.GetPlayerName() <<std::endl;
        std::cout << "*************** MAIN MENU ***************" << std::endl;
        if(!player.IsPlayerInfoSet()){
        std::cout << "********* 1. ENTER PLAYER NAME **********" << std::endl;
        } else{
        std::cout << "********* 1. CHANGE PLAYER NAME **********" << std::endl;
        }
        std::cout << "********* 2. PLAY GAME ******************" << std::endl;
        std::cout << "********* 3. SET GAME DIFFICULTY ********" << std::endl;
        std::cout << "********* 4. QUIT GAME ******************" << std::endl;
        std::cin >> option;

        switch (option)
        {
        case 1:
        MainMenu::EnterPlayerName();
        break;

        case 2:
        MainMenu::PlayGame();        
        break;

        case 3:
        MainMenu::SetGameDifficulty();
        break;

        case 4:
        MainMenu::Quit();
        break;
        
        default:
        std::cout << "Wrong option entered!" <<std::endl;
        break;
        }

    }while(option == 1 || option == 3 || (option == 2 && !player.IsPlayerInfoSet()));
}

void MainMenu::EnterPlayerName(){
    std::string name;
    if(!player.IsPlayerInfoSet()){
            std::cout << "Enter Your name? " << std::endl;
            std::cin >> name;
            player.SetPlayerName(name);
            std::thread sendToFileThread(&Player::SendNewPlayerToFile, &player, name, player.GetHighScore());
            sendToFileThread.join();             
        } else {
            std::cout << "Rename player!! " << std::endl;
            std::cin >> name;
            player.SetPlayerName(name);
            std::thread sendToFileThread(&Player::UpdatePlayerInfo, &player, name, -1);
            sendToFileThread.join();     
            //player.UpdatePlayerInfo(name, -1); //-1 for we aren't updating player's score
        }
};

void MainMenu::SetGameDifficulty(){
    int gameDifficultyIndex;
    std::cout << "Game Difficulty (Type: 1.Easy, 2.Normal, 3.Hard)\n";
    std::cin >> gameDifficultyIndex;
    leveldifficulty.SetGameDifficultyLevel(gameDifficultyIndex);
    std::cout <<"GameDifficulty is " << leveldifficulty.GetDifficultyLevel() << " and speed " << leveldifficulty.GetDifficultyLevel() << std::endl;
};

void MainMenu::PlayGame(){
    if(player.IsPlayerInfoSet())
    {
        Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
        Controller controller;
        Game game(kGridWidth, kGridHeight, leveldifficulty);
        game.Run(controller, renderer, kMsPerFrame);
        std::thread sendToFileThread(&Player::UpdatePlayerInfo, &player, "", game.GetScore());
        sendToFileThread.join(); 
        //player.UpdatePlayerInfo("", game.GetScore()); //update the high score only
        std::cout << "Game has terminated successfully!\n";
        std::cout << "Score: " << game.GetScore() << "\n";
        std::cout << "Size: " << game.GetSize() << "\n";
    } else{
        std::cout << "Please enter your Player Name Before Playing the game!!" << std::endl;
    }
};

void MainMenu::Quit(){
    std::cout << "Game has terminated successfully!\n";
    isGameRunning = false;
};