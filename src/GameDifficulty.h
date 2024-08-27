#ifndef GAMEDIFFICULTY_H
#define GAMEDIFFICULTY_H

#include <string>

class GameDifficulty{
    public:
    enum DifficultyLevel{
        EASY,
        NORMAL,
        HARD
    };

    //getter
    std::string GetDifficultyLevel()const; 
    
    //setter
    void SetGameDifficultyLevel(int);
    float GetGameSpeed()const;
    

    private:
    DifficultyLevel level{DifficultyLevel::EASY};
};

#endif