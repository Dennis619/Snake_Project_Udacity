#include "GameDifficulty.h"

std::string GameDifficulty::GetDifficultyLevel()const {
    switch (level)
    {
    case GameDifficulty::DifficultyLevel::EASY:
        return "easy"; 
        break;
    case GameDifficulty::DifficultyLevel::NORMAL:
        return "normal"; 
        break;
    case GameDifficulty::DifficultyLevel::HARD:
        return "hard"; 
        break;
    default:
        return "unkonwn"; 
        break;
    }
}; 

void GameDifficulty::SetGameDifficultyLevel(int index){
    switch (index)
    {
    case 1:
        this->level = GameDifficulty::DifficultyLevel::EASY; 
        break;
    case 2:
        this->level = GameDifficulty::DifficultyLevel::NORMAL;
        break;
    case 3:
        this->level = GameDifficulty::DifficultyLevel::HARD; 
        break;
    default:
        break;
    }
};

float GameDifficulty::GetGameSpeed()const{
    switch (level)
    {
    case EASY:
        return .1f; 
        break;
    case NORMAL:
        return .2f; 
        break;
    case HARD:
        return .3f; 
        break;
    default:
        return .05f; 
        break;
    }
};